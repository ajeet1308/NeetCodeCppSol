/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    /**
        The algorithm is composed of the follow three steps which are also 3 iteration rounds.

        1. Iterate the original list and duplicate each node. The duplicate of each node follows its original immediately.
        2. Iterate the new list and assign the random pointer for each duplicated node.
        3. Restore the original list and extract the duplicated nodes. 
    */
    public Node copyRandomList(Node head) {
        // Base case
        if (head == null) return head;
        Node curr = head, currNext = null;

        // Step 1
        while(curr != null) {
            currNext = curr.next;
            Node p = new Node(curr.val);
            curr.next = p;
            p.next = currNext;
            curr = currNext;
        }

        // Step2
        curr = head;
        while(curr != null) {
            curr.next.random = curr.random != null ? curr.random.next : null;
            curr = curr.next.next;
        }

        // Step3 
        Node dummyHead = new Node(-1), dummyCurr = dummyHead;

        curr = head;
        while(curr != null) {
            dummyCurr.next = curr.next;
            dummyCurr = curr.next;

            curr.next = curr.next.next;
            curr = curr.next;
        }

        return dummyHead.next;

    }
}

/**************************************************************************************************************/

class Solution {
    
    public Node copyRandomList(Node head) {
        // TC: O(N), SC:O(N)
        // Base case
        if (head == null) return head;

        HashMap<Node, Node> hashMap = new HashMap<>();
        // Above hashMap would map both the nodes old and new nodes copy with each other

        Node curr = head;
        while(curr != null) {
            hashMap.put(curr, new Node(curr.val));
            curr = curr.next;
        }

        curr = head;
        while(curr != null) {
            hashMap.get(curr).next = hashMap.get(curr.next);
            hashMap.get(curr).random = hashMap.get(curr.random);
            curr = curr.next;
        }

        return hashMap.get(head);

    }
}
