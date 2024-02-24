class MyCircularQueue {
public:
    struct ListNode{
        int val;
        ListNode *prev, *next;

        ListNode(int data){
            val = data;
            prev = nullptr;
            next = nullptr;
        }
    } *head = nullptr, *last = nullptr;

    int llSize, llMaxSize;
    MyCircularQueue(int k) {
        llSize = 0;
        llMaxSize = k;
    }
    
    bool enQueue(int value) {
        if (llSize + 1 > llMaxSize) return false;

        ListNode *p = new ListNode(value);
        
        if (head == nullptr) { // No Node present
            head = p;
        } else {
            last->next = p;
            p->prev = last;
        }

        last = p; // Update the last pointer
        llSize++; // Increase the size of LL
        return true;
    }
    
    bool deQueue() {
        if (head == nullptr) return false; // No elements present, so can't perform delete operation

        if (head->next == nullptr) { // Single Element Present
            head = nullptr;
            last = nullptr;
        } else {
            head = head->next; // Here Focus in FIFO, first inserted one will be deleted first
        }

        llSize--; // Decrease the size of LL

        return true;
    }
    
    int Front() {
        return head ? head->val : -1;
    }
    
    int Rear() {
        return last ? last->val : -1;
    }
    
    bool isEmpty() {
        return llSize == 0;
    }
    
    bool isFull() {
        return llSize == llMaxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
