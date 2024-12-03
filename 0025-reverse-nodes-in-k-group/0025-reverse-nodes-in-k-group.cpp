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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*n = head;
        vector<int>data;
        while(n){
            data.push_back(n->val);
            n = n->next;
        }
        int i = 0;
        int sz = data.size();
        while(i+k<=sz){
            reverse(data.begin()+i,data.begin()+k+i);
            i+=k;
        }
        n = head;
        i = 0;
        while(n){
            n->val = data[i];
            n = n->next;
            i++;
        }
        return head;
    }
};

// ListNode*n = head;
// ListNode*m = head->next;
// ListNode*r;
// while(n && m){
//     r = m->next;
//     m->next = n;
//     n = m;
//     m = r;
// }
// head->next = nullptr;