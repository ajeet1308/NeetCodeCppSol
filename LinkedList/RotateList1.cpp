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
    int findLengthOfLinkedList(ListNode* head) {
        ListNode *curr = head;
        int cnt = 0;
        while(curr) {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        // Base cases
        if (!head || !head->next || k == 0) return head;
        
        int n = findLengthOfLinkedList(head);
        k = k%n; // for not repeating our operations again and again
        if (k == 0) return head;

        ListNode *curr = head, *last = head;
        int i = 0;

        while(last->next) {
            if (i++ == (n-k-1)) curr = last;
            last = last->next;
        }

        last->next = head;
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};
