//380. Insert Delete GetRandom O(1)
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
        vector<int> v;
        unordered_map<int, int> mp;
        RandomizedSet() {
            v.clear();
            mp.clear();
        }
        bool insert(int val) {
            if (mp.find(val) != mp.end()) {
                return false;
            }
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        }

        bool remove(int val) {
            if (mp.find(val) == mp.end()) {
                return false;
            }
            int index = mp[val];
            int last = v.back();
            v[index] = last;
            mp[last] = index;
            v.pop_back();
            mp.erase(val);
            return true;
        }

        int getRandom() {
            int n = v.size();
            int index = rand() % n;
            return v[index];
        }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    int param_4 = obj->getRandom();
    bool param_5 = obj->remove(1);
    bool param_6 = obj->insert(2);
    int param_7 = obj->getRandom();
    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6 << " " << param_7 << endl;
    return 0;
}