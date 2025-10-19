#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

// Note:  Burada karmaşıklık çok yüksek çıkmadığından, olası tüm stringleri gezmek mümkün oluyor.
// BFS algoritmasına benzer bir yaklaşımla her string için ekleme ve döndürme işlemlerini yapıyoruz ve
// denediğimiz string'leri set içerisinde tutarak tekrardan denemekten kaçınıyoruz. 
class Solution {
public:
    std::string findLexSmallestString(std::string s, int a, int b) {
        std::unordered_set<std::string> vis;
        std::string ans = s;
        std::queue<std::string> q;
        q.push(s); vis.insert(s);
        while (!q.empty()) {
            // get string from queue
            s = q.front();
            q.pop();
            // compare with answer
            if (ans > s)
                ans = s;
            // accumulate
            std::string tmp = s;
            for (int i = 1; i < tmp.size(); i += 2)
                tmp[i] = ((tmp[i] - '0' + a) % 10) + '0';
            if (vis.find(tmp) == vis.end()) {
                q.push(tmp);
                vis.insert(tmp);
            }
            // rotate
            std::rotate(s.begin(), s.end() - b, s.end());
            if (vis.find(s) == vis.end()) {
                q.push(s);
                vis.insert(s);
            }
        }
        return ans;
    }
};

int main(int, char**) {
    Solution sol;
    std::string s = "56478453241897454154545454577778264175135486797455554184365413684134";
    std::cout << sol.findLexSmallestString(s, 7, 1);
}