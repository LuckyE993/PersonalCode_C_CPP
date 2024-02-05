#include <iostream>
#include <fstream>


using namespace std;

/**
 * @brief 结构体概述
 *      coefficient 系数
 *      exponent    指数
 *      next        下一项的指针
 */
struct Term {
    int coefficient;  // 系数
    int exponent;     // 指数
    Term* next;       // 下一个项的指针
};

/**
 * @brief 在链表中插入新的项
 * @param head  链表结构体
 * @param coeff 系数
 * @param expo  指数
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
 * @brief 释放链表内存
 *
 * @param head 链表结构体
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
 * @brief 打印多项式
 *
 * @param head 多项式结构体
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
 * @brief 获取多项式最高指数
 *
 * @param head 多项式结构体
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
 * @brief 简化多项式，消除系数为零的项
 *
 * @param poly 多项式结构体
 *
 * @return Term 多项式结构体
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
 * @brief  多项式相加
 *
 * @param poly1 第一个多项式
 * @param poly2 第二个多项式
 *
 * @return Term 多项式结构体
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
 * @brief 多项式相减
 *
 * @param poly1 第一个多项式
 * @param poly2 第二个多项式
 *
 * @return Term 多项式结构体
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
 * @brief 保存多项式至文件
 *
 * @param head 多项式
 * @param filename 文件名
 *
 * @return Term 多项式结构体
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
        cout << "------------- 菜单选项 ---------------" << endl;
        cout << "1. 输入多项式1" << endl;
        cout << "2. 输入多项式2" << endl;
        cout << "3. 执行计算" << endl;
        cout << "4. 退出" << endl;
        cout << "-------------------------------------" << endl;
        cout << "请选择一个选项：";
        cin >> choice;

        switch (choice) {
            case 1: {
                int poly1_termNums;
                cout << "请输入多项式1的项数：";
                cin >> poly1_termNums;

                cout << "请依次输入多项式1的系数和指数（空格隔开）：" << endl;
                while (poly1_termNums--) {
                    int coeff, expo;
                    cin >> coeff >> expo;
                    insertTerm(poly1, coeff, expo);
                }
                savePolynomialsToFile(poly1, "poly1.txt");
                cout << "多项式1已保存至poly1.txt" << endl;
                break;
            }
            case 2: {
                int poly2_termNums;
                cout << "请输入多项式2的项数：";
                cin >> poly2_termNums;

                cout << "请依次输入多项式2的系数和指数（空格隔开）：" << endl;
                while (poly2_termNums--) {
                    int coeff, expo;
                    cin >> coeff >> expo;
                    insertTerm(poly2, coeff, expo);
                }
                savePolynomialsToFile(poly2, "poly2.txt");
                cout << "多项式2已保存至poly2.txt" << endl;
                break;
            }
            case 3: {
                if (poly1 == nullptr || poly2 == nullptr) {
                    cout << "请先输入多项式1和多项式2！" << endl;
                } else {
                    cout << "多项式1: ";
                    printPolynomial(poly1);

                    cout << "多项式2: ";
                    printPolynomial(poly2);

                    Term* sum = addPolynomials(poly1, poly2);
                    cout << "相加结果: ";
                    printPolynomial(sum);

                    Term* diff = subtractPolynomials(poly1, poly2);
                    cout << "相减结果: ";
                    printPolynomial(diff);

                    destroyPolynomial(sum);
                    destroyPolynomial(diff);
                }
                break;
            }
            case 4: {
                destroyPolynomial(poly1);
                destroyPolynomial(poly2);
                cout << "程序已终止。" << endl;
                return 0;
            }
            default:
                cout << "无效的选项！请重新选择。" << endl;
        }
        cout << endl;
    }
}
