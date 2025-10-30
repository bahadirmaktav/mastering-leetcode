#include <iostream>
#include <vector>
#include <algorithm>

// Note: Wow!!!
class Solution {
public:
    int minNumberOperations(std::vector<int>& target) {
        // wow
        int ans = target[0];
        for (int i = 1; i < target.size(); ++i) {
            ans += std::max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
};

// Note: Worse solution...
// class Solution {
// public:
//     int minNumberOperations(std::vector<int>& target) {
//         int ans = 0;
//         int zero_count = 0;
//         int size = target.size();
//         while (size > zero_count) {
//             int min = INT_MAX;
//             int min_count = 0;
//             std::vector<int*> sub;
//             for (int i  = 0; i < size; ++i) {
//                 if (target[i] != 0) {
//                     sub.push_back(&target[i]);
//                     if (target[i] < min) {
//                         min = target[i];
//                         min_count = 1;
//                     } else if (target[i] == min) {
//                         min_count++;
//                     }
//                 }
//                 if (((target[i] == 0) || (i == size - 1)) && (!sub.empty())) {
//                     std::for_each(sub.begin(), sub.end(), [&](int* x) { *x -= min; });
//                     ans += min;
//                     zero_count += min_count;
//                     min_count = 0;
//                     min = INT_MAX;
//                     sub.clear();
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {1,2,3,2,1};
    auto ans = sol.minNumberOperations(nums);
    std::cout << ans;
}