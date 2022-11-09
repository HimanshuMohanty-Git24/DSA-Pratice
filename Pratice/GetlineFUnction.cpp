#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string data;
    ofstream outfile;
    outfile.open("file.dat");
    cout << "Writing to the file" << endl;
    cout << "Enter section name: ";
    getline(cin, data);
    outfile << data << endl;
    cout << "Enter your id: ";
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();
    ifstream infile;
    cout << "Reading from the file" << endl;
    infile.open("file.dat");
    getline(infile, data);
    cout << data << endl;
    getline(infile, data);
    cout << data << endl;
    infile.close();
    return 0;
}
