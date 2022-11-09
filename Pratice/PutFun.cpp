#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream fout;
    char ch;
    fout.open("inputFile.dat");
    do
    {
        cin.get(ch);
        fout.put(ch);
    } while (ch != '\n');
    fout.close();
    cout << "\nData written successfully...";
    return 0;
}
