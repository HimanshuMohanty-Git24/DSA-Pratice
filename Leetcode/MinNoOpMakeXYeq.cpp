// 100159. Minimum Number of Operations to Make X and Y Equal
#include <bits/stdc++.h>
using namespace std;
int minimumOperationsToMakeEqual(int x, int y)
{
        queue<int> q;
        q.push(x);
        int step = 0;
        map<int, int> vis;

        while (!q.empty()) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                int k = q.front();
                q.pop();

                if (k > 1e4 || k < 0) continue;
                if (k == y) return step;

                if (k % 11 == 0 && vis[k / 11] == 0) {
                    vis[k / 11] = 1;
                    q.push(k / 11);
                }
                if (k % 5 == 0 && vis[k / 5] == 0) {
                    vis[k / 5] = 1;
                    q.push(k / 5);
                }
                if (k > 0 && vis[k - 1] == 0) {
                    vis[k - 1] = 1;
                    q.push(k - 1);
                }
                if (vis[k + 1] == 0) {
                    vis[k + 1] = 1;
                    q.push(k + 1);
                }
            }

            step++;
        }

        return step;
}
int main()
{
    int x = 54, y = 2;
    cout << minimumOperationsToMakeEqual(x, y) << endl;
    return 0;
}