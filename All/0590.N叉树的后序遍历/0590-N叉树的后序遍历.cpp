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
        for(auto& i : node->children){
            search(i, ans);
        }
        ans.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        if(root == nullptr) return {};

        vector<int> ans;

        search(root, ans);

        return ans;
    }
};