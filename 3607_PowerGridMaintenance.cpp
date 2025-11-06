#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

class Solution {
public:
    std::vector<int> processQueries(int c, std::vector<std::vector<int>>& connections, std::vector<std::vector<int>>& queries) {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Prepare vec for BFS
        std::vector<std::vector<int>> adj(c + 1);
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        std::vector<std::set<std::pair<int, int>>> grid_grps;   // on=0/off=1 , id
        std::unordered_map<int, std::pair<int, int>> pwrs; // id , <grp_id, on=0/off=1>
        std::vector<bool> vis(c + 1, false);

        auto bfs = [&](const int& k, const int& id) {
            std::queue<int> q;
            vis[id] = true;
            q.push(id);
            std::set<std::pair<int, int>> s;

            while (!q.empty()) {
                int curr_id = q.front();
                q.pop();

                s.emplace(0, curr_id);
                std::pair<int, int> tmp(k, 0);
                pwrs.emplace(curr_id, tmp);

                for (int x : adj[curr_id]) {
                    if (!vis[x]) {
                        vis[x] = true;
                        q.push(x);
                    }
                }

            }

            grid_grps.push_back(s);
        };

        for (int i = 1, k = 0; i <= c; ++i) {
            if (!vis[i]) {
                bfs(k, i);
                k++;
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::vector<int> ans;
        for (const auto& query : queries) {
            int id = query[1];
            int grp_id = pwrs[id].first;
            int pws_stat = pwrs[id].second;
            if (query[0] == 1 && pws_stat == 0) {
                ans.push_back(id);
            } else if (query[0] == 1 && pws_stat == 1) {
                if (grid_grps[grp_id].begin()->first == 1) { // all off
                    ans.push_back(-1);
                } else {
                    ans.push_back(grid_grps[grp_id].begin()->second);
                }
            } else if (query[0] == 2 && pws_stat == 0) {
                auto it = grid_grps[grp_id].find({0, id});
                if (it != grid_grps[grp_id].end()) {
                    grid_grps[grp_id].erase(it);
                    grid_grps[grp_id].emplace(1, id);
                }
                pwrs.find(id)->second.second = 1;
            }
        }

        return ans;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
};

int main(int, char**) {
    Solution sol;

    std::vector<std::vector<int>> connections = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    std::vector<std::vector<int>> queries = {
        {1, 3},
        {2, 1},
        {1, 1},
        {2, 2},
        {1, 2}
    };

    auto ans = sol.processQueries(5, connections, queries);
    for (const auto& num : ans) {
        std::cout << num << ", ";
    }
}