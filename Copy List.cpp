/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 void insertCopyInBetween(RandomListNode* head){
    RandomListNode* temp = head;
    while(temp != NULL){
        
        // Create a new node with the same data
        RandomListNode* copy = new RandomListNode(temp->label);  
        
        // Point the copy's next to
        // the original node's next
        copy->next = temp->next;  
        
        // Point the original
        // node's next to the copy
        temp->next = copy;         

        // Move to the next original node
        temp = temp->next->next;         
    }
}

// Function to connect random
// pointers of the copied nodes
void connectRandomPointers(RandomListNode* head){
    RandomListNode* temp = head;
    while(temp != NULL){
        // Access the copied node
        RandomListNode* copyNode = temp->next;    
        
        // If the original node
        // has a random pointer
        if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copyNode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copyNode->random = NULL;   
        }
        
         // Move to the next original node
        temp = temp->next->next;   
    }
}

// Function to retrieve the
// deep copy of the linked list
RandomListNode* getDeepCopyList(RandomListNode* head){
    RandomListNode* temp = head;
     // Create a dummy node
    RandomListNode* dummyNode = new RandomListNode(-1);   
    // Initialize a result pointer
    RandomListNode* res = dummyNode;             

    while(temp != NULL){
        // Creating a new List by
        // pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
     // Return the deep copy of the
     // list starting from the dummy node
    return dummyNode->next;   
}
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
     if(!head) return nullptr;   
    
    
    insertCopyInBetween(head); 
    
    connectRandomPointers(head);  
    
    return getDeepCopyList(head); 
}
