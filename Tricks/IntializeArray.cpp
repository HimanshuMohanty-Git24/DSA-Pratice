#include <iostream>

using namespace std;

int main()
{
    int arr[100];
    fill_n(arr, 100, 24); // All elemnt intialized to 24
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}