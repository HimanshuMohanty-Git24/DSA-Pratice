//2160. Minimum Sum of Four Digit Number After Splitting Digits

// Input: num = 2932
// Output: 52
// Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
// The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
#include<bits/stdc++.h>
using namespace std;
int minimumSum(int num) {
        int sum=0;
        int n=num;
        int count=0;
        while(n>0)
        {
            n=n/10;
            count++;
        }
        int arr[count];
        for(int i=count-1;i>=0;i--)
        {
            arr[i]=num%10;
            num=num/10;
        }
        //Code Explanation
        //1. First we find the number of digits in the given number.
        //2. Then we store the digits in an array.
        //3. Then we sort the array.
        //4. Then we form two numbers by taking alternate digits from the array.
        //5. Then we add the two numbers and return the sum.
        sort(arr,arr+count);
        int a=0;
        int b=0;
        for(int i=0;i<count;i++)
        {
            if(i%2==0)//Index: 0,2
            {
                a=a*10+arr[i];
            }
            else//Index: 1,3
            {
                b=b*10+arr[i];
            }
        }
        sum=a+b;
        return sum;
}
int main()
{
    int num;
    cin>>num;
    cout<<minimumSum(num);
   return 0;
}