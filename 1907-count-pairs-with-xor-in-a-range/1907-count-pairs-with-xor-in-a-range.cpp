const int LEVEL = 16; // 1 <= nums[i] <= 20000

struct TrieNode { 
    TrieNode *child[2];  // Stores binary represention of numbers  
    int cnt; // Stores count of elements present in a node
    TrieNode() { 
        child[0] = child[1] = NULL; 
        cnt = 0; 
    } 
}; 
 
 
// Function to insert a number into Trie 
void insertTrie(TrieNode *root, int n) { 
    // Traverse binary representation of X 
    for (int i = LEVEL; i >= 0; i--) { 
        // Stores ith bit of N 
        bool x = (n) & (1 << i); 
        // Check if an element already present in Trie having ith bit x
        if(!root->child[x]) { 
            // Create a new node of Trie. 
            root->child[x] = new TrieNode(); 
        } 
        // Update count of elements whose ith bit is x 
        root->child[x]->cnt += 1; 
        
        //Go to next level
        root = root->child[x]; 
    } 
} 


class Solution {
private:
    // Count elements in Trie whose XOR with N less than K 
    int countSmallerPairs(TrieNode * root,  int N, int K) { 
        // Stores count of elements whose XOR with N less than K 
        int cntPairs = 0; 
        // Traverse binary representation of N and K in Trie 
        for (int i = LEVEL; i >= 0 && root; i--) {                 
            bool x = N & (1 << i); // Stores ith bit of N 
            bool y = K & (1 << i); // Stores ith bit of K 

            // If the ith bit of K is 0 
            if (y == 0 ) { 
                // find the number which bit is same as N
                // so that they can be xored to ZERO
                root = root->child[x]; 
                continue;
            } 
            // If the ith bit of K is 1 
            // If an element already present in Trie having ith bit (x)
            if(root->child[x]) {
                // find the number which bit is same as N
                // so that they can be xored to ZERO. so it would be smaller than K
                cntPairs  += root->child[x]->cnt; 
            }
            //go to another way for next bit count
            root = root->child[1 - x]; 
        } 
        return cntPairs; 
    } 
public:
    int countPairs(vector<int>& nums, int low, int high) {
        
        TrieNode* root = new TrieNode();
        
        int cnt = 0;
        for (auto& num : nums) {
            cnt += countSmallerPairs(root, num, high + 1) - countSmallerPairs(root, num, low);
            insertTrie(root, num);
        }
        
        
        return cnt;
    }
};