//2125. Number of Laser Beams in a Bank
#include<bits/stdc++.h>
using namespace std;
int numberOfBeams(vector<string>& bank) {
    char one = '1';
    int prev = count(bank[0].begin(), bank[0].end(), one);//STL function to count the number of 1's in the first row.
    int res =0;

    for (int i = 1; i < bank.size(); i++)
    {
        int curr = count(bank[i].begin(), bank[i].end(), one);
        res += (prev*curr);
        if(curr){
            prev=curr;
        }
    }
    return res;
}//Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the bank matrix.
//Space Complexity: O(1) as no extra space is used.
/*
Logic:
1. We will iterate through the bank matrix row by row.
2. We will count the number of 1's in the current row and multiply it with the number of 1's in the previous row.
3. We will add the result to the final result.
4. We will update the number of 1's in the previous row with the number of 1's in the current row.
5. We will return the final result.
*/
int main()
{
    vector<string> bank={"011001","000000","010100","001000"};
    cout<<numberOfBeams(bank);
    return 0;
}