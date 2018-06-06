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
    TestCase& check_equal(const T &a, const T &b)
    {
        if((T) a == (T) b)
            numPassed++;
        else
        {
            numFailed++;
            *write
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": "
                    << a
                    << " should equal "
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_different(const T &a, const T &b)
    {
        if((T)a != (T)b)
            numPassed++;
        else
        {
            numFailed++;
            *write
                     << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": "
                    << a
                    << " should not equal "
                    << b
                    << "!"
                    << endl;
        }
        return *this;
    }

    template <typename T, typename U, typename V>
    TestCase& check_function(T fun, const U& a, const V& b)
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

    /**Test MyStruct operators: Failure in test #3: string value should be MyStruct(5) but is MyStrct(5)*/
    /** There is no "!" */
    template <typename T>
    TestCase& check_output(const T& a, std::string b)
    {
        std::ostringstream os;
        os << a;
        if (os.str() == b)
            numPassed++;
        else
        {
            numFailed++;
            *write
                    << name
                    << ": Failure in test #"
                    << numPassed + numFailed
                    << ": string value should be "
                    << b
                    << " but is "
                    << os.str()
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
    std::ostream* write;
};

#endif // TESTCASE_H
