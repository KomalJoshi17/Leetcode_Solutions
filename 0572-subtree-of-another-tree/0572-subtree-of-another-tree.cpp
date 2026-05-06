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
// class Solution {
// public:
//     // Function to check if two trees are the same
//     bool areSame(TreeNode* r1, TreeNode* r2) {
//         if (!r1 && !r2) return true; // Both are null
//         if (!r1 || !r2) return false; // One is null, the other isn't
//         return (r1->val == r2->val) &&
//                areSame(r1->left, r2->left) &&
//                areSame(r1->right, r2->right);
//     }

//     // DFS traversal of root tree, to find a matching subtree
//     void traverse(TreeNode* r1, TreeNode* r2, bool& ans) {
//         if (!r1) return;
//         if (areSame(r1, r2)) {
//             ans = true;
//             return;
//         }
//         traverse(r1->left, r2, ans);
//         traverse(r1->right, r2, ans);
//     }

//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         bool ans = false;
//         traverse(root, subRoot, ans);
//         return ans;
//     }
// };



class Solution {
public:
    // Check if two trees are identical
    bool isSame(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;             // both null
        if (!r1 || !r2) return false;            // one null
        if (r1->val != r2->val) return false;    // value mismatch
        return isSame(r1->left, r2->left) && isSame(r1->right, r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSame(root, subRoot)) return true;  // match found
        // check in left or right subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};