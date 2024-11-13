/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
int Solution::lPalin(ListNode* A) {
    if(A == NULL || A->next==NULL) return 1;
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* newHead = reverse(slow->next);
    ListNode* first = A;
    ListNode* second = newHead;
    while(second!=NULL){
        if(first->val != second->val){
            reverse(newHead);
            return 0;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newHead);
    return 1;
}
