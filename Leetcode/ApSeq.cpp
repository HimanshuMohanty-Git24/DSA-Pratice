/*1502. Can Make Arithmetic Progression From Sequence
*/
#include<bits/stdc++.h>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for(int i = 2; i < arr.size(); i++){
        if(arr[i] - arr[i-1] != diff)
            return false;
    }
    return true;
}
int main()
{
    vector<int> arr = {1,2,4};
    bool ans=canMakeArithmeticProgression(arr);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
   return 0;
}