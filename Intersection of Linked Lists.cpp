/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A||!B) return NULL;
    ListNode* t1 = A;
    ListNode* t2 = B;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t2) return t1;
        if(t1==NULL) t1=B;
        if(t2==NULL) t2=A;
        
    
}
return t1;
}
