//Find the Missing and Repeating Number
#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size();
    int hash[n+1] = {0};
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        hash[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(hash[i]==0)
        {
            ans.push_back(i);
        }
        else if(hash[i]==2)
        {
            ans.push_back(i);
        }
    }
    return ans;
}//Time Complexity: O(n) Auxiliary Space: O(n)
//Best solution using Maths
vector<int> findMissingRepeatingNumbers2(vector < int > a) {
    long long n =a.size();
    long long sum = (n*(n+1))/2;
    long long sumSq = (n*(n+1)*(2*n+1))/6;
    long long missingNumber = 0;
    long long repeatingNumber = 0;
    for(int i=0;i<n;i++)
    {
        sum -= (long long)a[i];
        sumSq -= (long long)a[i]*(long long)a[i];
    }
    missingNumber = (sum + sumSq/sum)/2;
    repeatingNumber = missingNumber - sum;
    vector<int> ans;
    ans.push_back(repeatingNumber);
    ans.push_back(missingNumber);
    return ans;
}//Time Complexity: O(n) Auxiliary Space: O(1)
/*
Logic:
1. Find the sum of all the numbers from 1 to n, let it be sum1.
2. Find the sum of all the elements in the array, let it be sum2.
3. Find the sum of squares of all the numbers from 1 to n, let it be sum3.
4. Find the sum of squares of all the elements in the array, let it be sum4.
5. Let x be the repeating number and y be the missing number.
6. Equate sum1 and sum2, and then equate sum3 and sum4.
7. We get x - y = sum2 - sum1 and x^2 - y^2 = sum4 - sum3.
8. We get x = (sum2 - sum1) + (sum4 - sum3)/(sum2 - sum1) and y = (sum4 - sum3)/(sum2 - sum1).
*/
//Xor Method
vector<int> findMissingRepeatingNumbers3(vector < int > a) {
    long long n = a.size();
    int xr = 0;
    for(int i=0;i<n;i++)
    {
        xr ^= a[i];//xor of all the elements in the array
        xr ^= (i+1);//xor of all the elements from 1 to n
    }
    int bitNo = 0;
    while(1)
    {
        if((xr & (1<<bitNo))!=0)
        {
            break;
        }
        bitNo++;
    }
    int zero = 0;
    int one = 0;
    for(int i=0;i<n;i++)
    {
        if((a[i] & (1<<bitNo))!=0)
        {
            one ^= a[i];
        }
        else
        {
            zero ^= a[i];
        }
        if(((i+1) & (1<<bitNo))!=0)
        {
            one ^= (i+1);
        }
        else
        {
            zero ^= (i+1);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(a[i]==zero)
        {
            ans.push_back(zero);
            ans.push_back(one);
            break;
        }
        else if(a[i]==one)
        {
            ans.push_back(one);
            ans.push_back(zero);
            break;
        }
    }
    return ans;
}
/*
Logic:
1. Find the xor of all the elements in the array and all the elements from 1 to n.
2. Find the rightmost set bit in the xor found in step 1.
3. Divide the elements in the array and from 1 to n into two groups, one group which has the rightmost set bit in the xor as 1 and the other group which has the rightmost set bit in the xor as 0.
4. Find the xor of all the elements in the first group, let it be x1, and the xor of all the elements in the second group, let it be x2.
5. Find the xor of all the elements from 1 to n in the first group, let it be y1, and the xor of all the elements from 1 to n in the second group, let it be y2.
6. The repeating number will be either x1 or x2, and the missing number will be either y1 or y2.
*/
int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,12,13,15,15};
    vector<int> ans = findMissingRepeatingNumbers3(a);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}