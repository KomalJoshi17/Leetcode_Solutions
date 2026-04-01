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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *>q;
        q.push(root);
        int levelNum=0;
        while(!q.empty()){
            int levelSize=q.size();
            vector<int>level;
            for(int i=0;i<levelSize;i++){
                TreeNode* frontVal=q.front();
                level.push_back(frontVal->val);
                q.pop();
                if(frontVal->left){
                    q.push(frontVal->left);
                }
                if(frontVal->right){
                    q.push(frontVal->right);
                }
            }
            if(levelNum%2!=0){
               reverse(level.begin(),level.end()); 
            }
            ans.push_back(level);
            levelNum++;
        }
        return ans;
    }
};