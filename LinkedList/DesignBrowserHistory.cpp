#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    struct ListNode {
        struct ListNode* prev;
        string val;
        struct ListNode* next;
        ListNode(string d) {
            val = d;
            next = nullptr;
            prev = nullptr;
        }
    } *curr = nullptr;

    BrowserHistory(string homepage) {
       // Here we do not have to keep track of head as it is doubly linked list
       curr = new ListNode(homepage);
    }
    
    void visit(string url) {
        // Here One thing to Note that as soon as we visit any web page wherever we are
        // right now all the upcoming nodes will get vanished and curr node would now point
        // to newly visited page
        ListNode *p = new ListNode(url);
        p->prev = curr;
        curr->next = p;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps--) {
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next && steps--) {
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
