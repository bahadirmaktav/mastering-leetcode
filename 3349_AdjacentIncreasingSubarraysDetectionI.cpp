#include <iostream>
#include <vector>

// Notes: My solution looks complicated
class Solution {
public:
    bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
        bool ans = k == 1 ? true : false;
        bool isff = false;
        for (int i = 1, cnt = 0, adj = 0, prev = nums[0]; i < nums.size(); ++i) {
            if (nums[i] > prev == 1) {
                cnt++;
                if (cnt + 1 == k) {
                    if (isff) {
                        ans = true;
                        break;
                    }
                    isff = true;
                    adj = 0;
                } else if (cnt + 1 == 2 * k) {
                    ans = true;
                    break;
                }
            } else {
                cnt = 0;
                if (isff)
                    adj++;
                if (adj > 1)
                    isff = false;
            }
            prev = nums[i];
        }
        return ans;
    }
};

// Notes: Less complicated solution
// class Solution {
// public:
//     bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
//         int n = nums.size();
//         int cnt = 1, precnt = 0, ans = 0;
//         for (int i = 1; i < n; ++i) {
//             if (nums[i] > nums[i - 1]) {
//                 ++cnt;
//             } else {
//                 precnt = cnt;
//                 cnt = 1;
//             }
//             ans = std::max(ans, std::min(precnt, cnt));
//             ans = std::max(ans, cnt / 2);
//         }
//         return ans >= k;
//     }
// };

int main(int, char**) {
    Solution sol;
    std::vector nums = {2,5,7,8,9,2,3,4,3,1};
    std::cout << sol.hasIncreasingSubarrays(nums, 2);
}