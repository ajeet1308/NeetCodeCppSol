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
    ListNode* tortoiseAndHare(ListNode* head) {
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    int findMaxPairSum(ListNode* curr1, ListNode* curr2) {
        int maxSum = INT_MIN;
        while(curr1 && curr2) {
            maxSum = max(maxSum, curr1->val + curr2->val);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return maxSum;
    }
    int pairSum(ListNode* head) {
        // Best Optimal Sol TC: O(n), SC: O(1)
        // Applying tortoise and hare method to find middle element
        ListNode *head1 = head, *middlePrev = tortoiseAndHare(head);

        // Reversing second half of linked list
        ListNode *rest = reverse(middlePrev->next); // reversing second half of linked list
        middlePrev->next = rest; // Linking first part with second reversed part

        // Finding our solution
        int finalResult = findMaxPairSum(head, rest);

        // Recovering original form of linked list
        rest = reverse(middlePrev->next);
        middlePrev->next = rest;


        return finalResult;
    }
};