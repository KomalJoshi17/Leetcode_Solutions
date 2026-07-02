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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        queue<TreeNode *>q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize=q.size();
            for(int i=0;i<levelSize;i++){
                TreeNode* frontVal=q.front();
                q.pop();

                if(i==levelSize-1) ans.push_back(frontVal->val);

                if(frontVal->left){
                    q.push(frontVal->left);
                }
                if(frontVal->right){
                    q.push(frontVal->right);
                }
            }
        }
        return ans;
    }
};
