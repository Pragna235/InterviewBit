/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* temp1 = A;
    ListNode* temp2=B;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* curr = dummyNode;
    int carry = 0;
    
    while(temp1!=NULL || temp2!=NULL){
        int sum = carry;
        if(temp1) sum+=temp1->val;
        if(temp2) sum+=temp2->val;
        ListNode* newNode = new ListNode(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr=curr->next;
        
        if(temp1) temp1=temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}
