#include <bits/stdc++.h>
using namespace std;

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
}

class Trie{
public:
    class node{
    public:
        bool end;
        node* next[26];
        node(){
            end = false;
            for(int i = 0; i <26; i++){
                next[i] == NULL;
            }
        }
    };


    node* trie;
    Trie(){
        trie = new node();
    };


    void insert(string word){
        int i = 0;
        node* it = trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL){
                it->next[word[i]-'a'] = new node();
            }

            it = it->next[word[i]-'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word){
        int i = 0;
        node* it= trie;

        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL){
                return false;
            }
            it= it->next[word[i]-'a'];
            i++;
        } 

        return (it->end==true);
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init_code();
    Trie *trr = new Trie();
    trr->insert("Vaibhav");
    trr->insert("Madhav");

    cout<<trr->search("Madhhav")<<" ";
    cout<<trr->search("Madhav")<<" ";
    cout<<trr->search("Madh")<<" ";
    cout<<trr->search("Vaibhav")<<" ";
    return 0;
}