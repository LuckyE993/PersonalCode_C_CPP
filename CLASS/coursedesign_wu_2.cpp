#include <iostream>
#include <fstream>


using namespace std;

/**
 * @brief �ṹ�����
 *      coefficient ϵ��
 *      exponent    ָ��
 *      next        ��һ���ָ��
 */
struct Term {
    int coefficient;  // ϵ��
    int exponent;     // ָ��
    Term* next;       // ��һ�����ָ��
};

/**
 * @brief �������в����µ���
 * @param head  ����ṹ��
 * @param coeff ϵ��
 * @param expo  ָ��
 *
 * @return none
 *
 */
void insertTerm(Term*& head, int coeff, int expo) {
    Term* newTerm = new Term;
    newTerm->coefficient = coeff;
    newTerm->exponent = expo;
    newTerm->next = nullptr;

    if (head == nullptr) {
        head = newTerm;
    } else {
        Term* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

/**
 * @brief �ͷ������ڴ�
 *
 * @param head ����ṹ��
 *
 * @return none
 */
void destroyPolynomial(Term* head) {
    while (head != nullptr) {
        Term* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief ��ӡ����ʽ
 *
 * @param head ����ʽ�ṹ��
 *
 * @return none
 */
void printPolynomial(Term* head) {
    Term* current = head;
    bool isFirstTerm = true;

    while (current != nullptr) {
        int coeff = current->coefficient;
        int expo = current->exponent;

        if (isFirstTerm) {
            if (coeff < 0)
                cout << "-";
            isFirstTerm = false;
        } else {
            if (coeff < 0)
                cout << " - ";
            else
                cout << " + ";
        }

        coeff = abs(coeff);

        if (coeff != 1 || expo == 0)
            cout << coeff;

        if (expo > 0) {
            cout << "x";
            if (expo > 1)
                cout << "^" << expo;
        }

        current = current->next;
    }

    cout << endl;
}

/**
 * @brief ��ȡ����ʽ���ָ��
 *
 * @param head ����ʽ�ṹ��
 *
 * @return none
 */
int getHighestExponent(Term* head) {
    int highestExpo = 0;
    Term* current = head;
    while (current != nullptr) {
        if (current->exponent > highestExpo)
            highestExpo = current->exponent;
        current = current->next;
    }
    return highestExpo;
}

/**
 * @brief �򻯶���ʽ������ϵ��Ϊ�����
 *
 * @param poly ����ʽ�ṹ��
 *
 * @return Term ����ʽ�ṹ��
 * */
Term* simplifyPolynomial(Term* poly) {
    Term* simplifiedPoly = nullptr;
    Term* current = poly;

    while (current != nullptr) {
        if (current->coefficient != 0)
            insertTerm(simplifiedPoly, current->coefficient, current->exponent);
        current = current->next;
    }

    return simplifiedPoly;
}

/**
 * @brief  ����ʽ���
 *
 * @param poly1 ��һ������ʽ
 * @param poly2 �ڶ�������ʽ
 *
 * @return Term ����ʽ�ṹ��
 *
 */
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = nullptr;
    Term* current = nullptr;

    int highestExponent = max(getHighestExponent(poly1), getHighestExponent(poly2));

    for (int expo = highestExponent; expo >= 0; expo--) {
        int coeff = 0;

        Term* term1 = poly1;
        while (term1 != nullptr) {
            if (term1->exponent == expo)
                coeff += term1->coefficient;
            term1 = term1->next;
        }

        Term* term2 = poly2;
        while (term2 != nullptr) {
            if (term2->exponent == expo)
                coeff += term2->coefficient;
            term2 = term2->next;
        }

        if (coeff != 0)
            insertTerm(result, coeff, expo);

        if (current == nullptr)
            current = result;
    }

    return simplifyPolynomial(result);
}

/**
 * @brief ����ʽ���
 *
 * @param poly1 ��һ������ʽ
 * @param poly2 �ڶ�������ʽ
 *
 * @return Term ����ʽ�ṹ��
 *
 */
Term* subtractPolynomials(Term* poly1, Term* poly2) {
    Term* result = nullptr;
    Term* current = nullptr;

    int highestExponent = max(getHighestExponent(poly1), getHighestExponent(poly2));

    for (int expo = highestExponent; expo >= 0; expo--) {
        int coeff = 0;

        Term* term1 = poly1;
        while (term1 != nullptr) {
            if (term1->exponent == expo)
                coeff += term1->coefficient;
            term1 = term1->next;
        }

        Term* term2 = poly2;
        while (term2 != nullptr) {
            if (term2->exponent == expo)
                coeff -= term2->coefficient;
            term2 = term2->next;
        }

        if (coeff != 0)
            insertTerm(result, coeff, expo);

        if (current == nullptr)
            current = result;
    }

    return simplifyPolynomial(result);
}

/**
 * @brief �������ʽ���ļ�
 *
 * @param head ����ʽ
 * @param filename �ļ���
 *
 * @return Term ����ʽ�ṹ��
 *
 */
void savePolynomialsToFile(Term* head,const string& filename)
{
    Term* current = head;
    bool isFirstTerm = true;
    ofstream file(filename);
    while (current != nullptr) {
        int coeff = current->coefficient;
        int expo = current->exponent;

        if (isFirstTerm) {
            if (coeff < 0)
                file<< "-";
            isFirstTerm = false;
        } else {
            if (coeff < 0)
                file << " - ";
            else
                file << " + ";
        }

        coeff = abs(coeff);

        if (coeff != 1 || expo == 0)
            file << coeff;

        if (expo > 0) {
            file << "x";
            if (expo > 1)
                file << "^" << expo;
        }

        current = current->next;
    }

    file << endl;
}

int main() {
    Term* poly1 = nullptr;
    Term* poly2 = nullptr;

    int choice;
    while (true) {
        cout << "------------- �˵�ѡ�� ---------------" << endl;
        cout << "1. �������ʽ1" << endl;
        cout << "2. �������ʽ2" << endl;
        cout << "3. ִ�м���" << endl;
        cout << "4. �˳�" << endl;
        cout << "-------------------------------------" << endl;
        cout << "��ѡ��һ��ѡ�";
        cin >> choice;

        switch (choice) {
            case 1: {
                int poly1_termNums;
                cout << "���������ʽ1��������";
                cin >> poly1_termNums;

                cout << "�������������ʽ1��ϵ����ָ�����ո��������" << endl;
                while (poly1_termNums--) {
                    int coeff, expo;
                    cin >> coeff >> expo;
                    insertTerm(poly1, coeff, expo);
                }
                savePolynomialsToFile(poly1, "poly1.txt");
                cout << "����ʽ1�ѱ�����poly1.txt" << endl;
                break;
            }
            case 2: {
                int poly2_termNums;
                cout << "���������ʽ2��������";
                cin >> poly2_termNums;

                cout << "�������������ʽ2��ϵ����ָ�����ո��������" << endl;
                while (poly2_termNums--) {
                    int coeff, expo;
                    cin >> coeff >> expo;
                    insertTerm(poly2, coeff, expo);
                }
                savePolynomialsToFile(poly2, "poly2.txt");
                cout << "����ʽ2�ѱ�����poly2.txt" << endl;
                break;
            }
            case 3: {
                if (poly1 == nullptr || poly2 == nullptr) {
                    cout << "�����������ʽ1�Ͷ���ʽ2��" << endl;
                } else {
                    cout << "����ʽ1: ";
                    printPolynomial(poly1);

                    cout << "����ʽ2: ";
                    printPolynomial(poly2);

                    Term* sum = addPolynomials(poly1, poly2);
                    cout << "��ӽ��: ";
                    printPolynomial(sum);

                    Term* diff = subtractPolynomials(poly1, poly2);
                    cout << "������: ";
                    printPolynomial(diff);

                    destroyPolynomial(sum);
                    destroyPolynomial(diff);
                }
                break;
            }
            case 4: {
                destroyPolynomial(poly1);
                destroyPolynomial(poly2);
                cout << "��������ֹ��" << endl;
                return 0;
            }
            default:
                cout << "��Ч��ѡ�������ѡ��" << endl;
        }
        cout << endl;
    }
}
