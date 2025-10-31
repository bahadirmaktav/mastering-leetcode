#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
        std::vector<int> ans;
        std::unordered_set<int> vnums;
        for (const auto& num : nums) {
            if (vnums.find(num) == vnums.end())
                vnums.insert(num);
            else
                ans.push_back(num);
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {0,3,2,1,3,2};
    auto ans = sol.getSneakyNumbers(nums);
    std::cout << ans[0] << ", " << ans[1];
}