/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (B == C) return A; // No need to reverse if B and C are the same

    ListNode* dummy = new ListNode(0); // Create a dummy node to handle edge cases
    dummy->next = A;
    ListNode* prev = dummy;

    // Move prev to the node just before the position B
    for (int i = 1; i < B; i++) {
        prev = prev->next;
    }

    ListNode* start = prev->next; // The first node to be reversed
    ListNode* then = start->next; // The node that will be moved

    // Reverse the sublist from B to C
    for (int i = 0; i < C - B; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy->next;
}
