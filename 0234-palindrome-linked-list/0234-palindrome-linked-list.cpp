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
    ListNode* reversList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // find middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reversList(slow);
        ListNode* first = head;

        while(second) {
            if(first->val != second->val) {
                return false;
            }
            second = second->next;
            first = first->next;
        }
        return true;


    }
};