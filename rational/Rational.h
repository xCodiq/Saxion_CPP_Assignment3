//
// Created by elmar on 07/03/2022.
//
#include <iostream>

#ifndef CPPASSIGNMENT3_RATIONAL_H
#define CPPASSIGNMENT3_RATIONAL_H

using std::cout, std::cin, std::endl, std::getline, std::ifstream, std::string;

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational(int numerator, int denominator);

    explicit Rational(int numerator);

    explicit Rational(const string &rationalStr);

    Rational();

    [[nodiscard]] int getNumerator() const;

    [[nodiscard]] int getDenominator() const;

    void setNumerator(int newNumerator);

    void setDenominator(int newDenominator);

    [[nodiscard]] string toString() const;

    [[nodiscard]] double toDouble() const;

    [[nodiscard]] bool isPositive() const;

    [[nodiscard]] bool isNegative() const;

    [[nodiscard]] bool isInfinite() const;

    [[nodiscard]] bool isNaN() const;

    int greatestCommonDivisor(int num, int den);

    int greatestCommonDivisor();

    void simplify();

    bool validate();
};


#endif //CPPASSIGNMENT3_RATIONAL_H
