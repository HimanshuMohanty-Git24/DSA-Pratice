#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream ifile;
    ifile.open("inputFile.dat");
    cout << "Reading data from a file :-" << endl;
    while (!ifile.eof())
    {
        char ch;
        ifile >> ch;
        cout << ch << endl;
    }
    ifile.close();
    return 0;
}