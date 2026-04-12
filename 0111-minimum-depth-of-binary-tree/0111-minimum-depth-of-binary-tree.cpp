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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        } 
        int mindepth=0;
        int depth1=minDepth(root->left);
        int depth2=minDepth(root->right);
        mindepth=min(depth1,depth2);
        if(depth1==0){
            mindepth=depth2;
        }else if(depth2==0){
            mindepth=depth1;
        }
        return 1+mindepth; 
    }
};