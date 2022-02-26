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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int ans = 0, base = 0;

        while(!q.empty()){
            auto [node, step] = q.front();
            q.pop();

            if(step > base){
                ans = node->val;
                base++;
            } else ans += node->val;

            if(node->left) q.push(make_pair(node->left, step+1));
            if(node->right) q.push(make_pair(node->right, step+1));
        }
        return ans;
    }
};