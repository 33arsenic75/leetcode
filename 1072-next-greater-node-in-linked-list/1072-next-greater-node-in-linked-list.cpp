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
    vector<int> nextLargest(ListNode*head){
        if(!(head->next))return vector<int>{0};
        vector<int>temp = nextLargest(head->next);
        if(head->val < head->next->val){
            temp.push_back(head->next->val);
            return temp;
        }
        for(int i = temp.size() - 1 ; i >= 0 ; i--){
            if(head->val < temp[i]){
                temp.push_back(temp[i]);
                return temp;
            }
        }
        temp.push_back(0);
        return temp;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans = nextLargest(head);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};