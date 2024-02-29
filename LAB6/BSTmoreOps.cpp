#include <stack>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertRec(Node* root, int data) {
        if (root == nullptr) {
            return createNode(data);
        }

        if (data < root->data) {
            root->left = insertRec(root->left, data);
        } else if (data > root->data) {
            root->right = insertRec(root->right, data);
        }

        return root;
    }

    Node* findNode(Node* root, int data) {
        if (root == nullptr || root->data == data) {
            return root;
        }

        if (data < root->data) {
            return findNode(root->left, data);
        }

        return findNode(root->right, data);
    }

    Node* findMin(Node* root) {
        if (root == nullptr || root->left == nullptr) {
            return root;
        }
        return findMin(root->left);
    }

    Node* findMax(Node* root) {
        if (root == nullptr || root->right == nullptr) {
            return root;
        }
        return findMax(root->right);
    }

    Node* deleteRec(Node* root, int data) {
        if (root == nullptr) {
            return root;
        }

        if (data < root->data) {
            root->left = deleteRec(root->left, data);
        } else if (data > root->data) {
            root->right = deleteRec(root->right, data);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

   int findIthLargest(int i) 
   {
    Node* curr = root;
    stack<Node*> stack;

    while (curr != nullptr || !stack.empty()) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->right;
        }

        curr = stack.top();
        stack.pop();

        if (--i == 0) {
            return curr->data;
        }

        curr = curr->left;
    }

    return -1; 
}


    int findIthSmallest(int i) {
        Node* curr = root;
        int count = 0;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if (++count == i) {
                    return curr->data;
                }
                curr = curr->right;
            } else {
                Node* predecessor = findMax(curr->left);
                if (predecessor->right == nullptr) {
                    if (++count == i) {
                        return curr->data;
                    }
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr;
                    if (++count == i) {
                        return curr->data;
                    }
                    curr = curr->right;
                }
            }
        }
        return -1;
    }

    int inorderSuccessor(int data) {
        Node* node = findNode(root, data);
        if (node == nullptr) {
            return -1;
        }

        if (node->right != nullptr) {
            return findMin(node->right)->data;
        }

        Node* successor = nullptr;
        Node* curr = root;
        while (curr != nullptr) {
            if (node->data < curr->data) {
                successor = curr;
                curr = curr->left;
            } else if (node->data > curr->data) {
                curr = curr->right;
            } else {
                break;
            }
        }
        return (successor != nullptr) ? successor->data : -1;
    }

    int inorderPredecessor(int data) {
        Node* node = findNode(root, data);
        if (node == nullptr) {
            return -1;
        }

        if (node->left != nullptr) {
            return findMax(node->left)->data;
        }

        Node* predecessor = nullptr;
        Node* curr = root;
        while (curr != nullptr) {
            if (node->data > curr->data) {
                predecessor = curr;
                curr = curr->right;
            } else if (node->data < curr->data) {
                curr = curr->left;
            } else {
                break;
            }
        }
        return (predecessor != nullptr) ? predecessor->data : -1;
    }

    void deleteNode(int data) {
        root = deleteRec(root, data);
    }
};

int main() {
    BST bst;

    // Perform operations on the BST
    int n;
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        int operation;
        cin >> operation;
        switch (operation) {
            case 1:
                int z;
                cin >> z;
                bst.insert(z);
                break;
            case 2:
                int i;
                cin >> i;
                cout<< bst.findIthLargest(i) << endl;
                break;
            case 3:
                cin >> i;
                cout << bst.findIthSmallest(i) << endl;
                break;
            case 4:
                int nodeData;
                cin >> nodeData;
                cout<< bst.inorderSuccessor(nodeData) << endl;
                break;
            case 5:
                cin >> nodeData;
                cout<< bst.inorderPredecessor(nodeData) << endl;
                break;
            case 6:
                cin >> z;
                bst.deleteNode(z);
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    }

    return 0;
}