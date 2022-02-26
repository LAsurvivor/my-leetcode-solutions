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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* dummy = new ListNode(0, head->next);

        int cnt = 1;
        ListNode* tmp = odd;
        while(odd && even){
            if(cnt & 1){
                odd->next = even->next;
                tmp = odd;
                odd = odd->next;
            } else {
                even->next = odd->next;
                even = even->next;
            }
            cnt++;
        }
        if(odd) odd->next = dummy->next;
        else tmp->next = dummy->next;

        return head;
    }
};