// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// int level(Node* root){
//     if(root==NULL) return 0;
//     return 1+max(level(root->left),level(root->right));
// }
// void nthlevel(Node* root,int curr,int level) {
//     if (root == NULL) return;
//     if(curr==level) {
//         cout<<root->val<<" ";
//         return;
//     }
//     nthlevel(root->left,curr+1,level);
//     nthlevel(root->right,curr+1,level);
// }
// void levelOrder(Node* root){
//     int n=level(root);
//     for(int i=1;i<=n;i++){
//         nthlevel(root,1,i);
//         cout<<endl;
//     }
// }

// int main() {
//     Node* a = new Node(1);
//     Node* b = new Node(2);
//     Node* c = new Node(3);
//     Node* d = new Node(4);
//     Node* e = new Node(5);
//     Node* f = new Node(6);
//     Node* g = new Node(7);
//     a->left = b;
//     a->right = c;
//     b->left = d;
//     b->right = e;
//     c->left = f;
//     c->right = g;
//     // nthlevel(a,1,1);
//     // nthlevel(a,1,2);
//     // nthlevel(a,1,3);
//     levelOrder(a);    
// }





// right to left
#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int level(Node* root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
void nthlevel(Node* root,int curr,int level) {
    if (root == NULL) return;
    if(curr==level) {
        cout<<root->val<<" ";
        return;
    }
    nthlevel(root->left,curr+1,level);
    nthlevel(root->right,curr+1,level);
}
void levelOrder(Node* root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
}

void levelOrderQueue(Node* root){  //bfs
     queue<Node*> q;
     q.push(root);
     while(q.size()>0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
     }
     cout<<endl;
}
int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    // levelOrder(a);
    nthlevel(a,1,3);    
}
