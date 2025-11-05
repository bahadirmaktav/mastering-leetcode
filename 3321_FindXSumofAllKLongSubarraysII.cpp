#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <set>

class Solution {
public:
    std::vector<long long> findXSum(std::vector<int>& nums, int k, int x) {
        std::unordered_map<int, int> occ;
        std::set<std::pair<int, int>> most;
        std::set<std::pair<int, int>> least;
        long long total = 0;

        auto add = [&](const std::pair<int, int>& p) {
            if (most.size() < x || p > *most.begin()) {
                total += (long long)p.first * p.second;
                most.insert(p);
                if (most.size() > x) {
                    auto tmp = *most.begin();
                    total -= (long long)tmp.first * tmp.second;
                    least.insert(tmp);
                    most.erase(tmp);
                }
            } else {
                least.insert(p);
            }
        };

        auto remove = [&](const std::pair<int, int>& p) {
            if (p >= *most.begin()) {
                total -= (long long)p.first * p.second;
                most.erase(p);
                if (least.size() > 0) {
                    auto tmp = *least.rbegin();
                    total += tmp.first * (long long)tmp.second;
                    most.insert(tmp);
                    least.erase(tmp);
                }
            } else {
                least.erase(p);
            }
        };

        auto insert_num = [&](int num) {
            if (occ[num]) {
                remove({occ[num], num});
            }
            ++occ[num];
            add({occ[num], num});
        };

        auto remove_num = [&](int num) {
            remove({occ[num], num});
            --occ[num];
            if (occ[num]) {
                add({occ[num], num});
            }
        };

        std::vector<long long> ans;
        for (int i = 0; i < nums.size(); ++i) {
            insert_num(nums[i]);
            if (i >= k) {
                remove_num(nums[i - k]);
            }
            if (i >= k - 1) {
                ans.push_back(total);
            }
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