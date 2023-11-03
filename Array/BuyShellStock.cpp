//121. Best Time to Buy and Sell Stock
#include<bits/stdc++.h>
using namespace std;
void maxProfit(vector<int>& prices) {
    int minM=prices[0];
    int profit =0;
    int buyDay = 0, sellDay = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        int cost = prices[i]-minM;
        if(cost > profit){
            profit = cost;
            sellDay = i;
        }
        if(prices[i] < minM){
            minM = prices[i];
            buyDay = i;
        }
    }
    cout<<"Buy on day "<<buyDay<<" at price "<<prices[buyDay]<<endl;
    cout<<"Sell on day "<<sellDay<<" at price "<<prices[sellDay]<<endl;
    cout<<"Max Profit "<<profit<<endl;
}
//Leetcode solution
int maxProfit2(vector<int>& prices) {
    int maxPro = 0;//Maximun profit
    int minPrice = INT_MAX;//Minimum price in the array till now

    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);//we are finding the minimum price till now
        maxPro = max(maxPro, prices[i] - minPrice);//we are finding the maximum profit till now
    }
    return maxPro;
}
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    maxProfit(prices);
   return 0;
}