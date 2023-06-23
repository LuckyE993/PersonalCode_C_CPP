//
// Created by izumi on 2023-06-23.
//

#ifndef CPP_COURSEDESIGN_WU_H
#define CPP_COURSEDESIGN_WU_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>

struct Term {
    int coefficient;//系数
    int exponent;//指数
    bool differ;
};

struct Polynomial {
    Term* terms; // 动态数组用于存储多项式的项
    int numTerms; // 项的数量
};

bool compareTerms(const Term& a, const Term& b);
void readPolynomial(Polynomial& poly,bool dif);
void savePolynomialToFile(const Polynomial& poly1, const Polynomial& poly2, const std::string& filename,bool option);
Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2);
void printPolynomial(const Polynomial& poly1, const Polynomial& poly2,bool option);
int CalculatePolynomialSum(const Polynomial& poly);
int CalculatePolynomial(int value1,int value2,bool option);


#endif //CPP_COURSEDESIGN_WU_H
