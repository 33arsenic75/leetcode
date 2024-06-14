/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        if(!p1)return false;
        if(p1->next)p1=p1->next;
        else return false;
        while(p1!=p2){
            if(p2->next)p2=p2->next;
            else return false;
            if(p1->next)p1=p1->next;
            else return false;
            if(p1->next)p1=p1->next;
            else return false;
        }
        return true;
    }
};