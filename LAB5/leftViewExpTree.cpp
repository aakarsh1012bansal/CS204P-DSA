#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
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

void leftView(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        bool isFirst = true;

        for (int i = 0; i < n; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            if (isFirst) {
                cout << curr->data << " ";
                isFirst = false;
            }
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {
    string postfix;
    int t;
    cin>>t;
    cin.ignore();
    for(int q=0;q<t;q++) {
        getline(cin, postfix);
        TreeNode* root = buildExpressionTree(postfix);
        leftView(root);
        cout<<endl;
    }

    return 0;
}