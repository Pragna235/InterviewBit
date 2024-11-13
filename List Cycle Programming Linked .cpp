/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;

    // Step 1: Detect if there is a cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        // Cycle detected
        if (slow == fast) {
            ListNode* entry = A;

            // Step 2: Find the entry point of the cycle
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    // No cycle found
    return NULL;
}
