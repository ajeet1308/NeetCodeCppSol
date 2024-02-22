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
    ListNode* swapPairs(ListNode* head) {
        // TC: O(n), SC:O(1)
        // Edge Case
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = head, *curr = head->next, *back = nullptr;

        ListNode *actualStart = head->next;

        while(curr) {
            // a->b->c->d
            // Iter(1) : prev -> a, curr -> b (After this operation b->a->c->d)
            // Iter(2) : back -> a, prev -> c, curr -> d (After this operation b->a->d->c)
            // Here back plays important role in linking two swap pairs in between movement
            prev->next = curr->next;
            curr->next = prev;
            if (back) back->next = curr;

            back = prev;
            prev = prev->next;
            curr = prev ? prev->next : prev;
        }

        return actualStart;
    }
};

/*************************************************************************************************/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // TC:O(n), SC:O(n) => Recursion Stack
        // Edge Case
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *rest = swapPairs(head->next->next);
        ListNode *start = head->next;
        head->next->next = head;
        head->next = rest;

        return start;
    }
};
