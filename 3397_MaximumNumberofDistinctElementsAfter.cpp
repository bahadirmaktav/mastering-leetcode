#include <iostream>
#include <vector>
#include <algorithm>

// Note: Önce nums vectorü sortlanır. 
// Sonrasında her eleman olabileceği en küçük kullanılmamış değere eşitlenmeye çalışılır.
// Burada 'Greedy Algoritması' ve 'Sort Algoritması' kullanılmış olur.
// Sort işlemi O(nlogn), sonrasında yapılan işlem O(n) olacağından çözümün karmaşıklığı O(nlogn) olur.
class Solution {
public:
    int maxDistinctElements(std::vector<int>& nums, int k) {
        // O(nlogn)
        std::sort(nums.begin(), nums.end());

        // O(n)
        int ans = 0;
        int prev = INT_MIN;
        for (int num : nums) {
            if (int curr = std::min(std::max(num - k, prev + 1), num + k); curr > prev) {
                ans++;
                prev = curr;
            }
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector nums = {1,2,2,3,3,4};
    std::cout << sol.maxDistinctElements(nums, 2);
}