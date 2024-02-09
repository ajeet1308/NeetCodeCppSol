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
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = head, *nxt = head->next, *curr = head->next;
        prev->next = NULL;
        while(curr->next){
            nxt = nxt->next;
            curr->next = prev;
            prev = curr; // Keeps taking prev to next position
            curr = nxt; // Keeps taking curr to it origin place without unlinking
        }
        curr->next = prev; // One last time we have to make our curr pointing to previous
        return curr;
    }
};

// prev -> 1
// head -> 2
// temp -> 2
// head.next -> 1
// prev -> 2