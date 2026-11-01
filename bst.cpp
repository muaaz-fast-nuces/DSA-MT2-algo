#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val, Node* left = nullptr, Node* right=nullptr):val(val),left(left),right(right){}
};

class BST{
    Node* root = nullptr;
    Node* insert(Node* root,int val){
        if(!root) return new Node(val);
        if(val > root->val){
            root->right = insert(root->right,val);
        }
        else {
            root->left = insert(root->left,val);
        }
        return root;
    }
    void inOrder(Node *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
    Node* findSmallest(Node* root){
        if(!root) return nullptr;
        if(!root->left) return root;
        return findSmallest(root->left);
    }
    Node *findLargest(Node *root)
    {
        if (!root)
            return nullptr;
        if (!root->right)
            return root;
        return findLargest(root->right);
    }
    Node* deleteNodeByVal(Node* root, int target){
        if(!root) return nullptr;
        if(target > root->val ) root->right = deleteNodeByVal(root->right,target);
        else if(target < root->val) root->left =  deleteNodeByVal(root->left,target);
        else{
            if(!root->left && !root->right) {
                delete root;
                root = nullptr;
                return root;
            }
            if(!root->left){
                Node* next = root->right;
                delete root;
                return next;
            }
            if(!root->right){
                Node *next = root->left;
                delete root;
                return next;
            }

            Node* smallest = findSmallest(root->right);

            swap(smallest->val,root->val);
            root->right = deleteNodeByVal(root->right,smallest->val);

        }
        return root;
    }
    public:
    void insert(int val){
        if(!root) root = insert(nullptr,val);
        else insert(root,val);
    }
    void inOrder(){inOrder(root);}
    void deleteByValue(int val){deleteNodeByVal(root,val);}
};

int main() {
    BST bst;
    bst.insert(0);
    bst.insert(1);
    bst.insert(4);
    bst.insert(5);
    bst.insert(2);
    bst.insert(9);
    bst.inOrder();
    cout << endl;
    bst.deleteByValue(7);
    bst.inOrder();
    cout << endl;
    bst.deleteByValue(5);
    bst.inOrder();

    return 0;
}
