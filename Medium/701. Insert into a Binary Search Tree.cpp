// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        return insertIntoBST_Helper(root, val);
    }

    TreeNode *insertIntoBST_Helper(TreeNode *root, int val)
    {

        if (root == nullptr)
            return new TreeNode(val);

        else if (root->val > val)
            root->left = insertIntoBST_Helper(root->left, val);

        else
            root->right = insertIntoBST_Helper(root->right, val);

        return root;
    }
};