/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
            return {};

        std::vector<pair<TreeNode*, int>> v{{root, 0}};
        std::vector<int> result;
        while (v.size())
        {
            if (v.back().first == nullptr)
            {
                v.pop_back();
                continue;
            }
            
            if (v.back().second == 0)
            {
                v.back().second += 1;
                v.push_back({v.back().first->left, 0});
            }
            else
            {
                result.push_back(v.back().first->val);
                v.back().first = v.back().first->right;
                v.back().second = 0;
            }
        }

        return result;
    }
};