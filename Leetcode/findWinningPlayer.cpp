#include <bits/stdc++.h>
using namespace std;

int findWinningPlayer(vector<int>& skills, int k) {

    int n = skills.size();
    if(k>=n){
        return max_element(skills.begin(),skills.end())-skills.begin();
    }
    deque<int> players;
    for (int i = 0; i < n; i++) {
        players.push_back(i);
    }

    int current_winner = players[0];
    int consecutive_wins = 0;

    while (true) {
        int player1 = players[0];
        int player2 = players[1];

        players.pop_front();
        players.pop_front();

        if (skills[player1] > skills[player2]) {
            current_winner = player1;
            consecutive_wins++;
            players.push_front(player1);
            players.push_back(player2);
        } else {
            current_winner = player2;
            consecutive_wins = 1;
            players.push_front(player2);
            players.push_back(player1);
        }

        if (consecutive_wins == k) {
            return current_winner;
        }
    }
    return -1;
}
//Time Complexity: O(n)
//Space Complexity: O(n)

int main()
{
    vector<int> skills1 = {4, 2, 6, 3, 9};
    int k1 = 2;
    cout << "Winner index: " << findWinningPlayer(skills1, k1) << endl; // Output: 2

    vector<int> skills2 = {2, 5, 4};
    int k2 = 3;
    cout << "Winner index: " << findWinningPlayer(skills2, k2) << endl; // Output: 1

    vector<int> skills3 = {16,4,7,17};
    int k3=562084119;
    cout << "Winner index: " << findWinningPlayer(skills3, k3) << endl;

    return 0;
}
