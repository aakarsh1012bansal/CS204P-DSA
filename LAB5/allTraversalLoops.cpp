#include <iostream>
#include <stack>
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

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}
void preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();
        cout << current->data << " ";
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
}
void postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    stack<string> result;

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();
        result.push(current->data);
        if (current->left)
            s.push(current->left);
        if (current->right)
            s.push(current->right);
    }

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
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
        inorderTraversal(root);
        cout << endl;
        preorderTraversal(root);
        cout << endl;
        postorderTraversal(root);
        cout << endl;
    }

    return 0;
}