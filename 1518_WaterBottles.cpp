#include <iostream>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles >= numExchange) {
            int exchangedBottles = numBottles / numExchange;
            int leftEmptyBottles = numBottles % numExchange;
            result += exchangedBottles;
            numBottles = exchangedBottles + leftEmptyBottles;
        }
        return result;
    }
};

int main(int, char**) {
    Solution sol;
    std::cout << sol.numWaterBottles(15, 3);
}