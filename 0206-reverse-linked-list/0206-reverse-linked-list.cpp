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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* n = head;
        ListNode* m = head->next;
        ListNode* r;
        while(n && m){
            r = m->next;
            m->next = n;
            n = m;
            m = r;
        }
        head -> next = nullptr;
        return n;
    }
};