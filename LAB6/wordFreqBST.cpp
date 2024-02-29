#include <iostream>
#include <sstream>
#include <string>
using namespace std;


struct TreeNode {
    string word;
    int frequency;
    TreeNode* left;
    TreeNode* right;
};


TreeNode* createNode(string val) {
    TreeNode* newNode = new TreeNode;
    newNode->word = val;
    newNode->frequency = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insertEle(TreeNode* root, string word) {
    if (root == nullptr) {
        return createNode(word);
    }

    if (word < root->word) {
        root->left = insertEle(root->left, word);
    } else if (word > root->word) {
        root->right = insertEle(root->right, word);
    } else {
        root->frequency++;
    }

    return root;
}


void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->word << " " << root->frequency << endl;
        inorder(root->right);
    }
}

void wordFreq(string input) {
    stringstream ss(input);
    TreeNode* root = nullptr;
    string word;
    while(ss>>word) {
        root = insertEle(root, word);
    }
    inorder(root);
}

int main() {
    int t;
    cin>>t;
    cin.ignore();
    for(int q=0;q<t;q++) {
        string s;
        getline(cin, s);
        wordFreq(s);
        cout << endl;
    }
    return 0;
}
