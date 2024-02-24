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
    ListNode* reverseLL(ListNode* head, ListNode* stopNode) {
        if (!head || !head->next || head == stopNode) return head;

        ListNode *rest = reverseLL(head->next, stopNode);

        head->next->next = head;
        head->next = nullptr;

        return rest;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base case
        if (!head || !head->next || left == right) return head;

        ListNode *currStart = head, *currStartPrev = nullptr;
        ListNode *currEnd = head, *currEndNext = head;

        while(left-- > 1) {
            currStartPrev = currStart;
            currStart = currStart->next;
        }

        while(right-- > 1) {
            currEnd = currEnd->next;
        }

        currEndNext = currEnd->next;

        ListNode *rest = reverseLL(currStart, currEnd);
        if (currStartPrev) {
            currStartPrev->next = rest;
        } else {
            head = rest; // This is the case when left one is at head
        }
        while(rest->next) rest = rest->next;
        rest->next = currEndNext;

        return head;
    }
};
