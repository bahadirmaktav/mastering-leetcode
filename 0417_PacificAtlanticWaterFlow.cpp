#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
    DFS veya BFS kullanılmalı. 
    Fakat her hücre için tek tek DFS/BFS yapılırsa yavaş oluyor( mxn matris için : O(n) = (m x n)'2).
    Bu nedenle hızlı çözümde olduğu gibi tersten gidilerek pasific ve atlatic okyanuslarına ulaşabilen hücreleri bulmak lazım.
    Bu senaryoda O(n) = 3 x m x n yani m x n oluyor.
*/

// Note: True but slow solution
// class Solution {
// public:
//     struct Point {
//         int m;
//         int n;
//     };

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         vector<vector<int>> ans;
//         int row = heights.size();
//         int col = heights[0].size();
//         for (int m = 0; m < row; ++m) {
//             for (int n = 0; n < col; ++n) {
//                 stack<Point> q{};
//                 vector<vector<bool>> visited(row, vector<bool>(col, false));
//                 q.push({m, n});
//                 visited[m][n] = true;
//                 bool pasific = (m == 0 || n == 0) ? true : false;
//                 bool atlantic = (m == (row - 1) || n == (col - 1)) ? true : false;
//                 while (!q.empty()) {
//                     Point p = q.top();
//                     q.pop();
//                     int dx[4] = {0, 1, 0, -1};
//                     int dy[4] = {1, 0, -1, 0};
//                     for (int dir = 0; dir < 4; dir++) {
//                         int r = p.m + dx[dir];
//                         int c = p.n + dy[dir];
//                         if ((r >= 0) && (r < row) && (c >= 0) && (c < col) 
//                         && (visited[r][c] == false) 
//                         && (heights[p.m][p.n] >= heights[r][c])) {
//                             q.push({r,c});
//                             visited[r][c] = true;
//                             if (r == 0 || c == 0)
//                                 pasific = true;
//                             if (r == (row - 1) || c == (col - 1))
//                                 atlantic = true;
//                         }
//                     }
//                     if (pasific && atlantic) {
//                         ans.push_back({m, n});
//                         break;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Note : True and faster solution
class Solution {
public:
    struct Point {
        int m;
        int n;
    };

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        stack<Point> pq;
        stack<Point> aq;

        auto dsf = [&](stack<Point>& q, vector<vector<bool>>& ocean) {
            while (!q.empty()) {
                Point p = q.top();
                q.pop();
                int dx[4] = {0, 1, 0, -1};
                int dy[4] = {1, 0, -1, 0};
                for (int dir = 0; dir < 4; dir++) {
                    int r = p.m + dx[dir];
                    int c = p.n + dy[dir];
                    if ((r >= 0) && (r < row) && (c >= 0) && (c < col) &&
                        (ocean[r][c] == false) &&
                        (heights[p.m][p.n] <= heights[r][c])) {
                        q.push({r, c});
                        ocean[r][c] = true;
                    }
                }
            }
        };

        for (int m = 0; m < row; ++m) {
            pq.push({m,0});
            aq.push({m, col-1});
            pacific[m][0] = true;
            atlantic[m][col-1] = true;
        }
        for (int n = 0; n < col; ++n) {
            pq.push({0,n});
            aq.push({row-1,n});
            pacific[0][n] = true;
            atlantic[row-1][n]=true;
        }

        dsf(aq, atlantic);
        dsf(pq, pacific);

        vector<vector<int>> ans;
        for (int m = 0; m < row; ++m) {
            for (int n = 0; n < col; ++n) {
                if (atlantic[m][n] && pacific[m][n])
                    ans.push_back({m,n});
            }
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    for (auto ans : sol.pacificAtlantic(heights)) {
        cout << ans[0] << "," << ans[1] << "\n";
    }
}