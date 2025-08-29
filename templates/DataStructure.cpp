#include <bits/stdc++.h>
using namespace std;

// ---------------- LINKED LIST ----------------
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct DobbyLinkedList {
    Node* head;
    DobbyLinkedList() : head(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertBack(int val) {
        Node* newNode = new Node(val);
        if(!head){ head=newNode; return; }
        Node* temp=head;
        while(temp->next) temp=temp->next;
        temp->next=newNode;
    }
    void remove(int val) {
        if(!head) return;
        if(head->data==val){
            Node* temp=head; head=head->next; delete temp; return;
        }
        Node* cur=head;
        while(cur->next && cur->next->data!=val) cur=cur->next;
        if(cur->next){
            Node* temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
        }
    }
    void print() {
        Node* temp=head;
        while(temp){ cout<<temp->data<<" "; temp=temp->next; }
        cout<<"\n";
    }
};

// ---------------- STACK ----------------
struct DobbyStack {
    vector<int> st;
    void push(int x){ st.push_back(x); }
    void pop(){ if(!st.empty()) st.pop_back(); }
    int top(){ return st.empty() ? -1 : st.back(); }
    bool empty(){ return st.empty(); }
};

// ---------------- QUEUE ----------------
struct DobbyQueue {
    deque<int> q;
    void push(int x){ q.push_back(x); }
    void pop(){ if(!q.empty()) q.pop_front(); }
    int front(){ return q.empty() ? -1 : q.front(); }
    bool empty(){ return q.empty(); }
};

// ---------------- BINARY TREE (BST) ----------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};
struct DobbyTree {
    TreeNode* root=nullptr;
    TreeNode* insert(TreeNode* node,int val){
        if(!node) return new TreeNode(val);
        if(val<node->val) node->left=insert(node->left,val);
        else node->right=insert(node->right,val);
        return node;
    }
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }
};

// ---------------- GRAPH ----------------
struct DobbyGraph {
    int n;
    vector<vector<int>> adj;
    DobbyGraph(int n): n(n), adj(n) {}
    void addEdge(int u,int v,bool undirected=true){
        adj[u].push_back(v);
        if(undirected) adj[v].push_back(u);
    }
    void bfs(int s){
        vector<bool> vis(n,false);
        queue<int> q; q.push(s); vis[s]=true;
        while(!q.empty()){
            int u=q.front(); q.pop();
            cout<<u<<" ";
            for(auto v:adj[u]) if(!vis[v]) vis[v]=true,q.push(v);
        }
        cout<<"\n";
    }
    void dfsUtil(int u, vector<bool>& vis){
        vis[u]=true; cout<<u<<" ";
        for(auto v:adj[u]) if(!vis[v]) dfsUtil(v,vis);
    }
    void dfs(int s){
        vector<bool> vis(n,false);
        dfsUtil(s,vis);
        cout<<"\n";
    }
};

// ---------------- UNORDERED MAP (Hash Table) ----------------
template<typename K, typename V>
class DobbyUnorderedMap {
    static const int SIZE = 1009; // prime bucket size
    vector<vector<pair<K,V>>> table;
    int hashFunc(const K& key) const {
        return std::hash<K>{}(key) % SIZE;
    }
public:
    DobbyUnorderedMap() : table(SIZE) {}
    void put(const K& key, const V& value){
        int idx=hashFunc(key);
        for(auto &p:table[idx]){
            if(p.first==key){ p.second=value; return; }
        }
        table[idx].push_back({key,value});
    }
    bool get(const K& key, V& value) const {
        int idx=hashFunc(key);
        for(auto &p:table[idx]) if(p.first==key){ value=p.second; return true; }
        return false;
    }
    bool contains(const K& key) const {
        int idx=hashFunc(key);
        for(auto &p:table[idx]) if(p.first==key) return true;
        return false;
    }
    void remove(const K& key){
        int idx=hashFunc(key);
        auto &bucket=table[idx];
        bucket.erase(remove_if(bucket.begin(),bucket.end(),
                               [&](auto &p){return p.first==key;}),bucket.end());
    }
};

// ---------------- MAIN DEMO ----------------
int main(){
    // LinkedList
    DobbyLinkedList ll;
    ll.insertBack(1); ll.insertBack(2); ll.insertFront(0);
    cout<<"LinkedList: "; ll.print();

    // Stack
    DobbyStack st; st.push(10); st.push(20);
    cout<<"Stack top: "<<st.top()<<"\n"; st.pop();

    // Queue
    DobbyQueue q; q.push(5); q.push(6);
    cout<<"Queue front: "<<q.front()<<"\n"; q.pop();

    // Tree
    DobbyTree t;
    t.root=t.insert(t.root,5);
    t.insert(t.root,3); t.insert(t.root,7);
    cout<<"Tree inorder: "; t.inorder(t.root); cout<<"\n";

    // Graph
    DobbyGraph g(5);
    g.addEdge(0,1); g.addEdge(0,2); g.addEdge(1,3); g.addEdge(1,4);
    cout<<"Graph BFS from 0: "; g.bfs(0);
    cout<<"Graph DFS from 0: "; g.dfs(0);

    // Unordered Map
    DobbyUnorderedMap<string,int> ump;
    ump.put("Alice",10); ump.put("Bob",20); ump.put("Alice",99);
    int val;
    if(ump.get("Alice",val)) cout<<"Alice -> "<<val<<"\n";
    cout<<"Contains Bob? "<<(ump.contains("Bob")?"Yes":"No")<<"\n";
    ump.remove("Bob");
    cout<<"Contains Bob? "<<(ump.contains("Bob")?"Yes":"No")<<"\n";

    return 0;
}
