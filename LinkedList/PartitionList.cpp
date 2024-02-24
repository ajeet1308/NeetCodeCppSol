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
    ListNode* partition(ListNode* head, int x) {
        // TC: O(N) SC:O(1)
        // Fundamental Principle is to create separate pointer to separate lists
        if (!head || !head->next) return head; // Base case
        
        ListNode *head1 = new ListNode(-1), *dummyHead1 = head1;
        ListNode *head2 = new ListNode(-1), *dummyHead2 = head2;
        ListNode *curr = head;

        while(curr) {
            if (curr->val < x) {
                head1->next = curr;
                head1 = head1->next;
                curr = curr->next;
                head1->next = nullptr;
            } else {
                head2->next = curr;
                head2 = head2->next;
                curr = curr->next;
                head2->next = nullptr;
            }
        }
        head1->next = dummyHead2->next;

        return dummyHead1->next;
    }
};
