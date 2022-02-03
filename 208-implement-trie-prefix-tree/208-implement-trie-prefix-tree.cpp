
struct Node{
    Node* links[26];
    bool flag=false;
    bool contain(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    void end(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
    
};

class Trie {
private: Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contain(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->end();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contain(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        if(node->isend()){
            return 1;
        }
        return 0;
        
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->contain(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */