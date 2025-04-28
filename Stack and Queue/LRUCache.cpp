class Node{
public:
    int key;   // stores the key for this node
    int val;   // stores the value for this node

    Node* prev;  // pointer to the previous node in the doubly linked list
    Node* next;  // pointer to the next node in the doubly linked list

    // Constructor to initialize a new node with a key-value pair
    Node(int key, int val){
        this -> key = key;  // set the key
        this -> val = val;  // set the value
    }
};

// LRUCache class that uses a doubly linked list + hashmap to store the cache
class LRUCache {
public:
    Node* head = new Node(-1,-1);   // create a dummy head node
    Node* tail = new Node(-1,-1);   // create a dummy tail node

    int cap;  // capacity of the LRU Cache
    unordered_map<int,Node*> mp;  // hashmap to store the key-node pairs

    // Constructor to initialize the LRUCache with a specific capacity
    LRUCache(int capacity) {
        cap = capacity;  // set the capacity
        head -> next = tail;  // link the head node to the tail node
        tail -> prev = head;  // link the tail node to the head node
    }

    // Adds a node right after the head node (most recently used)
    void addNode(Node* newNode){
        Node* temp = head -> next;  // temporary pointer to the node after the head

        newNode -> next = temp;  // new node points to the current first node
        newNode -> prev = head;  // new node's previous pointer points to head

        temp -> prev = newNode;  // the current first node's previous pointer points to the new node
        head -> next = newNode;  // the head node's next pointer points to the new node
    }

    // Removes a node from the doubly linked list
    void deleteNode(Node* delNode){
        Node* prevv = delNode -> prev;  // get the previous node of the node to delete
        Node* nextt = delNode -> next;  // get the next node of the node to delete

        prevv -> next = nextt;  // link the previous node to the next node
        nextt -> prev = prevv;  // link the next node to the previous node
    }
    
    // Get the value for a specific key from the cache
    int get(int key) {
        // If the key is found in the hashmap
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];  // retrieve the node associated with the key
            int ans = resNode -> val;  // store the value of the node

            mp.erase(key);  // remove the key from the hashmap
            deleteNode(resNode);  // remove the node from the doubly linked list
            addNode(resNode);  // add the node back to the front (most recently used)

            mp[key] = head -> next;  // update the hashmap with the new position of the node
            return ans;  // return the value of the node
        }
        return -1;  // return -1 if the key is not found in the cache
    }
    
    // Put a key-value pair into the cache
    void put(int key, int value) {
        // If the key already exists in the cache, update its value
        if(mp.find(key) != mp.end())
        {
            Node* curr = mp[key];  // get the current node for the key
            mp.erase(key);  // remove the old key-value pair from the hashmap
            deleteNode(curr);  // remove the node from the doubly linked list
        }

        // If the cache has reached its capacity, remove the least recently used node
        if(mp.size() == cap){
            mp.erase(tail -> prev -> key);  // remove the key of the node before the tail (least recently used)
            deleteNode(tail -> prev);  // remove the node from the doubly linked list
        }

        // Add the new node with the key-value pair at the front of the list (most recently used)
        addNode(new Node(key,value));
        mp[key] = head -> next;  // update the hashmap to reflect the new position of the node
    }
};








// Not the correct code but to get basic idea:

class Node{
public:
    int key;   // Node lo key-value pair store chestav
    int val;   

    Node* prev;  // pointer to the previous,next nodes in double linked list
    Node* next;  

    // Constructor to initialize a new node with a key-value pair
    Node(int key, int val){
        this -> key = key;  // set the key
        this -> val = val;  // set the value
    }
};

// LRUCache class that uses a doubly linked list + hashmap to store the cache
class LRUCache {
public:
    Node* head = new Node(-1,-1);   // create a dummy head node
    Node* tail = new Node(-1,-1);   // create a dummy tail node

    int cap;  // capacity of the LRU Cache
    unordered_map<int,Node*> mp;  // hashmap to store the key-node pairs

    // Constructor to initialize the LRUCache with a specific capacity
    LRUCache(int capacity) {
        cap = capacity;  // set the capacity
        head -> next = tail;  // link the head node to the tail node
        tail -> prev = head;  // link the tail node to the head node
    }

    // Adds a node right after the head node (most recently used)
    void addNode(Node* newNode){
        Node* temp = head -> next;  // temporary pointer to the node after the head

        newNode -> next = temp;  // new head next place lo pedtav
        newNode -> prev = head;  // 

        temp -> prev = newNode;  // the current first node's previous pointer points to the new node
        head -> next = newNode;  // the head node's next pointer points to the new node
    }

    // THIS IS SIMPLE
    void deleteNode(Node* delNode){
        Node* prevv = delNode -> prev;  // get the previous node of the node to delete
        Node* nextt = delNode -> next;  // get the next node of the node to delete

        prevv -> next = nextt;  // link the previous node to the next node
        nextt -> prev = prevv;  // link the next node to the previous node
    }
    
    // Get the value for a specific key from the cache
    int get(int key) {
        // If the key is found in the hashmap
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];  // retrieve the node associated with the key
            int ans = resNode -> val;  // store the value of the node

            mp.erase(key);  // remove the key from the hashmap
            deleteNode(resNode);  // remove the node from the doubly linked list
            addNode(resNode);  // add the node back to the front (most recently used)

            mp[key] = head -> next;  // update the hashmap with the new position of the node
            return ans;  // return the value of the node
        }
        return -1;  // return -1 if the key is not found in the cache
    }
    
    // HIS GET AND PUT, U THINK
    void put(int key, int value) {
        // If the key already exists in the cache, update its value
        if(mp.find(key) != mp.end())
        {
            Node* curr = mp[key];  // get the current node for the key
            mp.erase(key);  // remove the old key-value pair from the hashmap
            deleteNode(curr);  // remove the node from the doubly linked list
        }

        // If the cache has reached its capacity, remove the least recently used node
        if(mp.size() == cap){
            mp.erase(tail -> prev -> key);  // remove the key of the node before the tail (least recently used)
            deleteNode(tail -> prev);  // remove the node from the doubly linked list
        }

        // Add the new node with the key-value pair at the front of the list (most recently used)
        addNode(new Node(key,value));
        mp[key] = head -> next;  // update the hashmap to reflect the new position of the node
    }
};
