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
    void subtree(TreeNode* node, string& ans){
        ans += to_string(node->val);
        if(node->left) {
            ans += '(';
            subtree(node->left, ans);
            ans += ')';
        }
        if(node->right){
            if(node->left == nullptr) ans += "()";
            ans += '(';
            subtree(node->right, ans);
            ans += ')';
        }
    }

    string tree2str(TreeNode* root) {
        if(root == nullptr) return "";
        string ans = "";
        subtree(root, ans);
        return ans;
    }
};