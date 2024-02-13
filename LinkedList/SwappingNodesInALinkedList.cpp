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

    void swapListVal(ListNode* &p, ListNode* &q) {
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        return ;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        // TC: O(n), SC: O(1)
        // let n be total no of nodes in linked list
        // Here we need to find kth and (n-k)th node from beginning and swap them
        ListNode *slow = head, *fast = head;

        while(k-- > 1) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *kthNodeFromHead = slow; // --> This points to kth node from beginning

        slow = head;
        while(fast->next) {
            slow = slow->next; // This will travel remaining (n-k) nodes
            fast = fast->next; // This will travel remaining (n-k) nodes
        }

        ListNode *kthNodeFromEnd = slow; // --> This points to kth node from End
        
        swapListVal(kthNodeFromHead, kthNodeFromEnd);
        
        return head;
    }
};