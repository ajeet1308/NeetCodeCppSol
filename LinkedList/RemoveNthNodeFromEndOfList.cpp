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

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
    nullptr is a keyword that can be used at all places where NULL is expected. Like NULL, nullptr is implicitly convertible and comparable to any pointer type. Unlike NULL, it is not implicitly convertible or comparable to integral types
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TC: O(k -> length of linked list), SC: O(1)
        // In this method we are trying covering up principle
        // As we know if say we go till nth node from starting it means their are (k-n) length left
        // This means when fast will reach null to complete (k-n) nodes, since slow is again starting from head,
        // This means as soon as fast reaches nullptr we slow pointer would have travelled (k-n)th node
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(n--) { // O(n)
            slow = slow->next;
            fast = fast->next;
        }
        slow = head; // Resetting it again at starting
        // In below code now since fast will travel k-n nodes, and same would be travelled by slow pointer
        // So this way slow will reach nth node from end that is (k-n)th node from starting
        while(fast) { // O(k-n)
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // Keep an eye on edge cases
        if (slow == head) head = head->next; // here slow = head means we are removing first element
        else prev->next = slow->next;
        delete slow;

        return head;
    }
};

/**********************************************************************************************************/

class Solution {
public:
    int lengthOfLinkedList (ListNode* p) {
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TC: O(n), SC: O(1)
        ListNode *prev = nullptr, *curr = head;
        int len = lengthOfLinkedList(head);

        int i = 0;
        while(i < len-n) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        if (len == n) head = head->next; // edge case
        else prev->next = curr->next;

        delete curr; // always free up memory

        return head;
    }
};
