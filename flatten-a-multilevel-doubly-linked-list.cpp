/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* h = head; h != NULL; h = h->next)
        {
            if (h->child)
            {
                Node* next = h->next; // next pointing to next
                h->next = h->child; // replace the next first
                h->next->prev = h; // vice versa change childs prev
                h->child = NULL; // make child null
                Node* p = h->next; // p points to child starting
                while (p->next) // keep moving to the last forget about its children
                    p = p->next; 
                p->next = next; // join the end of child to parent's next
                if (next) // join child's end prev to parent's next
                    next->prev = p;
            }
        }
        return head;
    }
};