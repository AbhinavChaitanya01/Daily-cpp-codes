//~~~~~~~~~~~~~~~~~  IMPLEMENTATION OF A TRIE ( DICTIONARY )  ~~~~~~~~~~~~~~~~~~

#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;
    // Constructor: 
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root= new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'A';
        TrieNode* child;
        // if present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        // else it is absent
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //Recursion:
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index= word[0]-'A';
        TrieNode* child;
        // present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            // absent
            return false;
        }
        // recursion-
        return searchUtil(child, word.substr(1));
    }
    bool search(string word){
        return searchUtil(root, word);
    }
};
int main(){
    Trie* t=new Trie();
    t->insertWord("ABCD");
    t->insertWord("CAT");
    t->insertWord("CAR");
    t->insertWord("DU");
    t->insertWord("DUCK");
    t->insertWord("TIME");
    cout<<t->search("TIM"); // Output- 0
    return 0;
}