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
class Solution {
public:
    queue<int>q;
    Solution(ListNode* head) {
        while(head){
            q.push(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int temp = q.front();
        q.pop();
        q.push(temp);
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

