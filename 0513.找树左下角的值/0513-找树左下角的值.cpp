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
using pti = pair<TreeNode*, int>;
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pti> q;
        q.push({root, 1});
        int depth = 1, ans = root->val;

        while(!q.empty()){
            auto [node, layer] = q.front();
            q.pop();
            if(layer > depth){
                depth = layer;
                ans = node->val;
            }

            if(node->left != nullptr) q.push({node->left, layer+1});
            if(node->right != nullptr) q.push({node->right, layer+1});
        }
        return ans;
    }
};