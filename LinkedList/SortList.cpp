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
