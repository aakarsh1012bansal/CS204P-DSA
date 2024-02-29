#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;
};



TreeNode* buildExpressionTree(string postfix) {
    stack<TreeNode*> st;
    size_t pos = 0;
    while ((pos = postfix.find(' ')) != string::npos) {
        string token = postfix.substr(0, pos);
        // cout<<token<<endl;
        postfix.erase(0, pos + 1);
        // cout<<postfix<<endl;
        TreeNode* newNode = new TreeNode;
        newNode->data = token;
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
        }
        else {
            newNode->right = NULL;
            newNode->left = NULL;
        }
        st.push(newNode);
    }
    TreeNode* finalNode = new TreeNode;
    finalNode->data = postfix;
    finalNode->right = st.top();
    st.pop();
    finalNode->left = st.top();
    st.pop();
    st.push(finalNode);
    return st.top();
}

void inorderTraversal(TreeNode* root) {
    if (root!=NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(TreeNode* root) {
    if (root!=NULL) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(TreeNode* root) {
    if (root!=NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int t;
    cin>>t;
    cin.ignore();
    for(int q=0;q<t;q++) {
        string postfix;
        getline(cin, postfix);
        TreeNode* root = buildExpressionTree(postfix);
        inorderTraversal(root);
        cout << endl;
        preorderTraversal(root);
        cout << endl;
        postorderTraversal(root);
        cout << endl;
    }

    return 0;
}