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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode *p = list1 , *q = list2, *head = new ListNode(), *final;
        final = head;
        while(p && q) {
            if (p->val < q->val) {
                head->next = new ListNode(p->val);
                p = p->next;
            } else {
                head->next = new ListNode(q->val);
                q = q->next;
            }
            head = head->next;
        }
        while (p) {
            head->next = new ListNode(p->val);
            p = p->next;
            head = head->next;
        }
        while (q) {
            head->next = new ListNode(q->val);
            q = q->next;
            head = head->next;
        }
        return final->next;
    }
};