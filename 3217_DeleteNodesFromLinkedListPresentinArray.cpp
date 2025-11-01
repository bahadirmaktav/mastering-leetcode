#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        // O(n)
        std::unordered_set<int> snums;
        for (const auto& num : nums)
            snums.insert(num);
        
        // O(n)
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (snums.find(curr->val) != snums.end()) {
                if (curr == head) {
                    head = curr->next;
                    delete curr;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main(int, char**) {
    Solution sol;
    std::vector<int> nums = {1,2,3};
    ListNode* n4 = new ListNode(5);
    ListNode* n3 = new ListNode(4, n4);
    ListNode* n2 = new ListNode(3, n3);
    ListNode* n1 = new ListNode(2, n2);
    ListNode* n0 = new ListNode(1, n1);
    auto ans = sol.modifiedList(nums, n0);
    std::cout << ans->val;
}