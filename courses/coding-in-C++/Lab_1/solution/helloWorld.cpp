#include <iostream>
#include "first_header.hpp"

using namespace std;

void printFromHeader()
{
    cout << "Hello from .hpp" << endl;
}

int main()
{
    cout << "Hello, World!" << endl;
    printFromHeader();

    return 0;
}
