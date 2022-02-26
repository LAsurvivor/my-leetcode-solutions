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
    ListNode* reverseList(ListNode* head) {
        ListNode* left = head;
        if(left == nullptr) return head;
        ListNode* mid = left->next;
        if(mid == nullptr) return head;
        ListNode* right = mid->next;

        left->next = nullptr;
        while(right){
            mid->next = left;

            left = mid;
            mid = right;
            right = right->next;
        }
        mid->next = left;
        return mid;
    }
};