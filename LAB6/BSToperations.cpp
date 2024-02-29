#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createNode(int val) {
    TreeNode* newNode = new TreeNode;
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}


TreeNode* insertEle(TreeNode* root, int val) {
    if (root == nullptr) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertEle(root->left, val);
    } else {
        root->right = insertEle(root->right, val);
    }

    return root;
}


bool searchEle(TreeNode* root, int val) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == val) {
        return true;
    } else if (val < root->val) {
        return searchEle(root->left, val);
    } else {
        return searchEle(root->right, val);
    }
}


int smallestEle(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root->val;
}

void preorder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}


int main() {
    int t;
    cin>>t;
    TreeNode* root = nullptr;
    // node = createNode(10);
    for(int q=0;q<t;q++) {
        int code, ele;
        cin>>code;
        switch(code) {
            case 1:
                cin>>ele;
                root = insertEle(root, ele);
                break;
            case 2:
                cin>>ele;
                cout<<searchEle(root, ele)<<endl;
                break;
            case 3:
                cout<<smallestEle(root)<<endl;
                break;
            case 4:
                preorder(root);
                cout<<endl;
                break;
            case 5:
                inorder(root);
                cout<<endl;
                break;
        }
    }
}
