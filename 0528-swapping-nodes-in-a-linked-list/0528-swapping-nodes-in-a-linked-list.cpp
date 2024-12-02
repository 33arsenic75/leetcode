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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>data;
        ListNode*n = head;
        while(n){
            data.push_back(n->val);
            n = n->next;
        }
        int first = data[k-1];
        int last = data[data.size()-k];
        data[k-1]=last;
        data[data.size()-k]=first;
        n = head;
        int i = 0;
        while(n){
            n->val = data[i];
            i++;
            n = n->next;
        }
        return head;
    }
};