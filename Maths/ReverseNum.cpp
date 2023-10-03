#include<bits/stdc++.h>
using namespace std;
long long reverse(int x) {
    if(x>INT_MAX || x<INT_MIN) return 0;
    long long rev=0;
    if(x<0){
        long long num=abs(static_cast<long long>(x));
        while(num>0){
            long long lastdigit = num%10;
            rev = (rev*10)+lastdigit;
            num=num/10;
        }
        if(rev>INT_MAX||rev<INT_MIN) return 0;
        return (-rev);
    }
    else{
        while(x>0){
            long long lastdigit = x%10;
            rev = (rev*10)+lastdigit;
            x=x/10;
        }
        if(rev>INT_MAX||rev<INT_MIN) return 0;
        return (rev);
    }
}
int main()
{
    long long n;
    cin>>n;
    long long res = reverse(n);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(log10(n))
//Space Complexity: O(1)