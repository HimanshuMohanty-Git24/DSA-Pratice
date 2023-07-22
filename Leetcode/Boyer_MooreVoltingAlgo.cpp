// 169. Majority Element
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int score = 0;
    for (auto n : nums) {
        if (n == candidate) {
                score++;
        } else{
            score--;
            if (score < 0) {
                candidate = n;
                score = 1;
            }
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {-1,1,1,1,2,1};
    cout << majorityElement(nums);
    return 0;
}
