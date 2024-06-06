#include<bits/stdc++.h>
using namespace std;

int xorseq(int x,int y){
    int ans = x^y;
    return ans & -ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << xorseq(x, y) << endl;
    }

    return 0;
}
