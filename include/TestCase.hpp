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

    TestCase(std::string name, std::ostream& write);

    // Functions tester

    // about the no possibility of the implementation of these functions in the cpp file.
    // https://stackoverflow.com/questions/36039/templates-spread-across-multiple-files

    template <typename T>
    TestCase& check_equal(const T& a, const T& b)
    {
        if (a == b)
            numPassed++;
        else
        {
            numFailed++;
            *write
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << a
                    << " == "
                    << b
                    << " but returned "
                    << a
                    << " != "
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_different(const T& a, const T& b)
    {
        if (a != b)
            numPassed++;
        else
        {
            numFailed++;
            *write
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << a
                    << " != "
                    << b
                    << " but returned "
                    << a
                    << " == "
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T, typename U>
    TestCase& check_function(int (*fun) (U), const U& a, const T& b)
    {
        int temp = fun(a);
        if (b == temp)
            numPassed++;
        else
        {
            numFailed++;
            *write
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << b
                    << " but returned "
                    << temp
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_output(const T& a, std::string b)
    {

        std::ostream *temp;
        temp = &(cout << a);

       /* if (temp == b)
            numPassed++;
        else
        {
            numFailed++;
            *write
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": Function should return "
                    << b
                    << " but returned "
                    << ss.str()
                    << "!"
                    << endl;
        }
        */
        return *this;
    }
    void print();

protected:

private:

    // Class variables

    int numPassed, numFailed;
    std::string name;
    std::ostream* write;
};

#endif // TESTCASE_H
