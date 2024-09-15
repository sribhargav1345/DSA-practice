class Node {
public:
    Node* child[26];
    bool flag = false;

    bool containsKey(char ch){
        return child[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        child[ch-'a'] = node;
    }

    Node* get(char ch) {
        return child[ch-'a'];
    }

    void setEnd(){
        flag = 1;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* a = root;
        for(int i = 0; i < word.size(); i++) {
            if(!a -> containsKey(word[i])){
                a -> put(word[i], new Node());
            }
            a = a -> get(word[i]);
        }
        a -> setEnd(); 
    }
    
    bool search(string word) {
        Node* a = root;
        for(int i=0;i<word.size();i++)
        {
            if(!a -> containsKey(word[i])){
                return false;
            }
            a = a -> get(word[i]);
        }
        return (a -> isEnd());
    }
    
    bool startsWith(string word) {
        Node* a = root;
        for(int i=0;i<word.size();i++)
        {
            if(!a -> containsKey(word[i])){
                return false;
            }
            a = a -> get(word[i]);
        }
        return true;
    }
};