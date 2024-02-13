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
    ListNode* addTwoList(ListNode* p, ListNode* q) {
        ListNode *head = nullptr, *originalHead = nullptr;
        int rem = 0, quo = 0, sum = 0;
        while(p || q) {
            sum = (p ? p->val : 0) + (q ? q->val : 0) + quo;
            rem = sum%10;
            quo = sum/10;
            if (head) {
                head->next = new ListNode(rem);
                head = head->next;
            } else {
                head = new ListNode(rem);
                originalHead = head;
            }
            if (p) p = p->next;
            if (q) q = q->next;
        }

        if (quo > 0) {
            if (head) {
                head->next = new ListNode(quo);
                head = head->next;
            } else {
                head = new ListNode(quo);
                originalHead = head;
            }
        }

        return originalHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // TC: O(n), SC: O(min(l1,l2))
        // Since the linked list we have is already reversed of digit so we do not have to reverse anything just return our answer
        // Now let's both of them one by one
        ListNode *AddList = addTwoList(l1, l2);

        return AddList;
    }
};
