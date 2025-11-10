#include "HelperIncludes.h"

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        // !!!!!!!! MONOTONIC STACK !!!!!!!!
        int ans = 0;
        std::vector<int> mono_stack;
        for (const auto& num : nums) {
            while (!mono_stack.empty() && mono_stack.back() >= num) {
                ans += mono_stack.back() == num ? 0 : 1;
                mono_stack.pop_back();
            }
            if (num == 0)
                continue;
            mono_stack.push_back(num);
        }
        return ans + mono_stack.size();
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {1023, 456, 789, 1023, 120, 4321, 456, 25000, 9876, 120, 120, 789, 120, 1023, 25000};
    int ans = sol.minOperations(nums);
    std::cout << ans;
}