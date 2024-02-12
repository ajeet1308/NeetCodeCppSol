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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; // base case
        ListNode *rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest; // here rest will be pointing to last starting node
    };
    void swapFunc(ListNode* head, ListNode* middleNode) {
        ListNode *q = head;
        while (middleNode && middleNode->next) {
            ListNode *actualFront = q->next, *requiredFront = middleNode->next;
            q->next = requiredFront; // (1)
            middleNode->next = requiredFront->next; // (2)
            requiredFront->next = actualFront; // (3)
            // (1),(2),(3) is just to regulate the links changing
            q = actualFront; // this step would make sure we forward with our starting pointer to repeat above step again
        }
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        // Using tortoise and hare algorithm to find middle node of linked list
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rest = reverse(slow->next);
        slow->next = rest;
        ListNode *temp = head;
        // while(head) {
        //     cout<<head->val<<" ";
        //     head = head->next;
        // }
        swapFunc(head, slow);
        return ;
    }
};
/*****************************************************************************************/

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>ptrStore;
        ListNode *curr = head;
        int n = 0;
        while(curr) {
            ptrStore.push(curr);
            curr = curr->next;
            n++;
        }
        curr = head;
        while (ptrStore.size()>(n/2 + 1)) {
            ListNode *actualFront = curr->next, *requiredFront = ptrStore.top();
            curr->next = requiredFront;
            requiredFront->next = actualFront;
            curr = actualFront;
            ptrStore.pop();
        }
        curr = ptrStore.top();
        curr->next = nullptr;
        return ;
    }
};
