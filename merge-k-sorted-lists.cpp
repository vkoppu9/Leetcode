/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        int n = lists.size(), min = INT_MAX, idx = 0;
        while (true) {
            for (int i = 0; i < n; i++) {
                if (lists[i] && lists[i]->val < min) { // of the lists finding the minimum
                    min = lists[i]->val; // keep value 
                    idx = i; // and index
                }
            }
            if (min == INT_MAX) { // no min found
                break;
            }
            cur->next = lists[idx]; // point to the min list
            cur = cur->next; // move curr list
            lists[idx] = lists[idx]->next; // move the list from where min is picked up
            min = INT_MAX; // replace min 
        }
        return dummy->next; // the head
    }
};