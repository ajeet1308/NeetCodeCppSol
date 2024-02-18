#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct ListNode{
        int val;
        int key;
        ListNode *prev;
        ListNode *next;
        ListNode(int _key, int _val){
            val = _val;
            key = _key;
            prev = nullptr;
            next = nullptr;
        }
    } *head, *tail;
    int maxCapacity;
    unordered_map<int, ListNode*>hashMap; // storing [key -> ListNode*] pairs

    LRUCache(int capacity) {
        head = new ListNode({-1, -1});
        tail = new ListNode({-1, -1});
        head->next = tail;
        tail->prev = head;
        maxCapacity = capacity;
    }

    void deleteNode(ListNode* &p) {
        int key = p->key;
        p->prev->next = p->next;
        p->next->prev = p->prev;

        hashMap.erase(key); // After deleting we have to make sure to remove key from hashMap

        return;
    }

    void insertingAtFront(int key, int val) {

        // Create a new Node and Insert it at front just after head
        ListNode *q = new ListNode(key, val);
        q->next = head->next;
        q->prev = head;
        head->next->prev = q;
        head->next = q;

        hashMap[key] = q; // Make sure to add key to hashMap once done with insertion of Node
    }
    
    int get(int key) {

        if (hashMap.find(key) == hashMap.end()) {
            return -1; // In this case it is useless to find anything
        }

        ListNode *p = hashMap[key];
        int res = p->val; // This is our answer

        // Delete p from DLL and from hashMap as this node would become recently used node so delete its current instance and add a new same instance on the top
        deleteNode(p);

        // Create a new Node and Insert it at front just after head due to which this node would be listed as recently used Node
        insertingAtFront(p->key, p->val);

        return res;
    }
    
    void put(int key, int value) {
        
        if (hashMap.find(key) != hashMap.end()) { // Either It is already existing key or a new key
            deleteNode(hashMap[key]);
        } else if (hashMap.size() == maxCapacity) {
            // Now the LRU would be the tail element which is least recently used so delete that
            deleteNode(tail->prev);
        }

        // This is must step as in case of put we have to add a new node
        insertingAtFront(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
