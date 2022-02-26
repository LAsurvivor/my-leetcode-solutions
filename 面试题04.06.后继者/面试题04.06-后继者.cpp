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
    void search(TreeNode* root, vector<TreeNode*>& lst){
        if(root->left) search(root->left, lst);
        lst.push_back(root);
        if(root->right) search(root->right, lst);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> lst;
        search(root, lst);
        for(int i = 0; i < lst.size(); i++){
            if(lst[i] == p){
                if(i == lst.size() - 1) return nullptr;
                else return lst[i+1];
            }
        }
        return nullptr;
    }
};
/*

*/