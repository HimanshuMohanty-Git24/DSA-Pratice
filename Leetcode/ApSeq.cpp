/*1502. Can Make Arithmetic Progression From Sequence
*/
#include<bits/stdc++.h>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());//Sorting the array
    int diff = arr[1] - arr[0];//Calculating the difference
    for(int i = 2; i < arr.size(); i++){//Checking if the difference is same for all the elements
        if(arr[i] - arr[i-1] != diff)
            return false;
    }
    return true;
}
int main()
{
    vector<int> arr = {1,2,4};//Input array
    bool ans=canMakeArithmeticProgression(arr);//Function call
    if(ans){//Printing the result
        cout<<"true";
    }
    else{
        cout<<"false";
    }
   return 0;
}