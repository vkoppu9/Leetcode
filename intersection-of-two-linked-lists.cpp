class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int countA = 0, countB = 0;
        ListNode *A = headA, *B = headB;
        while(headA != NULL){
            countA++;
            headA = headA->next;
        }
        while(headB != NULL){
            countB++;
            headB = headB->next;
        }
        headA = A;
        headB = B;
        while(headA != NULL && headB != NULL) {
            if(countA == countB) {
                if(headA == headB) {
                    return headA;
                }
                headB = headB->next;
                countB--;
                headA = headA->next;
                countA--;
            } else if(countB > countA) {
                countB--;
                headB = headB->next;
            } else {
                countA--;
                headA = headA->next;
            }
        }
        return NULL;
    }
};