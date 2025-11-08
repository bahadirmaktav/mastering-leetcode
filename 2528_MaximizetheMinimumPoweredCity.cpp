#include "HelperIncludes.h"

class Solution {
public:
    long long maxPower(std::vector<int>& stations, int r, int k) {
        // Prefix sum + sliding window
        std::vector<long long> sum_stats;
        long long sum_tmp = 0;
        for (int i = 0; i <= r; ++i) {
            sum_tmp += stations[i];
        }
        long long sum_stat_max = sum_tmp;
        sum_stats.push_back(sum_tmp);
        for (int i = 1; i < stations.size(); ++i) {
            if (i + r < stations.size()) {
                sum_tmp += stations[i + r];
            }
            if (i - r - 1 >= 0)
                sum_tmp -= stations[i - r - 1];
            if (sum_tmp > sum_stat_max)
                    sum_stat_max = sum_tmp;
            sum_stats.push_back(sum_tmp);
        }

        // Binary search + difference array
        long long min = 0;
        long long max = k + sum_stat_max;
        long long avr = 0;
        long long ans = 0;
        while (min <= max) {
            avr = min + (max - min) / 2;
            bool k_not_enough = false;
            long long sum = 0;
            int added_num = 0;
            std::vector<long long> diff (stations.size(), 0);
            std::vector<long long> sum_stats_tmp = sum_stats;
            for (int i = 0; i < sum_stats_tmp.size(); ++i) {
                sum += diff[i];
                sum_stats_tmp[i] += sum;
                if (sum_stats_tmp[i] < avr) {
                    long long tmp_diff = avr - sum_stats_tmp[i];
                    added_num += tmp_diff;
                    if (added_num > k) {
                        k_not_enough = true;
                        break;
                    }
                    sum += tmp_diff;
                    if (i + 2 * r + 1 < sum_stats_tmp.size())
                        diff[i + 2 * r + 1] -= tmp_diff;
                }
            }
            if (k_not_enough) {
                max = avr - 1;
            } else {
                ans = avr;
                min = avr + 1;
            }
        }
        return ans;
    }
};


int main(int, char**) {
    Solution sol;
    // std::vector<int> nums = {4,4,4,4}; std::cout << sol.maxPower(nums, 0, 3);
    // std::vector<int> nums = {1,2,4,5,0}; std::cout << sol.maxPower(nums, 1, 2);
    std::vector<int> nums = {4,0,17,0,17,100,3,8,8,2,1,99,50}; std::cout << sol.maxPower(nums, 3, 200);
}