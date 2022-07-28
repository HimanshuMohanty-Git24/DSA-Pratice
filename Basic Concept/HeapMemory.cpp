#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *p;
    int n = 5;
    p = new int[n];
    delete[] p;
    p = nullptr;
    return 0;
}
