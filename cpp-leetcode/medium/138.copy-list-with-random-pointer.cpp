/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        Node*n = head;
        mp = map<Node*,Node*>();
        mp[nullptr]=nullptr;
        while(n){
            Node* newNode = new Node(n->val);
            mp[n] = newNode;
            n = n->next;
        }
        n = head;
        while(n){
            mp[n]->next = mp[n->next];
            mp[n]->random = mp[n->random];
            n = n->next;
        }
        return mp[head];
    }
};
// @lc code=end

