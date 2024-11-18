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

    Node* get(char ch){
        return child[ch-'a'];
    }

    void setEnd(){
        flag = 1;
    }

    bool isEnd(){
        return (flag == 1);
    }
};

class Trie {
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        int n = word.size();
        Node* a = root;
        for(int i=0;i<n;i++)
        {
            if(!a -> containsKey(word[i])){
                a -> put(word[i], new Node());
            }
            a = a -> get(word[i]);
        }
        a -> setEnd();
    }

    bool search(string word){
        int n = word.size();
        Node* a = root;

        for(int i=0;i<n;i++)
        {
            if(a -> containsKey(word[i])){
                a = a -> get(word[i]);
            }
            else return false;
        }
        return a -> isEnd();
    }

    bool isStartwith(string word){
        int n = word.size();
        Node* a = root;

        for(int i=0;i<n;i++)
        {
            if(a -> containsKey(word[i])){
                a = a -> get(word[i]);
            }
            else return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        if(n == 0) return "";
        
        Trie th;
        for(int i=0;i<n;i++)
        {
            th.insert(strs[i]);
        }

        string prefix = "";
        Node* node = th.root;

        while (true) {
            int count = 0;  
            char nextChar;

            for(int i=0;i<26;i++){
                if (node->child[i] != nullptr) {
                    count++;
                    nextChar = 'a' + i;
                }
            }
            if (count != 1 || node->isEnd()) break;

            prefix += nextChar;
            node = node->child[nextChar - 'a'];
        }

        return prefix;

    }
};