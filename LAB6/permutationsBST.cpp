#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    int size;
    Node(int x)
    {
        data=x;
        left=right=NULL;
        size=1;
    }
};

class BinarySearchTree
{
    public:
    Node *root;
    BinarySearchTree() {root=NULL;}
    void insert(Node * n,int x)
    {
        if(root==NULL)
        {
            root=new Node(x);
            return;
        }
        n->size++;
        if(n->data>x)
        {
            if(n->left==NULL)  n->left=new Node(x);
            else  insert(n->left,x);
        }
        else
        {
            if(n->right==NULL)  n->right=new Node(x);
            else  insert(n->right,x);
        }
    }
    ll permutations(Node *n)
    {
        if(n==NULL) return 1;
        ll left=permutations(n->left);
        ll right=permutations(n->right);
        int x;
        if(n->left) x=n->left->size;
        else x=0;
        return left*right*combination(n->size-1,x);
    }
    ll combination(int n,int r)
    {
        if(r>n-r) r=n-r;
        ll res=1;
        for(int i=0;i<r;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        // cout<<n<<" "<<r<<" "<<res<<endl;
        return res;
    }
};



int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        int n;
        cin>>n;
        BinarySearchTree bst;
        while(n--)
        {
            int x;
            cin>>x;
            bst.insert(bst.root,x);
        }
        cout<<bst.permutations(bst.root)<<endl;
    }
}