#include "TestCase.hpp"

TestCase::TestCase(std::string name, std::ostream& write)
{
    this->name = name;
    this->write = &write;
    this->numPassed = 0;
    this->numFailed = 0;
}

/**
/*Test int operators: 2 failed, 5 passed, 7 total.
    	---
*/
void TestCase::print()
{
    *write
            << name
            << ": "
            << numFailed
            << " failed, "
            << numPassed
            << " passed, "
            << numPassed + numFailed
            << " total."
            << endl
            << "---"
            << endl;
}
