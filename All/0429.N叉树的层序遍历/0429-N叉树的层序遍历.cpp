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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};

        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        int curr = 0;

        vector<vector<int>> ans(1);

        while (!q.empty()) {
            auto [node, layer] = q.front();
            q.pop();

            if (curr == layer) {
                ans[curr].push_back(node->val);
            } else {
                curr = layer;
                vector<int> tmp;
                tmp.push_back(node->val);
                ans.push_back(tmp);
            }

            for (auto& child : node->children) {
                q.push(make_pair(child, layer + 1));
            }
        }
        return ans;
    }
};