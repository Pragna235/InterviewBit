/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* t1 = A;
    ListNode* t2 = B;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->val < t2->val){
            temp->next = t1;
            temp = t1;
            t1=t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2=t2->next;
        }
    }
    if(t1) temp->next =t1;
    else temp->next =t2;
    return dummyNode->next;
}
