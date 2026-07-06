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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }

        int root=preorder[0];
        TreeNode* node=new TreeNode(root);

        int idx=0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root){
                idx=i;
                break;
            }
        }

        vector<int>leftinorder(inorder.begin(),inorder.begin()+idx);
        vector<int>rightinorder(inorder.begin()+idx+1,inorder.end());

        vector<int>leftpreorder(preorder.begin()+1,preorder.begin()+leftinorder.size()+1);
        vector<int>rightpreorder(preorder.begin()+leftinorder.size()+1,preorder.end());

        if(!leftinorder.empty() && !leftpreorder.empty()){
            node->left=buildTree(leftpreorder,leftinorder);
        }else{
            node->left=nullptr;
        }

        if(!rightinorder.empty() && !rightpreorder.empty()){
            node->right=buildTree(rightpreorder,rightinorder);
        }else{
            node->right=nullptr;
        }

        return node;
    }
};