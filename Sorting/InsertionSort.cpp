#include <iostream>
#include <vector>
using namespace std;
using namespace std;
void Insertionsort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j=i;
        while (j>0&&arr[j-1]>arr[j])
        {
            int temp = arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    int size = arr.size();
    Insertionsort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}