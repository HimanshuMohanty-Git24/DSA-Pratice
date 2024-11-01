//633. Sum of Square Numbers
#include<bits/stdc++.h>
using namespace std;
bool judgeSquareSum(int c) {
        for(long a=0;a*a<=c;a++)
        {
            double b=sqrt(c-a*a);
            if(b==(int)b)
                return true;
        }
        return false;
}
/*'
Logic:
1. We will iterate from 0 to sqrt(c) and check if there is any number b such that b^2=c-a^2.
2. If we find such b then we will return true.
3. If we don't find any such b then we will return false.
*/
int main()
{
    int n;
    cin>>n;
    cout<<judgeSquareSum(n)<<endl;
   return 0;
}