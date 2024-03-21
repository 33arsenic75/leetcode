/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*>mp;
    vector<bool>vis;
    void clone(Node*n){
        if(!n)return;
        if(mp.find(n->val)!=mp.end())return;
        Node* newNode = new Node(n->val);
        mp[n->val] = newNode;
        for(Node*m:n->neighbors)clone(m);
    }
    void makelink(Node*n){
        if(!n)return;
        if(vis[n->val])return;
        vis[n->val]=true;
        for(Node*m : n->neighbors){
            mp[n->val]->neighbors.push_back(mp[m->val]);
            makelink(m);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        mp = map<int,Node*>();
        clone(node);
        int n = mp.size();
        vis = vector<bool>(n+1,false);
        makelink(node);
        return mp[node->val];
    }
};
// @lc code=end

