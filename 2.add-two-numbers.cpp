/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addnumber(l1,l2,0);
    }
    ListNode* addnumber(ListNode* l1, ListNode* l2,int carry){
        if(!l1 && !l2){
            if(carry==1){
                ListNode* n =new ListNode;
                n->val=carry;
                return n;
            }
            else return nullptr;
        }
        if(!l1){
            int val=l2->val;
            val+=carry;
            l2->val = val %10;
            l2->next = addnumber(nullptr,l2->next,val/10);
            return l2;
        }
        else if(!l2){
            int val=l1->val;
            val+=carry;
            l1->val = val %10;
            l1->next = addnumber(nullptr,l1->next,val/10);
            return l1;
        }
        int val = l1->val + l2->val + carry;
        l1-> val = val%10;
        l1->next = addnumber(l1->next,l2->next,val/10);
        return l1;
    }
};
// @lc code=end

