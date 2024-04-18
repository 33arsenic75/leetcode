/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <cstdlib> // for rand()
using namespace std;

class Solution {
public:
    vector<int> q;
    int n;

    Solution(ListNode* head) {
        while (head) {
            q.push_back(head->val);
            head = head->next;
        }
        n = q.size();
    }
    
    int getRandom() {
        int idx = rand() % n;
        return q[idx];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

