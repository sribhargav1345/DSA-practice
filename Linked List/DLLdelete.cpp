class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        int ct = 1;
        if(x == 1)
        {
            Node* p = head;
            head = head -> next;
            p -> next = NULL;
            head -> prev = NULL;
            
            return head;
        }
        
        Node* a = head;
        while(a != NULL)
        {
            if(ct == x-1){
                break;
            }
            ct++;
            a = a-> next;
        }
        
        Node* op = a -> next -> next;
        a -> next -> next = NULL;
        if(op != NULL) op -> prev = a;
        a -> next = op;
        
        return head;
    }
};