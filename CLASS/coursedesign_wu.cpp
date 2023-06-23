#include "coursedesign_wu.h"

using namespace std;

/*
 * @brief:����ָ������ıȽϺ���
 * @param: const Term&
 * @ret: bool
 * */
bool compareTerms(const Term& a, const Term& b) {
    return a.exponent < b.exponent;
}

// �Ӽ����������ʽ
//dif�������ֵڼ�������Ķ���ʽ
/*
 * @brief:��ȡ����ʽ
 * @param:poly  ����ʽ�ṹ��
 *        dif   �ڼ�������ʽ ��һ����true���ڶ���:false
 * @ret:void
 * */
void readPolynomial(Polynomial& poly,bool dif) {
    cout << "���������ʽ������: ";
    cin >> poly.numTerms;

    poly.terms = new Term[poly.numTerms]; //���� poly.numTerms ��С�Ŀռ�

    for (int i = 0; i < poly.numTerms; i++) {
        cout << "�������" << i + 1 << "���ϵ��: ";
        cin >> poly.terms[i].coefficient;
        cout << "�������" << i + 1 << "���ָ��: ";
        cin >> poly.terms[i].exponent;
        poly.terms[i].differ = dif;
    }


}

/*
 * @brief:�������ʽ���ļ�
 * @param:poly1,poly2  �����������������ʽ�ṹ��
 *        filename   ���浽���ļ���
 *        option    true �ӷ�
 *                  false ����
 * @ret:void
 * */
void savePolynomialToFile(const Polynomial& poly1, const Polynomial& poly2, const string& filename,bool option)
{
    ofstream file(filename);//�����"filename"�ļ���򿪣����򴴽�һ��"filename"���ļ�
    if (file.is_open())
    {
        int answer;

        answer = CalculatePolynomial(CalculatePolynomialSum(poly1),CalculatePolynomialSum(poly2)
                                     ,option);//������������ʽ�ĺͻ��

        Polynomial poly{};

        poly = addPolynomials(poly1,poly2);//�ϲ���������ʽ

        if(option)//�ӷ�
        {
            for (int i = 0; i < poly.numTerms; i++)
            {
                file << poly.terms[i].coefficient << "^" << poly.terms[i].exponent ;
                if(i<poly.numTerms-1)
                {
                    file<<"+";
                }
            }
            file<<" = "<<answer;
        }
        else//����
        {
            for (int i = 0; i < poly.numTerms; i++)
            {
                if(!poly.terms[i].differ)//����Ϊ�ڶ�����ʽ
                {
                    file<<"-";
                }
                if(poly.terms[i].differ&&i)
                {
                    file<<"+";
                }
                file << poly.terms[i].coefficient << "^" << poly.terms[i].exponent ;
            }
            file<<" = "<<answer;
        }
        file.close();
        cout << "����ʽ�ѱ��浽�ļ�: " << filename << endl;
    } else {
        cout << "�޷����ļ�: " << filename << endl;
    }
}

/*
 * @brief:����ʽƴ��
 * @param:Polynomial poly1,Polynomial poly2  �����������������ʽ�ṹ��
 *
 * @ret:Polynomial
 * */

Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result{};

    int maxSize = poly1.numTerms + poly2.numTerms;
    result.terms = new Term[maxSize];//����һ��maxSize��С�Ŀռ����ڴ�Ų�����maxSize������

    int i = 0, j = 0, k = 0;
    while (i < poly1.numTerms && j < poly2.numTerms) {
        if (poly1.terms[i].exponent < poly2.terms[j].exponent) {
            result.terms[k] = poly1.terms[i];
            i++;
        } else if (poly1.terms[i].exponent > poly2.terms[j].exponent) {
            result.terms[k] = poly2.terms[j];
            j++;
        } else {
            if (poly1.terms[i].coefficient < poly2.terms[j].coefficient)
            {
                result.terms[k] = poly1.terms[i];
                result.terms[k].exponent = poly1.terms[i].exponent;
                k++;
                result.terms[k] = poly2.terms[j];
                result.terms[k].exponent = poly1.terms[i].exponent;
            } else
            {
                result.terms[k] = poly2.terms[j];
                result.terms[k].exponent = poly1.terms[i].exponent;
                k++;
                result.terms[k] = poly1.terms[i];
                result.terms[k].exponent = poly1.terms[i].exponent;
            }
            i++;
            j++;
        }
        k++;
    }//��򵥵�������

    // ����ʣ�����
    while (i < poly1.numTerms) {
        result.terms[k] = poly1.terms[i];
        i++;
        k++;
    }

    while (j < poly2.numTerms) {
        result.terms[k] = poly2.terms[j];
        j++;
        k++;
    }

    result.numTerms = k;
    sort(result.terms, result.terms + result.numTerms, compareTerms);//��ƴ�Ӻ�Ķ���ʽ��������

    return result;
}

/*
 * @brief:��ӡ����ʽ
 * @param:Polynomial poly1,Polynomial poly2  �����������������ʽ�ṹ��
 *        option    true �ӷ�
 *                  false ����
 * @ret:void
 * */

void printPolynomial(const Polynomial& poly1, const Polynomial& poly2,bool option)
{
    int answer;

    answer = CalculatePolynomial(CalculatePolynomialSum(poly1),CalculatePolynomialSum(poly2)
                                 ,option);

    Polynomial poly{};

    poly = addPolynomials(poly1,poly2);

    if(option)//�ӷ�
    {
        for (int i = 0; i < poly.numTerms; i++)
        {
            cout << poly.terms[i].coefficient << "^" << poly.terms[i].exponent ;
            if(i<poly.numTerms-1)
            {
                cout<<"+";
            }
        }

    }
    else//����
    {
        for (int i = 0; i < poly.numTerms; i++)
        {
            if(!poly.terms[i].differ)//����Ϊ�ڶ�����ʽ
            {
                cout<<"-";
            }
            if(poly.terms[i].differ&&i)
            {
                cout<<"+";
            }
            cout << poly.terms[i].coefficient << "^" << poly.terms[i].exponent ;
        }

    }

    cout <<" = "<<answer<< endl;
}

/*
 * @brief:�������ʽ�ĺ�
 * @param:Polynomial poly
 * @ret:int
 * */

int CalculatePolynomialSum(const Polynomial& poly)
{

    int sum=0,num=0;
    while(num<poly.numTerms) {
        sum += (int)pow(poly.terms[num].coefficient,poly.terms[num].exponent);
        num++;
    }
    return sum;
}

/*
 * @brief:������������ʽ�ĺͻ��
 * @param:int value1,int value2,bool option
 * @ret:int
 * */
int CalculatePolynomial(int value1,int value2,bool option)
{
    if(option)
    {
        return value1+value2;
    }
    else
    {
        return value1-value2;
    }
}

int main() {
    Polynomial poly1{};
    Polynomial poly2{};
    Polynomial sum{};
    Polynomial diff{};

    cout << "�����һ������ʽ��" << endl;
    readPolynomial(poly1, true);
    cout<<endl;

    cout << "����ڶ�������ʽ��" << endl;
    readPolynomial(poly2, false);
    cout<<endl;

    printPolynomial(poly1,poly2, true);
    printPolynomial(poly1,poly2, false);
    cout<<endl;

    savePolynomialToFile(poly1,poly2,"sum.txt",true);
    savePolynomialToFile(poly1,poly2,"diff.txt",false);
    cout<<endl;

    //�ڴ����
    delete[] poly1.terms;
    delete[] poly2.terms;
    delete[] sum.terms;
    delete[] diff.terms;

    return 0;
}
