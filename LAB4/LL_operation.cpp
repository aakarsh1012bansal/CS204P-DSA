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
        struct Node* head = NULL;
        struct Node* lastNode = NULL;
        int count=0;
    
    public:
        void insert(int pos, int ele) { // done
            if(count==0 || pos==count+1) {
                append(ele);
            }
            else {
                Node* node = head;
                Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
                (*newNode).data = ele;
                if(pos==1) {
                    (*newNode).next = head;
                    head = newNode;
                }
                else {
                    for(int i=0;i<pos-2;i++) {
                        node = (*node).next;
                    }
                    (*newNode).data = ele;
                    (*newNode).next = (*node).next;
                    (*node).next = newNode;
                }
                count++;
            }
            
        }
        void deletee(int pos) { // done
            if(count!=0) {
                Node* node = head;
                Node* temp;
                if(pos==1) {
                    temp = node;
                    head = (*node).next;
                }
                else {
                    for(int i=0;i<pos-2;i++) {
                        node = (*node).next;
                    }
                    temp = (*node).next;
                    (*node).next = (*(*node).next).next;
                    if(pos==count) {
                        lastNode = node;
                    }
                }
                delete(temp);
                count--;
            }
        }
        
        void update(int pos, int ele) { // done
            if(pos<=count) {
                Node* node = head;
                for(int i=0;i<=pos-2;i++) {
                    node = (*node).next;
                }
                (*node).data = ele;
            }
        }
        
        void append(int ele) { // done
            if(count==0) {
                head = new Node;
                lastNode = new Node;
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
                    cout<<(*node).data<<" ";
                    node = (*node).next;
                }
                cout<<(*node).data<<endl;
            }
        }
};

int main() {
    LList ll;
    int code;
    while(true) {
        cin>>code;
        switch(code) {
            case 1:
                int ele1;
                cin>>ele1;
                ll.append(ele1);
                break;
            case 2:
                int ele2,pos2;
                cin>>pos2>>ele2;
                ll.insert(pos2,ele2);
                break;
            case 3:
                int pos3;
                cin>>pos3;
                ll.deletee(pos3);
                break;
            case 4:
                int ele4,pos4;
                cin>>pos4>>ele4;
                ll.update(pos4,ele4);
                break;
            case 5:
                ll.Reverse();
                break;
            case 6:
                ll.display();
                break;
            case 7:
                break;
        }
        if(code==7) {
            break;
        }
    }
}