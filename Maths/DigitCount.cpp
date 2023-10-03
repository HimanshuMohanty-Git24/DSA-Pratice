//https://www.codingninjas.com/studio/problems/count-digits_8416387?leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;
int DigitCount(int n)
{
    int ctr=0;
	int temp=n;
	while(n>0){
		int lastdigit = n%10;
		if(lastdigit!=0&&temp%lastdigit==0){
			ctr++;
		}
		n=n/10;
	}
	return ctr;
}
int main()
{
    int n;
    cin>>n;
    cout<<DigitCount(n)<<endl;
   return 0;
}