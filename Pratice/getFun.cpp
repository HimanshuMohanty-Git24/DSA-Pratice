#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ifstream fin;
    char ch;
    fin.open("inputFile.dat");
    cout << "\n Data in file...\n";
    while (!fin.eof())
    {
        fin.get(ch);
        cout << ch;
    }
    fin.close();
    return 0;
}
