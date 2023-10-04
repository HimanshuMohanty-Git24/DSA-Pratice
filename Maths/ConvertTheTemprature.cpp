//2469. Convert the Temperature
#include<bits/stdc++.h>
using namespace std;
vector<double> convertTemperature(double celsius) {
    vector<double> res;
    double kelvin=celsius+273.15;
    double fahrenheit = celsius*1.80+32.00;
    res.push_back(kelvin);
    res.push_back(fahrenheit);
    return res;
}
int main()
{
    double temp;
    cin>>temp;
    vector<double> res =  convertTemperature(temp);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}