//576. Out of Boundary Paths
#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
int solve(int n, int m, int maxMove, int startRow, int startColumn){

    if(startColumn<0 || startColumn>=n || startRow<0 || startRow>=m)return 1;


    int up=0,down=0,left=0,right=0;
    if(maxMove>0)up=solve(n, m, maxMove-1, startRow-1, startColumn);
    if(maxMove>0)down=solve(n, m, maxMove-1, startRow+1, startColumn);
    if(maxMove>0)left=solve(n, m, maxMove-1, startRow, startColumn-1);
    if(maxMove>0)right=solve(n, m, maxMove-1, startRow, startColumn+1);

    return (up+down+left+right)%M;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    return solve(n, m, maxMove, startRow, startColumn);
}
int main()
{
    int m,n,maxMove,startRow,startColumn;
    cin>>m>>n>>maxMove>>startRow>>startColumn;
    cout<<findPaths(m,n,maxMove,startRow,startColumn);
   return 0;
}