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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        while(root1){
            st1.push(root1);
            root1 = root1->left;
        }
        while(root2){
            st2.push(root2);
            root2 = root2->left;
        }
        vector<int> ans;

        while(!st1.empty() || !st2.empty()){
            int val1 = st1.empty() ? INT_MAX : st1.top()->val;
            int val2 = st2.empty() ? INT_MAX : st2.top()->val;

            if(val1 < val2){
                TreeNode* tmp = st1.top();
                st1.pop();
                ans.push_back(tmp->val);

                if(tmp->right){
                    tmp = tmp->right;
                    while(tmp){
                        st1.push(tmp);
                        tmp = tmp->left;
                    }
                }
            } else {
                TreeNode* tmp = st2.top();
                st2.pop();
                ans.push_back(tmp->val);

                if(tmp->right){
                    tmp = tmp->right;
                    while(tmp){
                        st2.push(tmp);
                        tmp = tmp->left;
                    }
                }
            }
        }
        return ans;
    }
};