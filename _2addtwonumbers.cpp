/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *head = new ListNode(0);
        ListNode *t1 = l1, *t2 = l2, *t3 = head;
        int v1, v2, s;
        while(t1||t2){
            if(t1){
                v1 = t1->val;
                t1 = t1->next;
            }
            else
                v1 = 0;
            if(t2){
                v2 = t2->val;
                t2 = t2->next;
            }
            else
                v2 = 0;
            s = v1 + v2 + carry;
            carry = s / 10;
            s %= 10;
            t3->next = new ListNode(s);
            t3 = t3->next;
        }
        if(carry)
            t3->next = new ListNode(1);
        return head->next;
    }
};