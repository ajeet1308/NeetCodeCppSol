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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Brute force way
        string palindromicString = "";
        ListNode *curr = head;
        while(curr) {
            palindromicString += to_string(curr->val);
            curr = curr->next;
        }
        string reverseString = palindromicString;
        reverse(palindromicString.begin(), palindromicString.end());
        return palindromicString == reverseString;
    }
};

/***************************************************************************************************/

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
    ListNode* hareAndToritoise(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseSecondHalf(ListNode* m2) {
        ListNode *curr = m2, *prev = m2, *next = m2->next;
        prev->next = NULL;
        while(next) {
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }
    bool isPalindrome(ListNode* head) {
        // Optimal way TC: O(N), SC:O(1)
        // Base cases
        if (head == nullptr || head->next == nullptr) return true;
        // Finding middle element of linked list using tortoise and hare algorithm
        ListNode *m1 = head, *m2 = hareAndToritoise(head);
        m2 = reverseSecondHalf(m2);
        while(m2) {
            if (m2->val != m1->val) return false;
            m2 = m2->next;
            m1 = m1->next;
        }
        return true;
    }
};