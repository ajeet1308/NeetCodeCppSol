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

/*------------------------------------------------------------------------*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // BruteForce way TC:O(n + m) , SC:O(n + m)
        ListNode *currA = headA;
        map<ListNode*, int>hashMap;
        while(currA) {
            hashMap[currA]++;
            currA = currA->next;
        }
        currA = headB;
        while(currA) {
            hashMap[currA]++;
            currA = currA->next;
        }
        for (auto ele : hashMap) {
            if (ele.second > 1) return ele.first;
        }
        return nullptr;
    }
};
/*------------------------------------------------------------------------------*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Best and Optimal way : following tortoise and hare principle TC: O(n+m), SC:O(1)
        ListNode *currA = headA, *currB = headB;
        while(currA != currB) {
            currA = currA ? currA->next : headB;
            currB = currB ? currB->next : headA;
        }
        /*
            Here logic is simple after max two Iteration we would be able to achieve our intersection node either would be nullptr or a node
            For more info Kindly look editorial and dry run you'll get it
        */
        return currA;
    }
};