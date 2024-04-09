#include<bits/stdc++.h>
using namespace std;
bool isPathCrossing(string path) {
    unordered_map<int, unordered_set<int>> hash;
    hash[0].insert(0);
    int x = 0, y = 0;
    for(int i = 0; i < path.length(); i++) {
        if(path[i] == 'N') {
            y++;
        } else if(path[i] == 'E') {
            x++;
        } else if(path[i] == 'S') {
            y--;
        } else if(path[i] == 'W') {
            x--;
        }
        if(hash.count(x) && hash[x].count(y)) {
            return true;
        }

        hash[x].insert(y);
    }
    return false;
}
int main()
{
    string path = "NESWW";
    cout<<isPathCrossing(path);
    return 0;
}