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
    // InsertionSort Algorithm
    /*
        TC: O(N^2) SC:O(1)
        InsertionSort(arr[]) {
            for i = 1 to arr.length
                key = arr[i]

                j = i-1;
                while j >= 0 and arr[j] > key
                    arr[j+1] = arr[j]
                    j = j-1
                
                arr[j+1] = key
        }
     */
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode key = head.next, keyPrev = head;

        while(key != null) {
            ListNode start = head, startPrev = null;
            while(start != key && start.val <= key.val) {
                startPrev = start;
                start = start.next;
            }
            
            if (key == start) {
                keyPrev = key;
                key = key.next;
                continue;
            }
            keyPrev.next = key.next; // Removed key from original linkage
            key.next = start;

            if (start == head){ // This means we have add element at first position
                head = key;
            } else {
                startPrev.next = key;
            }

            key = keyPrev.next;
        }

        return head;

    }
}
/********************************************************************************************************/
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
