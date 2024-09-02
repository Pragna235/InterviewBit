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
 * @Output Integer
 */
int lengthList(listnode *head){
    int cnt=0;
    listnode* temp = head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
int solve(listnode* head, int B) {
    if(head==NULL) return -1;
    
    if(head->next==NULL){
        if(B==0){
            return head->val;
        }
        else{
            return -1;
        }
    }
    
    int n=lengthList(head);
    int mid  = (n/2)+1;
    int cnt=mid;
    listnode* temp = head;
    while(temp){
        cnt--;
        if(cnt==B){
            return temp->val;
        }
        temp=temp->next;
    }
    return -1;
}
