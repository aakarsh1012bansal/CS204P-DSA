# include <iostream>
# include <cstring>
using namespace std;

int pow(int base, int power) {
    int num=1;
    for(int i=0;i<power;i++) {
        num *= base;
    }
    return num;
}

class myStack
{
private:
    /* data */
    int data[1000];
    int topEle=-1;
public:
    void push(int ele);
    void pop();
    int top();
    // void display();
};

void myStack::push(int ele) {
    topEle++;
    data[topEle] = ele;
}
void myStack::pop() {
    topEle--;
}
int myStack::top() {
    return data[topEle];
}
// void myStack::display() {
//     for(int i=0;i<=topEle;i++) {
//         cout<<data[i]<<" ";
//     }
//     cout<<endl;
// }


int main() {
    int t;
    cin>>t;
    cin.ignore();
    for(int q=0;q<t;q++) {
        string s;
        getline(cin, s);
        myStack eva;
        for(int i=0;i<s.length();i++) {
            if(isdigit(s.at(i))) {
                int j=i;
                int numDigit=0;
                while(isdigit(s.at(j))) {
                    numDigit++;
                    j++;
                }
                j=i;
                int num=0;
                for(int count=numDigit-1;count>=0;count--) {
                    num += (s.at(j)-'0')*pow(10, count);
                    j++;
                }
                i=j;
                // cout<<"num: "<<num<<endl;
                eva.push(num);
            }
            else if(s.at(i)=='+') {
                int first = eva.top();
                eva.pop();
                int second = eva.top();
                eva.pop();
                int result = first+second;
                eva.push(result);
            }
            else if(s.at(i)=='-') {
                int first = eva.top();
                eva.pop();
                int second = eva.top();
                eva.pop();
                int result = second-first;
                eva.push(result);
            }
            else if(s.at(i)=='*') {
                int first = eva.top();
                eva.pop();
                int second = eva.top();
                eva.pop();
                int result = second*first;
                eva.push(result);
            }
            else if(s.at(i)=='/') {
                int denom = eva.top();
                eva.pop();
                int nume = eva.top();
                eva.pop();
                int result = nume/denom;
                eva.push(result);
            }
        }
        cout<<eva.top()<<endl;
    }
}