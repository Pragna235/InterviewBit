/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
int lengthList(listnode* head){
    int cnt=0;
    listnode* temp = head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
listnode* removeNthFromEnd(listnode* head, int B) {
    if(head==NULL) return head;
    int cnt = lengthList(head);
    if(B>=cnt){
        listnode* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    cnt=cnt+1;
    listnode* temp = head;
    listnode* prev= NULL;
    while(temp){
        cnt--;
        if(cnt==B){
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
