#include "TestCase.hpp"

TestCase::TestCase(std::string name, std::ostream& error)
{
    this->name = name;
    this->error = &error;
    this->numPassed = 0;
    this->numFailed = 0;
}

void TestCase::print()
{

}
