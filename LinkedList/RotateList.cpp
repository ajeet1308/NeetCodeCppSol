#include <bits/stdc++.h>
using namespace std;
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
    ListNode* reverse(ListNode* head, ListNode* stopNode) {
        if (head == stopNode || (head->next == nullptr)) {
            head->next = nullptr;
            return head;
        }

        ListNode *rest = reverse(head->next, stopNode);

        head->next->next = head;
        head->next = nullptr;

        return rest;
    }

    int lengthOfLinkedList(ListNode* head) {
        int n = 0;
        ListNode *curr = head;
        while(curr) { curr = curr->next; n++; }
        return n;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // Simple concept while rotating: reverse(head, kth), reverse(head, n-k), reverse(n)
        // TC: O(n), SC:O(n)

        // Edge Case
        if (head == nullptr || head->next == nullptr) return head;

        int n = lengthOfLinkedList(head);
        k = k%n; // This is done to avoid over rotation as we can rotate the list max n times
        if (k == 0) return head;

        ListNode *curr = head, *currNext;
        for (int i=1; i<n-k; i++) {
            curr = curr->next;
        }
        currNext = curr->next;

        // Reverse first k Nodes
        ListNode *restStart = reverse(head, curr), *restEnd = restStart;
        while (restEnd->next) restEnd = restEnd->next;
        restEnd->next = currNext;
        // At this stage 3->2->1->4->5

        // Reverse last k Nodes
        ListNode *m3 = reverse(currNext, nullptr);
        restEnd->next = m3;
        // At this stage 3->2->1->5->4

        // Reverse whole Linked List
        ListNode *reversedAns = reverse(restStart, nullptr);
        // At this stage 4->5->1->2->3

        return reversedAns;
    }
};
