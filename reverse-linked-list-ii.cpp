/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
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
    /*
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
    */


    // Using Stack 

    class Solution {
    public:

        ListNode* reverseBetween(ListNode* head, int left, int right) {

            // No need to reverse if left == right
            if(left == right) 
                return head;

            // hold left to right values in stack 
            stack<int> st;

            // track the left node pointer
            ListNode *prev = nullptr, *thead = head;

            // loop till right and save values in stack from left to right
            // also save the left node pointer
            int i = 1;
            while(thead != nullptr && i <= right) {
                if(i == left)
                    prev = thead;

                if(i >= left && i <= right)
                    st.push(thead->val);

                i++;
                thead = thead->next;
            }

            // loop through left pointer to right and set value from stack top
            int s = st.size();
            for(int j = 0; j < s; j++) {
                prev->val = st.top();
                st.pop();
                prev = prev->next;
            }

            return head;

        }
    };
