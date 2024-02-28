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
    public ListNode mergeKLists(ListNode[] lists) {
        // TC: O(k*log(k)*N) SC:O(k)
        // Base case
        if (lists == null || lists.length == 0) return null;
        
        ListNode dummyHead = new ListNode(-1), tail = dummyHead;
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>() {
            @Override
            public int compare(ListNode l1, ListNode l2) {
                if (l1.val < l2.val) return -1;
                else if (l1.val == l2.val) return 0;
                else return 1;

            }
        });

        for(ListNode node: lists) {
            if (node != null) pq.add(node); // k*log(k)
        }

        while(pq.size() > 0) { // k*log(k)*N
            ListNode p = pq.poll();
            if (p.next != null) pq.add(p.next);
            
            tail.next = p;
            tail = tail.next;
            tail.next = null;
        }

        return dummyHead.next;
    }
}

/***********************************************************************************************************/

class Solution {
    public ListNode mergeTwoLists(ListNode p, ListNode q) {
        ListNode dummyHead = new ListNode(-1), currDummyHead = dummyHead;

        while (p != null && q != null) {
            if (p.val < q.val) {
                currDummyHead.next = p;
                p = p.next;
            } else {
                currDummyHead.next = q;
                q = q.next;
            }
            currDummyHead = currDummyHead.next;
            currDummyHead.next = null;
        }
        if (p != null) currDummyHead.next = p;
        
        if (q != null) currDummyHead.next = q;

        return dummyHead.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        // TC: O(K*K*N) SC:O(1)
        ListNode currDummyHead = lists.length > 0 ? lists[0] : null;
        ArrayList<Integer> arr = new ArrayList<Integer>();

        for(int i = 1; i < lists.length; i++) { // O(K)
            ListNode p = lists[i];
            currDummyHead = mergeTwoLists(currDummyHead,p); // O(N1 + (N1+N2) + (N1+N2+N3+N4)) ~~ O(K*N)
        }

        return currDummyHead;
    }
}
/*******************************************************************************************************/
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        // TC:O(N*K*log(N*K)) SC:O(N*K)
        ArrayList<Integer> arr = new ArrayList<Integer>();

        for(int i = 0; i < lists.length; i++) {
            ListNode curr = lists[i];
            while(curr != null) {
                arr.add(curr.val);
                curr = curr.next;
            }
        }

        Collections.sort(arr);

        ListNode dummyHead = new ListNode(-1), currDummyHead = dummyHead;
        for(int i = 0; i < arr.size(); i++) {
            ListNode p = new ListNode(arr.get(i));
            currDummyHead.next = p;
            currDummyHead = p;
        }

        return dummyHead.next;
    }
}
