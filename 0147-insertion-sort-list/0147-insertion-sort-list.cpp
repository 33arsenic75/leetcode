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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>num;
        ListNode*n = head;
        while(n){
            num.push_back(n->val);
            n = n->next;
        }
        // for(int n: num)cout<<n<<" ";
        sort(num.begin(),num.end());
        n = head;
        int i = 0;
        while(n){
            n->val = num[i];
            i++;
            n = n->next;
        }
        return head;
    }
};