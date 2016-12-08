#include ".\cppunitlite\TestHarness.h"
#include "utShapes.h"


#include <iostream>
#include <typeinfo>
#include "Cmd.h"

using namespace std;

int main()
{

    /*
    TestResult tr;
    TestRegistry::runAllTests(tr);
    */

    Cmd c;
    c.run();

    return 0;
}
