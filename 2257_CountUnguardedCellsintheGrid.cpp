#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Solution {
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls) {
        std::vector<std::vector<char>> cells(m, std::vector<char>(n, '-'));

        // O(a)
        for (int i = 0; i < guards.size(); ++i) {
            cells[guards[i][0]][guards[i][1]] = 'G';
        }
        // O(b)
        for (int i = 0; i < walls.size(); ++i) {
            cells[walls[i][0]][walls[i][1]] = 'W';
        }

        // O(m x n)
        for (int i = 0; i < guards.size(); ++i) {
            // left
            int tmp_c = guards[i][1] - 1;
            int tmp_r = guards[i][0];
            while (tmp_c >= 0) {
                if (cells[tmp_r][tmp_c] == 'W' || cells[tmp_r][tmp_c] == 'G')
                    break;
                else
                    cells[tmp_r][tmp_c] = '+';
                tmp_c--;
            }
            // right
            tmp_c = guards[i][1] + 1;
            while (tmp_c < n) {
                if (cells[tmp_r][tmp_c] == 'W' || cells[tmp_r][tmp_c] == 'G')
                    break;
                else
                    cells[tmp_r][tmp_c] = '+';
                tmp_c++;
            }
            // up
            tmp_c = guards[i][1];
            tmp_r = guards[i][0] - 1; 
            while (tmp_r >= 0) {
                if (cells[tmp_r][tmp_c] == 'W' || cells[tmp_r][tmp_c] == 'G')
                    break;
                else
                    cells[tmp_r][tmp_c] = '+';
                tmp_r--;
            }
            // down
            tmp_r = guards[i][0] + 1; 
            while (tmp_r < m) {
                if (cells[tmp_r][tmp_c] == 'W' || cells[tmp_r][tmp_c] == 'G')
                    break;
                else
                    cells[tmp_r][tmp_c] = '+';
                tmp_r++;
            }
        }

        // O(m x n)
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (cells[i][k] == '-')
                    ans++;
            }
        }

        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<std::vector<int>> guards = {{0,0},{1,1},{2,3}};
    std::vector<std::vector<int>> walls = {{0,1},{2,2},{1,4}};
    auto ans = sol.countUnguarded(4, 6, guards, walls);
    std::cout << ans;
}