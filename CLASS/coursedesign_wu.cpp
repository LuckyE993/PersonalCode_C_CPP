#include "coursedesign_wu.h"

using namespace std;

/*
 * @brief:用于指数升序的比较函数
 * @param: const Term&
 * @ret: bool
 * */
bool compareTerms(const Term& a, const Term& b) {
    return a.exponent < b.exponent;
}

// 从键盘输入多项式
//dif用于区分第几个输入的多项式
/*
 * @brief:读取多项式
 * @param:poly  多项式结构体
 *        dif   第几个多项式 第一个：true，第二个:false
 * @ret:void
 * */
void readPolynomial(Polynomial& poly,bool dif) {
    cout << "请输入多项式的项数: ";
    cin >> poly.numTerms;

    poly.terms = new Term[poly.numTerms]; //分配 poly.numTerms 大小的空间

    for (int i = 0; i < poly.numTerms; i++) {
        cout << "请输入第" << i + 1 << "项的系数: ";
        cin >> poly.terms[i].coefficient;
        cout << "请输入第" << i + 1 << "项的指数: ";
        cin >> poly.terms[i].exponent;
        poly.terms[i].differ = dif;
    }


}

/*
 * @brief:保存多项式到文件
 * @param:poly1,poly2  键盘输入的两个多项式结构体
 *        filename   保存到的文件名
 *        option    true 加法
 *                  false 减法
 * @ret:void
 * */
void savePolynomialToFile(const Polynomial& poly1, const Polynomial& poly2, const string& filename,bool option)
{
    ofstream file(filename);//如存在"filename"文件则打开，否则创建一个"filename"的文件
    if (file.is_open())
    {
        int answer;

        answer = CalculatePolynomial(CalculatePolynomialSum(poly1),CalculatePolynomialSum(poly2)
                                     ,option);//计算两个多项式的和或差

        Polynomial poly{};

        poly = addPolynomials(poly1,poly2);//合并两个多项式

        if(option)//加法
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
        else//减法
        {
            for (int i = 0; i < poly.numTerms; i++)
            {
                if(!poly.terms[i].differ)//该项为第二多项式
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
        cout << "多项式已保存到文件: " << filename << endl;
    } else {
        cout << "无法打开文件: " << filename << endl;
    }
}

/*
 * @brief:多项式拼接
 * @param:Polynomial poly1,Polynomial poly2  键盘输入的两个多项式结构体
 *
 * @ret:Polynomial
 * */

Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result{};

    int maxSize = poly1.numTerms + poly2.numTerms;
    result.terms = new Term[maxSize];//创建一个maxSize大小的空间用于存放不多于maxSize组数据

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
    }//简简单单的排序

    // 处理剩余的项
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
    sort(result.terms, result.terms + result.numTerms, compareTerms);//对拼接后的多项式进行排序。

    return result;
}

/*
 * @brief:打印多项式
 * @param:Polynomial poly1,Polynomial poly2  键盘输入的两个多项式结构体
 *        option    true 加法
 *                  false 减法
 * @ret:void
 * */

void printPolynomial(const Polynomial& poly1, const Polynomial& poly2,bool option)
{
    int answer;

    answer = CalculatePolynomial(CalculatePolynomialSum(poly1),CalculatePolynomialSum(poly2)
                                 ,option);

    Polynomial poly{};

    poly = addPolynomials(poly1,poly2);

    if(option)//加法
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
    else//减法
    {
        for (int i = 0; i < poly.numTerms; i++)
        {
            if(!poly.terms[i].differ)//该项为第二多项式
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
 * @brief:计算多项式的和
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
 * @brief:计算两个多项式的和或差
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

    cout << "输入第一个多项式：" << endl;
    readPolynomial(poly1, true);
    cout<<endl;

    cout << "输入第二个多项式：" << endl;
    readPolynomial(poly2, false);
    cout<<endl;

    printPolynomial(poly1,poly2, true);
    printPolynomial(poly1,poly2, false);
    cout<<endl;

    savePolynomialToFile(poly1,poly2,"sum.txt",true);
    savePolynomialToFile(poly1,poly2,"diff.txt",false);
    cout<<endl;

    //内存管理
    delete[] poly1.terms;
    delete[] poly2.terms;
    delete[] sum.terms;
    delete[] diff.terms;

    return 0;
}
