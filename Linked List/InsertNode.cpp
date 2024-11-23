class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head == NULL)
        {
            head = new Node(x);
            return head;
        }
        
        Node* a = head;
        while(a -> next != NULL)
        {
            a = a -> next;
        }
        a -> next = new Node(x);
        
        return head;
    }
};