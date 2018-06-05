#include "TestCase.hpp"

TestCase::TestCase(std::string name, std::ostream& write)
{
    this->name = name;
    this->write = &write;
    this->numPassed = 0;
    this->numFailed = 0;
}

void TestCase::print()
{

}
