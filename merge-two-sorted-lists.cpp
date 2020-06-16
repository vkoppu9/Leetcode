/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //iterative is faster
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* res = NULL; // this is the new head
        if(l1->val < l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        ListNode* curr = res; // now the pointer to traverse
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val > l2->val)
            {
                curr->next = l2;
                l2 = l2->next;
            }
            else
            {
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        if(l1 != NULL)
            curr->next = l1;
        if(l2 != NULL)
            curr->next = l2;
        return res;
    }
    
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //base cases
        if(l1 == NULL)
           return l2;
        if(l2 == NULL)
            return l1;
        // until traversing 
        if(l1->val < l2->val)
            l1->next = mergeTwoLists(l1->next, l2);
        else
            l2->next = mergeTwoLists(l1, l2->next);
        // returning for the last pair of matching 
        return (l1->val < l2->val) ? l1:l2; // you compare while returning
    }
    */
};