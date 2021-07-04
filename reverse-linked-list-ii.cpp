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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // check
        if(head == nullptr)
            return head;
        // take a dummy as head might also change
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        int count = 1;
        ListNode *ptr = dummy, *start, *end;
        
        while(ptr && count < m) {
            count++;
            ptr = ptr->next;
        }
        
        start = ptr;
        ptr = ptr->next;
        
        ListNode *prev = ptr, *curr = ptr->next, *nextNode;
        
        while(curr && count < n) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        end = curr;
        start->next->next = end;
        start->next = prev;
        
        return dummy->next;
    }
};