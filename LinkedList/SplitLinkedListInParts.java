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
    public int findLLLength(ListNode head) {
        int n = 0;
        ListNode curr = head;
        while(curr != null) {
            n++;
            curr = curr.next;
        }
        return n;
    }
    public ListNode[] splitListToParts(ListNode head, int k) {
        // TC: O(N), SC:O(1)
        ListNode[] v = new ListNode[k];

        int i = 0, j = 0;

        if (head == null || head.next == null || k == 1) {
            v[j] = head;
            return v;
        }

        int n = findLLLength(head);
        int rem = n%k, llSizes = n/k;

        ListNode curr = head, storeStart = head;
        while(curr != null) {
            if (i++ == (rem > 0 ? 1 : 0) + llSizes - 1) {
                v[j++] = storeStart;
                storeStart = curr.next;
                curr.next = null;
                rem--;
                i = 0;
            }
            curr = curr.next != null ? curr.next : storeStart;
        }

        return v;
    }
}
