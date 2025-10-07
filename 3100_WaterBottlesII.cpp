#include <iostream>

// Note: Bad Solution
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int bottlesDrunk = 0;
        while(numBottles > 0 || emptyBottles >= numExchange) {
            while(emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                numExchange++;
                numBottles++;
            }
            bottlesDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
        }
        return bottlesDrunk;
    }
};

// Note: Good Solution
// class Solution {
// public:
//     int maxBottlesDrunk(int numBottles, int numExchange) {
//         int ans = numBottles;
//         for (int empty = numBottles; empty >= numExchange; numExchange++) {
//             ans++;
//             empty -= numExchange - 1;
//         }
//         return ans;
//     }
// };

int main(int, char**) {
    Solution sol;
    std::cout << sol.maxBottlesDrunk(15, 3);
}