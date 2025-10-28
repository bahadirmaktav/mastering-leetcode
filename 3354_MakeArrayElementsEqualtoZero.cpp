#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    // PREFIX SUM
    int countValidSelections(std::vector<int>& nums) {
        int ans = 0;
        int left_sum = 0;
        int right_sum = std::accumulate(nums.begin(), nums.end(), 0);
        for (const auto& num : nums) {
            if (num == 0) {
                int diff = std::abs(left_sum - right_sum);
                if (diff == 1)
                    ans++;
                else if (diff == 0)
                    ans += 2;
            }
            else {
                left_sum += num;
                right_sum -= num;
            }
        }
        return ans;
    }
    /* SIMULATION
    int countValidSelections(vector<int>& nums) {
        std::vector<int> zeros;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                zeros.push_back(i);
        }

        auto process = [](std::vector<int> nums, int curr, int dir, int non_zero_count) -> bool {
            while (curr >= 0 && curr <= nums.size() - 1) {
                if (nums[curr] > 0) {
                    nums[curr]--;
                    dir *= -1;
                    if (nums[curr] == 0)
                        non_zero_count--;
                }
                curr += dir;
            }
            return non_zero_count == 0 ? true : false;
        };

        int ans = 0;
        int non_zero_count = nums.size() - zeros.size();
        for (int i = 0; i < zeros.size(); ++i) {
            if (process(nums, zeros[i], 1, non_zero_count))
                ans++;
            if (process(nums, zeros[i], -1, non_zero_count))
                ans++;  
        }

        return ans;
    }
    */
};

int main(int, char**) {
    Solution sol;
    std::vector nums = {2,3,4,0,4,1,0};
    std::cout << sol.countValidSelections(nums);
}