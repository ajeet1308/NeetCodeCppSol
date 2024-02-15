#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int data) {
            val = data;
            next = nullptr;
            prev = nullptr;
        }
    } *head, *curr;
    MyLinkedList() {
        head = nullptr;
        curr = nullptr;
    }
    
    int get(int index) {
        ListNode *p = head;
        while(p && index--) {
            p = p->next;
        }
        return p ? p->val : -1;
    }
    
    void addAtHead(int val) {
        ListNode *p = new ListNode(val);
        if (head) {
            p->next = head;
            head->prev = p;
        }
        head = p;
        return ;
    }
    
    void addAtTail(int val) {
        ListNode *p = new ListNode(val); // Here 'new' keyword creates a block of memory of size node inside our heap memory and returns its base address in pointer p, which means p is pointing toward this node
        ListNode *last = head, *prev = head;
        while(last) {
            prev = last;
            last = last->next;
        }
        if (prev == nullptr) { // This is first element Be careful
            head = p;
        } else {
            prev->next = p;
            p->prev = last;
        }
        return ;
    }
    
    void addAtIndex(int index, int val) {
        ListNode *p = new ListNode(val);
        ListNode *nthNode = head, *prev = head;
        while(nthNode && index--) {
            prev = nthNode;
            nthNode = nthNode->next;
        }
        if (index > 0) return ;
        if (nthNode == head) { // Case when we are inserting at head
            if (head) {
                p->next = head;
                head->prev = p;
            }
            head = p;
        } else if (nthNode == nullptr && index == 0) { // Case when we are inserting at end
            prev->next = p;
            p->prev = prev;
        } else { // Case when we are inserting in mid
            prev->next = p;
            nthNode->prev = p;
            p->next = nthNode;
            p->prev = prev;
        }
        return ;
    }
    
    void deleteAtIndex(int index) {
        ListNode *p = head, *prev = head;
        while(p->next && index--) {
            prev = p;
            p = p->next;
        }
        if (index > 0) return ;
        if (p == head) { // Case when we are deleting first element
            head = head->next;
        } else if (p->next == nullptr) { // Case when we are deleting the last element
            prev->next = nullptr;
        } else {
            ListNode *temp = p->next;
            prev->next = temp;
            temp->prev = prev;
        }
        delete p;
        return ;
    }
};



/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
