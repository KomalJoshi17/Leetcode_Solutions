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
    // vector<int>array;
    // vector<int> sorted(TreeNode* root){
    //     if(root==nullptr) return {};
    //     sorted(root->left);
    //     array.push_back(root->val);
    //     sorted(root->right);
    //     return array;
    // }

    // bool isSorted(vector<int> &arr){
    //     for(int i=0;i<arr.size()-1;i++){
    //         if(arr[i]>=arr[i+1]) return false;
    //     }
    //     return true;
    // }

    // bool isValidBST(TreeNode* root) {
    //     vector<int>arr=sorted(root);
    //     return isSorted(arr);
    // }

    bool validate(TreeNode* root,long long min, long long max){
        if(root==nullptr) return true;

        if(root->val <= min || root->val >= max) return false;

        return validate(root->left,min,root->val) && validate(root->right,root->val,max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};