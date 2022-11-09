#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream ofile;
    ofile.open("inputFile.dat");
    ofile << "This is a line in a file" << endl;
    ofile << "This is another line" << endl;
    cout << "Data written to file" << endl;
    ofile.close();
    return 0;
}