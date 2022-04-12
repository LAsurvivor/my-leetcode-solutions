/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();

            if((node->val <= p->val && node->val >= q->val) || 
                (node->val >= p->val && node->val <= q->val)) return node;
            
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
        }
        return nullptr;
    }
};