//2037. Minimum Number of Moves to Seat Everyone
#include<bits/stdc++.h>
using namespace std;
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n = seats.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += abs(seats[i]-students[i]);
        }
        return ans;
}
int main()
{
    vector<int> seats = {3,1,5};
    vector<int> students = {2,7,4};
    cout<<minMovesToSeat(seats,students);
   return 0;
}