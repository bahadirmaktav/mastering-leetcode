#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Instead of implementing merge sort, std::sort O(nlogn) added.
        std::sort(potions.begin(), potions.end());
        std::vector<int> ans;
        for (auto& spell : spells) {
            // Instead of implementing binary search, std::upper_bound (use binary search inside) added.
            auto it = std::lower_bound(potions.begin(), potions.end(), (double) success / spell);
            ans.push_back(potions.end() - it);
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    auto ans = sol.successfulPairs(spells, potions, 7);
    std::cout << ans[0] << ", " << ans[1] << ", " << ans[2];
}