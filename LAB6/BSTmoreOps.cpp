#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* findIthLargest(Node* root, int& count, int k) {
    if (root == nullptr)
        return nullptr;

    Node* right = findIthLargest(root->right, count, k);
    if (right != nullptr)
        return right;

    count++;
    if (count == k)
        return root;

    return findIthLargest(root->left, count, k);
}

Node* findIthSmallest(Node* root, int& count, int k) {
    if (root == nullptr)
        return nullptr;

    Node* left = findIthSmallest(root->left, count, k);
    if (left != nullptr)
        return left;

    count++;
    if (count == k)
        return root;

    return findIthSmallest(root->right, count, k);
}

Node* findInorderSuccessor(Node* root, int value) {
    Node* successor = nullptr;
    while (root) {
        if (root->data > value) {
            successor = root;
            root = root->left;
        } else
            root = root->right;
    }
    return successor;
}

Node* findInorderPredecessor(Node* root, int value) {
    Node* predecessor = nullptr;
    while (root) {
        if (root->data < value) {
            predecessor = root;
            root = root->right;
        } else
            root = root->left;
    }
    return predecessor;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;

    int p;
    cin >> p;
    while (p--) {
        int t;
        cin >> t;
        if (t == 1) {
            int n;
            cin >> n;
            root = insert(root, n);
        } else if (t == 2) {
            int k;
            cin >> k;
            int count = 0;
            int ans = findIthLargest(root, count, k)->data;
            cout << ans << endl;
        } else if (t == 3) {
            int k;
            cin >> k;
            int count = 0;
            int ans = findIthSmallest(root, count, k)->data;
            cout << ans << endl;
        } else if (t == 4) {
            int value;
            cin >> value;
            int ans = findInorderSuccessor(root, value)->data;
            cout << ans << endl;
        } else if (t == 5) {
            int value;
            cin >> value;
            int ans = findInorderPredecessor(root, value)->data;
            cout << ans << endl;
        } else if (t == 6) {
            int element;
            cin >> element;
            root = deleteNode(root, element);
        }
    }

    return 0;
}