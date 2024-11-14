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
ListNode* Solution::rotateRight(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* tail = head;
    int len = 1;
    if(!head || !head->next) return head;
    while(tail->next){
        tail=tail->next;
        len++;
    }
    if(k%len==0) return head;
    k = k%len;
    tail->next = head;
    ListNode* kthNode = getKthNode(temp, len-k);
    head = kthNode->next;
    kthNode->next = NULL;
    return head;
}
