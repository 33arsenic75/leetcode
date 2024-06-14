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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        ListNode*n = head;
        ListNode*m = head->next;
        if(!m){
            if(st.find(n->val)==st.end())return 0;
            return 1;
        }
        int ans = 0;
        if(st.find(head->val)!=st.end())ans=1;
        ListNode*r;
        while(m){
            if(st.find(m->val)!=st.end() && st.find(n->val)==st.end()){
                cout<<m->val<<'\n';
                ans++;
            }
            r = m->next;
            n = m;
            m = r;
        }
        return ans;
    }
};