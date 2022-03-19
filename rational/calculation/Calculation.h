//
// Created by elmar on 10/03/2022.
//

#ifndef CPPASSIGNMENT3_CALCULATION_H
#define CPPASSIGNMENT3_CALCULATION_H

#include "../Rational.h"

class Calculation {
public:
    Rational add(Rational first, Rational second);

    Rational subtract(Rational first, Rational second);

    Rational multiply(Rational first, Rational second);

    Rational divide(Rational first, Rational second);

    Rational pow(Rational rational, int number);

    Rational calculate(const string &expression);
};


#endif //CPPASSIGNMENT3_CALCULATION_H
