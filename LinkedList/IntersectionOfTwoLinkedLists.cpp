/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // BruteForce way TC:O(n*m) , SC:O(1)
        ListNode *currA = headA;
        while(currA) {
            ListNode *currB = headB;
            while(currB) {
                if (currA == currB) return currA;
                currB = currB->next;
            }
            currA = currA->next;
        }
        return nullptr;
    }
};