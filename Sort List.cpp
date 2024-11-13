/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* left, ListNode* right){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(left!=NULL && right!=NULL){
        if(left->val < right->val){
            temp->next = left;
            temp = left;
            left=left->next;
        }
        else{
            temp->next = right;
            temp=right;
            right=right->next;
        }
    }
    if(left) temp->next = left;
    else temp->next = right;
    return dummyNode->next;
}
ListNode* Solution::sortList(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* middle = findMiddle(A);
    ListNode* left = A;
    ListNode* right = middle->next;
    middle->next =  nullptr;
    
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}
