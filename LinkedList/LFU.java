// TC: O(1), SC:O(N)
class LFUCache {

    class ListNode {
        int key, val, cnt;
        ListNode prev, next;

        public ListNode(int _key, int _val) {
            this.key = _key;
            this.val = _val;
            this.cnt = 1;
            this.prev = null;
            this.next = null;
        }
    }

    class DLList {
        int size; // This would represent size of DLL
        ListNode head, tail;

        // Constructor as have the same name as of it parent class
        public DLList() {
            this.head = new ListNode(-1, -1);
            this.tail = new ListNode(-1, -1);
            head.next = tail;
            tail.prev = head;
            size = 0;
        }

        public void insertNodeAtFront(ListNode p) {
            p.next = head.next;
            p.prev = head;
            head.next.prev = p;
            head.next = p;
            
            size++;
        }

        public void deleteNode(ListNode p) {
            p.prev.next = p.next;
            p.next.prev = p.prev;
            
            size--;
        }
        
    }

    Map<Integer, ListNode>keyNode;
    Map<Integer, DLList>frequencyMap;

    int maxCapacity, heapSize, minFreqIndex;

    public LFUCache(int capacity) {
        this.maxCapacity = capacity;
        this.heapSize = 0;
        this.minFreqIndex = 1;

        this.keyNode = new HashMap<>();
        this.frequencyMap = new HashMap<>();
    }

    public void insertFreqDLLMap(ListNode p) {

        DLList newList = frequencyMap.getOrDefault(p.cnt, new DLList());

        newList.insertNodeAtFront(p);

        frequencyMap.put(p.cnt, newList);
        keyNode.put(p.key, p);

    }

    public void deleteFreqDLLMap(ListNode p) {

        DLList oldList = frequencyMap.get(p.cnt);
        oldList.deleteNode(p);
        
        keyNode.remove(p.key);

        if (p.cnt == minFreqIndex && frequencyMap.get(p.cnt).size == 0) minFreqIndex++;
        // Here p.cnt == minFreqIndex condition verifies whether it is not the case when lets say
        // we have minFreqIndex = 1 and we are deleting an element with count 4 so it is possible that
        // we still have any element at index 1, and due to continuous get call one element freq is increasing which is causing it to tranfer to 2->3->4
    }

    
    public int get(int key) {
        if (!keyNode.containsKey(key)) return -1;

        ListNode p = keyNode.get(key);

        deleteFreqDLLMap(p);

        p.cnt++; // This is done as now count would change of existing p node
        insertFreqDLLMap(p);
    
        return p.val;
    }
    
    public void put(int key, int value) {
        if (maxCapacity == 0) return; // Edge case

        if (keyNode.containsKey(key)) {
            ListNode p = keyNode.get(key);
            p.val = value;
            deleteFreqDLLMap(p);
            p.cnt++; // This is done as now count would change of existing p node
            insertFreqDLLMap(p);
        } else {
            ListNode p = new ListNode(key, value);
            if (keyNode.size() == maxCapacity) {
                // Remove the last node of DLL
                deleteFreqDLLMap(frequencyMap.get(minFreqIndex).tail.prev);
            }
            minFreqIndex = 1; // In this case first element will always be placed at first index
            insertFreqDLLMap(p);
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
