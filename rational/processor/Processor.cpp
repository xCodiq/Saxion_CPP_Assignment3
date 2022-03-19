//
// Created by elmar on 10/03/2022.
//

#include "Processor.h"

bool Processor::process(const string &fileName) {

    ifstream inputStream{fileName};
    if (TextfileUtil::validateInputStream(&inputStream, "File does not exist!"))
        cout << endl << "Opening \"" << fileName << "\"" << endl;
    else return false;

    Calculation calculation;
    string expressionLine{};

    string outputFileName = TextfileUtil::convertFileNameToOutputFileName(fileName);
    ofstream outputStream{outputFileName};

    while (getline(inputStream, expressionLine)) {
        Rational rational = calculation.calculate(expressionLine);
        string result = expressionLine + " = " + rational.toString() + "\n";

        cout << result;
        outputStream << result;
    }

    cout << endl << "Calculations complete! Saved to \"" << outputFileName << "\"" << endl;
    return true;
}
