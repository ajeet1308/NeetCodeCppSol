/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        // TC: O(N^2), SC:O(N)
        if (head == null || head.next == null) return head;

        ListNode rest = insertionSortList(head.next);

        ListNode curr = rest, currPrev = null;
        while(curr != null && curr.val <= head.val) {
            currPrev = curr;
            curr = curr.next;
        }

        head.next = curr;
        if (curr == rest) { // We are going to insert at first position
            rest = head;
        } else {
            currPrev.next = head;
        }

        return rest;
    }
}
