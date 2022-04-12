/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void search(Node* node, vector<int>& ans){
        ans.push_back(node->val);
        for(auto& nd : node->children){
            search(nd, ans);
        }
    }

    vector<int> preorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        search(root, ans);
        return ans;
    }
};