#ifndef TESTCASE_H
#define TESTCASE_H

/** Include */

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

/**
 * \brief TestCase.hpp.
 * \author Created by SAMUEL and JOHANN on 04/06/2018.
 * Copyright © 2018 SAMUEL and JOHANN. All rights reserved.
 */
class TestCase
{
public:

    // Constructor

    TestCase(std::string name, std::ostream& error);

    // Functions tester

    template <typename T>
    TestCase& check_equal(const T& a, const T& b)
    {
        try
        {
            a == b;
            numPassed++;
        }
        catch(...)
        {
            numFailed++;
            std::cerr
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << a
                    << "=="
                    << b
                    << " but returned "
                    << a
                    << "!="
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_different(const T& a, const T& b)
    {
        try
        {
            a != b;
            numPassed++;
        }
        catch(...)
        {
            numFailed++;
            *error
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << a
                    << "!="
                    << b
                    << " but returned "
                    << a
                    << "=="
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_function(const T& a, const T& b)
    {
        try
        {
            a != b;
            numPassed++;
        }
        catch(...)
        {
            numFailed++;
            *error
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << a
                    << "!="
                    << b
                    << " but returned "
                    << a
                    << "=="
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    void print();

protected:

private:

    // Class variables

    int numPassed, numFailed;
    std::string name;
    std::ostream* error;
};

#endif // TESTCASE_H
