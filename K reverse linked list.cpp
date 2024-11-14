/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* getKthNode(ListNode* temp, int k){
    k-=1;
    while(temp && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
ListNode* reverse(ListNode* head){
    if(!head || !head->next){
        return head;
    }
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
ListNode* Solution::reverseList(ListNode* head, int B) {
    ListNode* temp = head;
    ListNode* prevNode = NULL;
    while(temp){
        ListNode* kthNode = getKthNode(temp, B);
        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;
        
        if(kthNode==NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        
        kthNode = reverse(temp);
        if(temp==head){
            head=kthNode;
        }
        else{
            prevNode->next = kthNode;
        }
        
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
