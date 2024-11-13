/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* temp = A;
    while(temp && temp->next){
        if(temp->val == temp->next->val){
            ListNode* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else{
            temp = temp->next;
        }
    }
    return A;
}
