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