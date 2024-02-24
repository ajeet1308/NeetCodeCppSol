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

    ListNode* mergeSortedList(ListNode* p, ListNode* q) {
        
        ListNode *dummyHead = new ListNode(0);

        ListNode *curr = dummyHead;

        while(p && q) {

            if (p->val < q->val) {
                curr->next = p;
                p = p->next;
            } else {
                curr->next = q;
                q = q->next;
            }
            
            curr = curr->next;
            curr->next = nullptr;
        }

        // Now traverse remaining element of p and q
        if (p) curr->next = p; // Since from here onWard curr would continue on p's path
        
        if (q) curr->next = q; // Since from here onWard curr would continue on q's path

        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        // TC: O(NlogN), SC:O(1)
        // Base condition
        if (head == nullptr || head->next == nullptr) return head;

        // Find middle element using tortoise and hare algorithm
        ListNode *slow = head, *fast = head->next; // Here slight modification is done for fast pointer for getting right answer in even length linked list
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // here middle node would be pointed by slow pointer
        ListNode *left = slow, *right = slow->next;
        left->next = nullptr; // It's required to break the bonding b/w left and right list

        // Splitting list until we have each and every single node separated
        ListNode* l1 = sortList(head); // Represents sorted List of first half
        ListNode* l2 = sortList(right); // Represents sorted List of second half

        // Merge two sorted List
        return mergeSortedList(l1, l2);
    }
};
/****************************************************************************************************************/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // TC: O(N^2) SC: O(1)
        // Recursive Solution
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *rest = sortList(head->next);
        ListNode *temp = rest, *prevTemp = head;
        
        while(temp && temp->val <= head->val) {
            prevTemp = temp;
            temp = temp->next;
        }

        if (temp == rest) {
            head->next = rest;
            return head;
        }

        prevTemp->next = head;
        head->next = temp;

        return rest;
    }
};

/******************************************************************************************/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // TC: O(NlogN), SC:O(N)
        if (head == nullptr || head->next == nullptr) return head;

        vector<int>v;
        ListNode *temp = head;
        while(temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        temp = head;
        int i = 0;
        while(temp) {
            temp->val = v[i++];
            temp = temp->next;
        }

        return head;
    }
};
