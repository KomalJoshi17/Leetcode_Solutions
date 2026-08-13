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

class Solution {
public:
    TreeNode* prev=nullptr;

    void helper(TreeNode* root){
        if(root==nullptr) return;

        TreeNode* leftChild=root->left;
        TreeNode* rightChild=root->right;

        if(prev!=nullptr){
            prev->left=nullptr;
            prev->right=root;
        }

        prev=root;

        helper(leftChild);
        helper(rightChild);
    }

    void flatten(TreeNode* root) {
        prev=nullptr;
        helper(root);
    }
};