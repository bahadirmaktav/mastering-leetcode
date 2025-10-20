#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int ans = 0;
        for (const auto& operation : operations) {
            if (operation[0] == '+' || operation[operation.size() - 1] == '+') {
                ans++;
            } else {
                ans--;
            }
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<std::string> operations = {"X++","++X","--X","X--"};
    std::cout << sol.finalValueAfterOperations(operations);
}