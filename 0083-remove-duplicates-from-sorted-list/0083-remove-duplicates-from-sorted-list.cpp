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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* n = head ;
        if(!n)return nullptr;
        int v = n->val;
        n = n->next;
        while(n){
            if(n->val == v) n=n->next;
            else break;
        }
        head->next= deleteDuplicates(n);
        return head;
    }
};