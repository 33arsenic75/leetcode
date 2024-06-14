struct Node{
    Node* links[2];
    bool containskey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31; i>=0; i--){
            int bit=(num>>i) &1;
            if(!node->containskey(bit)){
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    int getmax(int num){
        Node* node=root;
        int maxnum=0;
        for(int i=31; i>=0; i--){
            int bit=(num>>i) & 1;
            if(node->containskey(1-bit)){
                maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);

        }
        return maxnum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it:nums){
            trie.insert(it);
        }
        int maxnum=0;
        for(auto it:nums){
            maxnum=max(maxnum,trie.getmax(it));
        }
        return maxnum;
    }
};