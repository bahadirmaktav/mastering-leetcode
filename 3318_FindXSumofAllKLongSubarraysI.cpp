#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> findXSum(std::vector<int>& nums, int k, int x) {
        auto x_sum = [&](const std::unordered_map<int, int>& m) -> int {
            std::vector<std::pair<int,int>> tmp;
            for (auto it = m.begin(); it != m.end(); ++it) {
                tmp.emplace_back(it->first, it->second);
            }
            std::sort(tmp.begin(), tmp.end(), [](const auto& a, const auto& b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });
            int res = 0, i = 0;
            while (i < tmp.size() && i < x) {
                res += (tmp[i].first * tmp[i].second);
                i++;
            }
            return res;
        };

        std::vector<int> ans;
        std::unordered_map<int, int> occs;
        // Get first window
        for (int i = 0; i < k; ++i) {
            occs[nums[i]]++;
        }
        ans.push_back(x_sum(occs));

        // Add the end, remove the begin
        for (int i = k; i < nums.size(); ++i) {
            occs[nums[i - k]]--;
            occs[nums[i]]++;
            ans.push_back(x_sum(occs));
        }

        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {1,1,2,2,3,4,2,3};
    auto ans = sol.findXSum(nums, 6, 2);
    std::cout << ans[0] << ", " << ans[1] << ", " << ans[2];
}