class LRUCache {
public:
    class node{
        public:
            int val, key;
            node *prev, *next;
            node(int key_,int value_){
                key=key_;
                val=value_;
            }
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node *newnode){
        node *tmp=head->next;
        newnode->next=tmp;
        newnode->prev=head;
        head->next=newnode;
        tmp->prev=newnode;
    }
    void deletnode(node *delnode){
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *res=mp[key];
            int ans=res->val;
            mp.erase(key);
            deletnode(res);
            addnode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *curr=mp[key];
            mp.erase(key);
            deletnode(curr);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletnode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */