#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = (right - left) * min(height[right], height[left]);
        while(left < right){
            int area = (right - left) * min(height[right], height[left]);
            if(area > res)
                res = area;
            if(height[right] > height[left])
                left++;
            else if(height[right] < height[left])
                right--;
            else {
                left++;
                right--;
            }
        }
        return res;
    }
};

int main(int, char**) {
    Solution sol;
    vector<int> hegiht = {1,8,6,2,5,4,8,3,7};
    std::cout << sol.maxArea(hegiht);
}