// Given a set Of numbers. find a pair Of numbers that add up to a certain target. Ex given [1,2,3,9]
// and a target of 1O, identify that 1 and 9 add up to 1O.
#include<bits/stdc++.h>
using namespace std;
//O(n^2)
vector<int> TargetSum1(vector<int> &sum,int k){
    vector<int> res(2,0);
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum.size(); j++)
        {
            if(sum[i]+sum[j]==k){
                res[0]=sum[i];
                res[1]=sum[j];
                return res;
            }
        }
    }
    return res;
}
//O(N)
vector<int> TargetSum2(vector<int> &sum,int k){
    vector<int> arr(2,0);
    int i =0;
    int j =sum.size()-1;
    while (i<j)
    {
        int ans = sum[i]+sum[j];
        if(ans==k){
            arr[0]=sum[i];
            arr[1]=sum[j];
            return arr;
        }
        if(ans>k){
            j--;
        }
        if(ans<k){
            i++;
        }
    }
    return arr;
}
//O(N)also Works for unordered array
vector<int> TargetSum5(vector<int> &nums, int k) {
    unordered_map<int, int> numMap;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = k - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            result.push_back(complement);
            result.push_back(nums[i]);
            return result;
        }
        numMap[nums[i]] = i;
    }

    return result;
}
int main()
{
    vector<int> arr={1,2,3,9};
    int target=10;
    vector<int> res = TargetSum2(arr,target);
    if (res.empty()) {
        std::cout << "No valid pair found.\n";
    } else {
        for (auto i : res) {
            std::cout << i << " ";
        }
    }
    return 0;
}
//negative can occur
//integers only
//no repeats from same index