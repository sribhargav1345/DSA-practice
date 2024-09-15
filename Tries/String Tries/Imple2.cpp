#include <bits/stdc++.h> 

class Node{
public:
    Node* child[26];
    bool flag = false;

    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (child[ch-'a'] != NULL);
    }

    Node* get(char ch)
    {
        return (child[ch - 'a']);
    }

    void put(char ch, Node* node){
        (child[ch - 'a'] = node);
    }

    void increaseEnd() {
        cntEndWith++; 
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--; 
    }

    void reducePrefix() {
        cntPrefix--; 
    }
};

class Trie{
    Node* root = new Node();
public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root; 

        for(int i=0;i<word.size();i++)
        {
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }

            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node -> containsKey(word[i])) return 0;
            node = node -> get(word[i]);
        }
        return node -> cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node -> containsKey(word[i])) return 0;
            node = node -> get(word[i]);
        }
        return node -> cntPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node -> containsKey(word[i])) return;

            node = node -> get(word[i]);
            node -> reducePrefix();
        }
        node -> deleteEnd();
    }
};
