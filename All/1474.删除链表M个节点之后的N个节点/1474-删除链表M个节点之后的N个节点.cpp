/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *left = head, *right = head;

        while (right) {
            for (int i = 1; i < m; ++i) {
                if (left == nullptr) break;
                left = left->next;
            }
            if (left == nullptr) break;
            right = left;
            for (int i = 0; i <= n; ++i) {
                if (right == nullptr) {
                    left->next = nullptr;
                    break;
                }
                right = right->next;
            }
            left->next = right;
            left = left->next;
        }
        return head;
    }
};