/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, val1, val2;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(l1 || l2 || carry){
            if(l1 == nullptr) val1 = 0;
            else{
                val1 = l1->val;
                l1 = l1->next;
            }

            if(l2 == nullptr) val2 = 0;
            else{
                val2 = l2->val;
                l2 = l2->next;
            }

            ListNode* tmp = new ListNode;
            tmp->val = (val1 + val2 + carry) % 10;
            head->next = tmp;
            head = head->next;
            carry = (val1 + val2 + carry) / 10;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};