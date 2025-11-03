#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int minCost(std::string colors, std::vector<int>& neededTime) {
        int ans = 0;
        int sum = neededTime[0];
        int max = sum;
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                sum += neededTime[i];
                if (neededTime[i] > max)
                    max = neededTime[i];
                if (i == colors.size() - 1)
                    ans += (sum - max);
            } else {
                if (sum != neededTime[i - 1]) {
                    ans += (sum - max);
                }
                max = sum = neededTime[i];
            }
        }

        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::string s = "aabaa";
    std::vector<int> neededTime = {1,2,3,4,1};
    std::cout << sol.minCost(s, neededTime);
}