#include <iostream>
#include "rational/Rational.h"
#include "rational/calculation/Calculation.h"
#include "rational/processor/Processor.h"

int main() {
    cout << "Welcome! Choose an option:" << endl;
    cout << "1: Create your own expressions" << endl;
    cout << "2: Open a file with expressions" << endl;
    cout << endl << "Enter option:";

    string option{};
    if (getline(cin, option) && option == "1") {

        Calculation calculation;
        while (true) {
            cout << endl << "Enter an expression:";
            string expression{};
            if (getline(cin, expression) && expression != "end") {
                cout << "Result: " << expression + " = " << calculation.calculate(expression).toString() << endl;
                continue;
            }

            break;
        }
    } else if (option == "2") {

        Processor processor;
        processor.process(TextfileUtil::promptFileName());

    }

    cout << endl << "Goodbye!" << endl;
}
