// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string result = "";

public:
    string smallestFromLeaf(TreeNode *root)
    {
        DFS(root, "");
        return result;
    }

    void DFS(TreeNode *root, string currentWord)
    {
        if (root == nullptr)
            return;

        currentWord = (char)(root->val + 'a') + currentWord;

        if (root->left == nullptr && root->right == nullptr)
            result = (result == "") ? currentWord : min(result, currentWord);

        DFS(root->left, currentWord);
        DFS(root->right, currentWord);
    }
};