#include<bits/stdc++.h>
using namespace std;

/*------------------------------
1. Trie data structure has k-n ary tree.
    k depends on the no of unique character
2. It can be a binary trie.
*/

int const SIZE = 26;

struct node{
    char c;
    int count; // count of words with this letter
    bool endOfWord; // int can also be used for endOfWord to denote no of strings ending 
    node* ar[SIZE];
};

node* getNode(){
    node* n = new node();
    n->endOfWord = false;
    for(int i=0;i<SIZE;i++) n->ar[i] = NULL;
    n->count = 0;
    return n;   
}

void insert(node* root,string s){
    node* tempRoot = root;
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(tempRoot->ar[index]==nullptr){
            tempRoot->ar[index] = getNode();
        }
        tempRoot = tempRoot->ar[index];
        tempRoot->count++;
        tempRoot->c = s[i];
    }
    tempRoot->endOfWord = true;
}

bool search(node* root,string s){
    node* tempRoot = root;
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(tempRoot->ar[index]==nullptr){
            return false;
        }
        tempRoot = tempRoot->ar[index];
    }
    return tempRoot->endOfWord;
}

bool deleteNode(node* root,string s){
    node* tempRoot = root;
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(tempRoot->ar[index]==nullptr) return false;
        tempRoot = tempRoot->ar[index];
    }
    if(tempRoot->endOfWord==false) return false;
    tempRoot->endOfWord = false;
    return true;
}

int32_t main(){
    

}





















