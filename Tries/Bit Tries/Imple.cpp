#include <iostream>
#include <vector>
using namespace std;

const int MAX_BITS = 31;  

class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class BitTrie {
private:
    TrieNode* root;

public:
    BitTrie() {
        root = new TrieNode();
    }

    // Insert Val in Trie
    void insert(int num) {
        TrieNode* node = root;
        for (int i=MAX_BITS;i>=0;i--) 
        {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

    // Function to search for a number in the Trie.
    bool search(int num) {
        TrieNode* node = root;
        for (int i = MAX_BITS; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                return false;
            }
            node = node->child[bit];
        }
        return true;
    }

    // Function to find the maximum XOR value with a given number.
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = MAX_BITS; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {
                maxXOR |= (1 << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXOR;
    }

    // Function to delete a number from the Trie.
    void remove(int num) {
        remove(root, num, MAX_BITS);
    }

private:
    bool remove(TrieNode* node, int num, int bitIndex) {
        if (!node) return false;
        if (bitIndex < 0) return true;

        int bit = (num >> bitIndex) & 1;
        if (remove(node->child[bit], num, bitIndex - 1)) {
            delete node->child[bit];
            node->child[bit] = nullptr;
            return !node->child[0] && !node->child[1];
        }
        return false;
    }
};