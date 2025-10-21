#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
        int ans = 0;
        std::unordered_map<int,int> freqs;

        // O(nlogn)
        std::sort(nums.begin(),nums.end());

        // O(n)
        for (const auto& num : nums) {
            freqs[num]++;
        }

        for (int i = nums.front(); i <= nums.back(); ++i) {
            auto lowerb = std::lower_bound(nums.begin(), nums.end(), i - k);
            auto upperb = std::upper_bound(nums.begin(), nums.end(), i + k);
            int window = upperb - lowerb;
            int maxb = freqs[i] + numOperations;
            ans = std::max(ans, std::min(maxb, window));
        }

        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {3,4,8,9,18,18,19,23};
    std::cout << sol.maxFrequency(nums, 3, 3);
}