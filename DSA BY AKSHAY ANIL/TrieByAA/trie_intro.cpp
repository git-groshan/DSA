#include<bits/stdc++.h>
using namespace std;

//Implement trie 
/*
-We insert every char as a node after the root node   T.C = O(N)
-bool isCompleteWord for every node to get know whether a word completes at this node
starts with -> means string exist in trie but it is not a complete word  T.C = O(N)
SPACE COMPLEXICITY - we create a new node each time for every newsequences character (new ordered character )
 O(s) --> Total no of charc in all string that are inserted in Tree
*/

class TrieNode{
    public:
    bool isCompleteWord;
    TrieNode* children[26]; // 

    TrieNode(){
        isCompleteWord = false;// when the word is completed (mark that node as true)
        memset(children , 0 , sizeof(children)); // for 26 possible childrens (for next letter)
    }
};

class Trie{  // Initializes the root node 
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

void insert(string word){
    TrieNode* node = root; // set root because insert after the root
    for(char ch: word){
        int idx = ch - 'a'; // as it is array so every char corrosponds to an index
        if(node->children[idx]==NULL){ // if no such child is present then 
            node->children[idx] = new TrieNode(); // make one 
        }
        node = node->children[idx]; 
    }
    node->isCompleteWord = true; // lastly mark end char of that word as complete
}

bool search(string word){
    TrieNode* node = root;
    for(char ch: word){
        int idx = ch - 'a';
        if(node->children[idx]==NULL) return false;
        node = node->children[idx];
    }
    return node->isCompleteWord;
}

bool startsWith(string prefix){
    TrieNode* node = root;
    for(char ch : prefix){
        int idx = ch -'a';
        if(node->children[idx] == NULL) return false;
        node = node->children[idx];
    }
    return true; // it doesn't need to be completed as it starts with
}

};

int main(){

return 0;
}