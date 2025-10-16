#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

// Note: Slower O(nlogn) and not good solution
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        std::map<int, int> factors;
        // O(n)
        for (auto& num : nums) {
            auto moduled = ((num % value) + value) % value;
            auto it = factors.find(moduled);
            if (it != factors.end())
                it->second++;
            else
                factors.insert(std::pair(moduled, 0));
            num = moduled + (factors[moduled] * value);
        }

        // O(nlogn)
        std::sort(nums.begin(), nums.end());

        // O(n) find MEX
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i)
                return i;
        }
        return nums.size();
    }
};

// Note: Faster O(n) and smarter solution
// class Solution {
// public:
//     int findSmallestInteger(vector<int>& nums, int value) {
//         vector<int> remainders(value);
//         for (auto& x : nums) {
//             int modulated = (x % value + value) % value;
//             remainders[modulated]++;
//         }
//         int ans = 0;
//         while (remainders[ans % value] > 0) {
//             remainders[ans % value]--;
//             ans++;
//         }
//         return ans;
//     }
// };

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {1,-10,7,13,6,8};
    auto ans = sol.findSmallestInteger(nums, 5);
    std::cout << ans;
}