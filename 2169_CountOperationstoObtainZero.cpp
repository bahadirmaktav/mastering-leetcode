#include "HelperIncludes.h"

class Solution {
public:
    int countOperations(int num1, int num2) {
        /* Bad
        int ans = 0;
        while(num1 != 0 && num2 != 0) {
            if (num1 > num2)
                num1 -= num2;
            else
                num2 -= num1;
            ans++;
        }
        return ans;
        */
        // Better
        int ans = 0;
        while(num1 != 0 && num2 != 0) {
            ans += num1 / num2;
            num1 %= num2;
            std::swap(num1, num2);
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    auto ans = sol.countOperations(10000, 1);
    std::cout << ans;
}