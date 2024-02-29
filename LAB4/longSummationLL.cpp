# include <iostream>
# include <stdlib.h>
using namespace std;

struct Node {
    public: 
        int data;
        Node* next;
};

class LList {
    private:
        struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
        struct Node* lastNode = (struct Node*)malloc(sizeof(struct Node*));
        int count=0;
    
    public:
        void append(int ele) { // done
            if(count==0) {
                (*head).data = ele;
                (*head).next = nullptr;
                lastNode = head;
            }
            else {
                Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
                (*lastNode).next = newNode;
                (*newNode).data = ele;
                (*newNode).next = nullptr;
                lastNode = newNode;
            }
            count++;
        }
        void Reverse() {
            Node* previousNode;
            Node* currentNode = head;
            Node* nextNode;
            for(int i=0;i<count;i++) {
                if(i==0) {
                    nextNode = currentNode->next;
                    currentNode->next = nullptr;
                    lastNode = currentNode;
                    previousNode = currentNode;
                    currentNode = nextNode;
                }
                else if(i==count-1) {
                    currentNode->next = previousNode;
                    head = currentNode;
                }
                else {
                    nextNode = currentNode->next;
                    currentNode->next = previousNode;
                    previousNode = currentNode;
                    currentNode = nextNode;
                }
            }
        }
        void display() { // done
            if(count!=0) {
                Node* node = head;
                while((*node).next!=nullptr) {
                    cout<<(*node).data<<"";
                    node = (*node).next;
                }
                cout<<(*node).data<<endl;
            }
        }
        Node* getHead() {
            return head;
        }
        void clear() {
            Node* currentNode = head;
            Node* nextNode = currentNode->next;
            while(currentNode->next!=nullptr) {
                nextNode = currentNode->next;
                delete(currentNode);
                currentNode = nextNode;
            }
            delete(currentNode);
        }
};

void bigSum(LList ll1, LList ll2) {
    Node* node1 = ll1.getHead();
    Node* node2 = ll2.getHead();
    LList ans;
    int carry = 0;
    while(node2->next!=nullptr) {
        int sum = node1->data + node2->data + carry;
        if(sum>=10) {
            ans.append((to_string(sum).at(1))-'0');
            carry = (to_string(sum).at(0)) - '0';
        }
        else {
            ans.append((to_string(sum).at(0))-'0');
            carry = 0;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    {
        int sum = node1->data + node2->data + carry;
        if(sum>=10) {
            ans.append((to_string(sum).at(1))-'0');
            carry = (to_string(sum).at(0)) - '0';
        }
        else {
            ans.append((to_string(sum).at(0))-'0');
            carry = 0;
        }
        node1 = node1->next;
    }
    if(node1!=nullptr) {
        while(node1->next!=nullptr) {
            int sum = node1->data + 0 + carry;
            if(sum>=10) {
                ans.append((to_string(sum).at(1))-'0');
                carry = (to_string(sum).at(0)) - '0';
            }
            else {
                ans.append((to_string(sum).at(0))-'0');
                carry = 0;
            }
            node1 = node1->next;
        }
        {
            int sum = node1->data + 0 + carry;
            if(sum>=10) {
                ans.append((to_string(sum).at(1))-'0');
                carry = (to_string(sum).at(0)) - '0';
            }
            else {
                ans.append((to_string(sum).at(0))-'0');
                carry = 0;
            }
        }
    }
    if(carry!=0) {
        ans.append(carry);
    }
    ans.Reverse();
    ans.display();
    ll1.clear();
    ll2.clear();
    ans.clear();
}

int main() {
    string s1, s2;
    int t;
    cin>>t;
    for(int q=0;q<t;q++) {
        LList ll1, ll2;
        cin>>s1;
        cin>>s2;
        for(int i=s1.length()-1;i>=0;i--) {
            ll1.append(s1.at(i)-'0');
        }
        for(int i=s2.length()-1;i>=0;i--) {
            ll2.append(s2.at(i)-'0');
        }
        // ll1.display();
        // ll2.display();
        if(s1.length()>=s2.length()) {
            bigSum(ll1, ll2);
        }
        else if(s1.length()<s2.length()) {
            bigSum(ll2, ll1);
        }
    }
}