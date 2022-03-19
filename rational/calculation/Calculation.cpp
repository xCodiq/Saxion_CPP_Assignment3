//
// Created by elmar on 10/03/2022.
//

#include "Calculation.h"

Rational Calculation::add(Rational first, Rational second) {
    int newNumerator = ((first.getNumerator() * second.getDenominator()) +
                        (second.getNumerator() * first.getDenominator()));
    int newDenominator = (first.getDenominator() * second.getDenominator());

    return {newNumerator, newDenominator};
}

Rational Calculation::subtract(Rational first, Rational second) {
    int newNumerator = ((first.getNumerator() * second.getDenominator()) -
                        (second.getNumerator() * first.getDenominator()));
    int newDenominator = (first.getDenominator() * second.getDenominator());

    return {newNumerator, newDenominator};
}

Rational Calculation::multiply(Rational first, Rational second) {
    return {first.getNumerator() * second.getNumerator(), first.getDenominator() * second.getDenominator()};
}

Rational Calculation::divide(Rational first, Rational second) {
    return multiply(first, {second.getDenominator(), second.getNumerator()});
}

Rational Calculation::pow(Rational rational, int number) {
    int newNumerator = rational.getNumerator(), newDenominator = rational.getDenominator();

    for (int i = 1; i < number; i++) {
        newNumerator *= rational.getNumerator();
        newDenominator *= rational.getDenominator();
    }

    return {newNumerator, newDenominator};
}

Rational Calculation::calculate(const string &expression) {
    auto firstSpacePosition = expression.find(' ');

    string firstStr = expression.substr(0, firstSpacePosition);
    const char operatorStr = expression.substr(firstSpacePosition + 1, firstSpacePosition - 2).c_str()[0];
    string secondStr = expression.substr(firstSpacePosition + 3);

    Rational first = Rational(firstStr);
    Rational second = Rational(secondStr);

    if (!first.validate() || !second.validate()) return {0, 0};

    switch (operatorStr) {
        case '+':
            return this->add(first, second);
        case '-':
            return this->subtract(first, second);
        case '*':
            return this->multiply(first, second);
        case '/':
            return this->divide(first, second);
        case '^':
            return this->pow(first, std::stoi(secondStr));
    }
}
