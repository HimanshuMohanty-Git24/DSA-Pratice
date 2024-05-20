// 1108. Defanging an IP Address
#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address)
{
    string ins = "[.]";
    for (int i = 0; i < address.length(); i++)
    {
        if (address[i] == '.')
        {
            address.replace(i, 1, ins);
            i += ins.length() - 1;
        }
    }
    return address;
}

int main()
{
    string address;
    cout << "Enter IP address: ";
    getline(cin, address);
    cout << defangIPaddr(address) << endl;
    return 0;
}
