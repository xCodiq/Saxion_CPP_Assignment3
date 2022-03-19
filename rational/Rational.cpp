//
// Created by elmar on 07/03/2022.
//

#include "Rational.h"

Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    this->simplify();
}

Rational::Rational(int numerator) : Rational(numerator, 1) {
}

Rational::Rational(const string &rationalStr) {
    std::basic_string<char>::size_type position = rationalStr.find('/');

    this->numerator = std::stoi(rationalStr.substr(0, position));
    this->denominator = std::stoi(rationalStr.substr(position + 1));

    this->simplify();
}

// Default constructor
Rational::Rational() : Rational(1, 1) {
}

int Rational::getNumerator() const {
    return this->numerator;
}

int Rational::getDenominator() const {
    return this->denominator;
}

void Rational::setNumerator(int newNumerator) {
    this->numerator = newNumerator;
    this->simplify();
}

void Rational::setDenominator(int newDenominator) {
    this->denominator = newDenominator;
    this->simplify();
}

string Rational::toString() const {
    return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}

double Rational::toDouble() const {
    return (double) this->numerator / (double) this->denominator;
}

bool Rational::isPositive() const {
    return this->toDouble() >= 0.0;
}

bool Rational::isNegative() const {
    return this->toDouble() < 0.0;
}

bool Rational::isInfinite() const {
    return this->numerator != 0 && this->denominator == 0;
}

bool Rational::isNaN() const {
    return this->numerator == 0 && this->denominator == 0;
}

int Rational::greatestCommonDivisor(int num, int den) {
    return den == 0 ? num : greatestCommonDivisor(den, num % den);
}

int Rational::greatestCommonDivisor() {
    return this->greatestCommonDivisor(this->numerator, this->denominator);
}

void Rational::simplify() {
    int simplification = this->greatestCommonDivisor();
    int absolute = this->denominator < 0 ? -1 : 1;

    this->numerator = this->numerator / simplification * absolute;
    this->denominator = this->denominator / simplification * absolute;
}

bool Rational::validate() {
    return this->isNaN() || this->isInfinite();
}
