# include <iostream>
# include <stack>
using namespace std;

class undoRedoFeature
{
private:
    /* data */
    char s[1000];
    int length=0;
    stack<pair<int,int>> s1, s2;
public:
    void init(string ss) {
        length = ss.length();
        for(int i=0;i<ss.length();i++) {
            s[i] = ss.at(i);
        }
    }
    void undo() {
        changeCase(s1.top().first, s1.top().second, false);
        s2.push(s1.top());
        s1.pop();
    }
    void redo() {
        s1.push(s2.top());
        changeCase(s1.top().first, s1.top().second, false);
        s2.pop();
    }
    void changeCase(int a, int b, bool byUser) {
        for(int i=a;i<=b;i++) {
            if(((int)s[i])>=97 && ((int)s[i])<=122) {
                s[i] = (char)((int)s[i]-32);
            }
            else if(((int)s[i])>=65 && ((int)s[i])<=90) {
                s[i] = (char)((int)s[i]+32);
            }
        }
        if(byUser) {
            pair<int,int> coor;
            coor.first = a;
            coor.second = b;
            s1.push(coor);
        }
        
    }
    void display() {
        for(int i=0;i<length;i++) {
            cout<<s[i];
        }
        cout<<endl;
    }

};


int main() {
    string s = "aakarsh";
    undoRedoFeature urf;
    urf.init(s);
    urf.display();
    urf.changeCase(0,2, true);
    urf.display();
    urf.changeCase(4,5, true);
    urf.display();
    urf.undo();
    urf.display();
    urf.undo();
    urf.display();
    urf.redo();
    urf.display();
    urf.redo();
    urf.display();
}