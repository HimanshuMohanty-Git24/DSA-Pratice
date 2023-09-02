#include <iostream>
#include <vector>
using namespace std;
using namespace std;
void Bubblesort(vector<int> &arr, int n)
{
    for (int i = n-1; i >0; i--)
    {
        int swapFlag =0;
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp =arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swapFlag==1;
            }
        }
        if(swapFlag==0){
            break;
        }
    }
}
int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    int size = arr.size();
    Bubblesort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}