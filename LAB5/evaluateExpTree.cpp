#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data1;
    char data2;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(char data)
{
    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->data2 = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct node* newNode(int data)
{
    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->data1 = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}


struct node* createNew(string s){
  
    stack<struct node* > q;
    string temp="";
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){
            struct node* r=newNode(s[i]);
            r->right=q.top();
            q.pop();
            r->left=q.top();
            q.pop();
            q.push(r);
        }
        else{
            if(s[i]==' ' && temp != ""){
                struct node* r=newNode(stoi(temp));
                q.push(r);
                temp="";
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                temp+=s[i];
            }
        }
    }
    return q.top();
}

int postfixTraversal(struct node* root){
     
    if (root==NULL) 
        return 0; 
 
    if (root->left==NULL && root->right==NULL) 
        return (root->data1); 
  
    int l = postfixTraversal(root->left); 
    int r = postfixTraversal(root->right); 

    if (root->data2=='+') 
        return l+r; 
 
    if (root->data2=='-') 
        return l-r; 
 
    if (root->data2=='*') 
        return l*r; 
 
    if(root->data2=='/'){
        return (l/r);
    } 
    if(root->data2=='^'){
        return pow(l,r);
    } 
    return 0;
} 


int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t-->0){
       string s;
        // cin>>s;
        getline(cin,s);
        struct node* head=createNew(s);
        int ans=postfixTraversal(head);
        cout<<ans<<endl;
    }
    return 0;
}