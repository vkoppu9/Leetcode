/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **cur = &head, *temp;
        while(*cur != nullptr) {
            if((*cur)->val == val) {
                temp = *cur; 
                *cur = (*cur)->next;
                delete temp;
            }
            else
                cur = &(*cur)->next;
        }
        return head;
    }
};
/*
void removeHelper(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->val == val)
    {
        head = head->next;
    }
    else
    {
        removeHelper(head->next, val);
    }
}

ListNode *removeElements(ListNode *head, int val)
{
    removeHelper(head, val);

    return head;
}
*/