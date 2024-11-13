/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* z1 = new ListNode(-1);
    ListNode* o1 = new ListNode(-1);
    
    ListNode* zero = z1;
    ListNode* one = o1;
    ListNode* temp = head;
    
    while(temp){
        if(temp->val == 0){
            zero->next = temp;
            zero=temp;
        }
        else{
            one->next = temp;
            one=temp;
        }
        temp=temp->next;
    }
    
    zero->next = o1->next;
    one->next = nullptr;
    return z1->next;
}
