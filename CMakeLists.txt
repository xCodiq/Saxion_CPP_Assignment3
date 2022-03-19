cmake_minimum_required(VERSION 3.20)
project(CPPAssignment3)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPPAssignment3 main.cpp util/textfile/TextfileUtil.cpp main.cpp util/textfile/TextfileUtil.h util/validation/Validator.cpp util/validation/Validator.h rational/Rational.cpp rational/Rational.h rational/calculation/Calculation.cpp rational/calculation/Calculation.h rational/processor/Processor.cpp rational/processor/Processor.h)
