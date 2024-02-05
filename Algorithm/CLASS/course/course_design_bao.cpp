#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Term {
    int coefficient;
    int exponent;
};

struct Polynomial {
    Term* terms; // ��̬�������ڴ洢����ʽ����
    int numTerms; // �������
};

// �ȽϺ���������ָ���Ľ�������
bool compareTerms(const Term& a, const Term& b) {
    return a.exponent > b.exponent;
}

// �Ӽ����������ʽ
void readPolynomial(Polynomial& poly) {
    cout << "���������ʽ������: ";
    cin >> poly.numTerms;

    poly.terms = new Term[poly.numTerms];

    for (int i = 0; i < poly.numTerms; i++) {
        cout << "�������" << i + 1 << "���ϵ��: ";
        cin >> poly.terms[i].coefficient;
        cout << "�������" << i + 1 << "���ָ��: ";
        cin >> poly.terms[i].exponent;
    }

    // ����ָ���Զ���ʽ���������Ա��������
    sort(poly.terms, poly.terms + poly.numTerms, compareTerms);
}

// �������ʽ���ļ�
void savePolynomialToFile(const Polynomial& poly, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < poly.numTerms; i++) {
            file << poly.terms[i].coefficient << "x^" << poly.terms[i].exponent << " ";
        }

        file.close();
        cout << "����ʽ�ѱ��浽�ļ�: " << filename << endl;
    } else {
        cout << "�޷����ļ�: " << filename << endl;
    }
}

// �������ʽ
void printPolynomial(const Polynomial& poly) {
    for (int i = 0; i < poly.numTerms; i++) {
        cout << poly.terms[i].coefficient << "x^" << poly.terms[i].exponent << " ";
    }

    cout << endl;
}

// ����ʽ���
Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    int maxSize = max(poly1.numTerms, poly2.numTerms);
    result.terms = new Term[maxSize];

    int i = 0, j = 0, k = 0;
    while (i < poly1.numTerms && j < poly2.numTerms)
    {
        if (poly1.terms[i].exponent > poly2.terms[j].exponent)
        {
            result.terms[k] = poly1.terms[i];
            i++;
        } else if (poly1.terms[i].exponent < poly2.terms[j].exponent) {
            result.terms[k] = poly2.terms[j];
            j++;
        } else {
            result.terms[k].coefficient = poly1.terms[i].coefficient + poly2.terms[j].coefficient;
            result.terms[k].exponent = poly1.terms[i].exponent;
            i++;
            j++;
        }
        k++;
    }

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

    cout << "����ʽ��ӽ��: ";
    printPolynomial(result);

    return result;
}

// ����ʽ���
Polynomial subtractPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    int maxSize = max(poly1.numTerms, poly2.numTerms);
    result.terms = new Term[maxSize];

    int i = 0, j = 0, k = 0;
    while (i < poly1.numTerms && j < poly2.numTerms) {
        if (poly1.terms[i].exponent > poly2.terms[j].exponent) {
            result.terms[k] = poly1.terms[i];
            i++;
        } else if (poly1.terms[i].exponent < poly2.terms[j].exponent) {
            result.terms[k] = poly2.terms[j];
            j++;
        } else {
            result.terms[k].coefficient = poly1.terms[i].coefficient - poly2.terms[j].coefficient;
            result.terms[k].exponent = poly1.terms[i].exponent;
            i++;
            j++;
        }
        k++;
    }

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

    cout << "����ʽ������: ";
    printPolynomial(result);

    return result;
}

int main() {
    Polynomial poly1;
    Polynomial poly2;
    Polynomial sum;
    Polynomial diff;

    cout << "�����һ������ʽ��" << endl;
    readPolynomial(poly1);

    cout << "����ڶ�������ʽ��" << endl;
    readPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);
    diff = subtractPolynomials(poly1, poly2);

    cout << "��һ������ʽ: ";
    printPolynomial(poly1);

    cout << "�ڶ�������ʽ: ";
    printPolynomial(poly2);

    savePolynomialToFile(sum, "sum.txt");
    savePolynomialToFile(diff, "diff.txt");

    delete[] poly1.terms;
    delete[] poly2.terms;
    delete[] sum.terms;
    delete[] diff.terms;

    return 0;
}
