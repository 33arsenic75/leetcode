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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp;
        while(even && even->next){
            temp=odd->next;
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            odd->next=temp;
            even=even->next;
        }
        return head;
    }
};