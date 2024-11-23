class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* a = head;
        Node* p = head;
        
        int ct = 1;
        while(a != NULL)
        {
            if(ct == pos+1){
                break;
            }
            ct++;
            a = a -> next;
        }
        
        Node* b = new Node(data);
        b -> next = a -> next;
        if(a -> next != NULL) a -> next -> prev = b;
        a -> next = b;
        b -> prev = a;
        
        return p;
    }
};