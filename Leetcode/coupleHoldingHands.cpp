// 765. Couples Holding Hands
#include<bits/stdc++.h>
using namespace std;
int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    int ans = 0;
    for (int i = 0; i < n; i+=2)
    {
        if(row[i]%2==0){
            if(row[i+1]!=row[i]+1){
                for (int j = i+2; j < n; j++)
                {
                    if(row[j]==row[i]+1){
                        swap(row[i+1],row[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
        else{
            if(row[i+1]!=row[i]-1){
                for (int j = i+2; j < n; j++)
                {
                    if(row[j]==row[i]-1){
                        swap(row[i+1],row[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> rows={6,2,1,7,4,5,3,8,0,9};
    cout<<minSwapsCouples(rows);
    return 0;
}
