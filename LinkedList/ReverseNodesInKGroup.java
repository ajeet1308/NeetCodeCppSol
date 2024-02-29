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
    public ListNode reverseSingleGroupLastNode(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode curr = head, next = head.next, prev = null;

        while(curr != null) {
            curr.next = prev;
            
            prev = curr;
            curr = next;
            if (next != null) next = next.next;
        }

        return head; // returns the last node of reverse linked list
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        // TC: O(N + K), SC:O(1)

        // Edge cases
        if (head == null || head.next == null || k == 1) return head;

        ListNode tail = head, start = head, startPrev = null;
        ListNode dummyHead = head;
        int nodeCnt = 1;

        while(tail != null) { // O(N)
            ListNode tailNext = tail.next;
            if (nodeCnt%k == 0)  { // Occasionally O(K)
                if (dummyHead == head) dummyHead = tail; // This will be assigned first and last time which will be starting point of our whole new linked list
                
                tail.next = null;
                ListNode lastNodeOfReversedLL = reverseSingleGroupLastNode(start); // O(K)
                
                lastNodeOfReversedLL.next = tailNext; // This will help us during linking one reversed & unreversed portion, i.e [1,2,3,4] [5]
                if (startPrev != null) startPrev.next = tail; // This is just done to point our previous reversed LL to upfront reversed LL position

                startPrev = lastNodeOfReversedLL;
                start = tailNext;
            }
            nodeCnt++;
            tail = tailNext;
        }

        return dummyHead;
    }
}
