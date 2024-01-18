# include <iostream>
using namespace std;

class myString
{
private:
    /* data */
    string s;
public:
    void init(string s1) {
        s = s1;
    }
    int length() {
        return s.length();
    }
    void upper() {
        string upperS = "";
        for(int i=0;i<length();i++) {
            int asciiS = (int)s.at(i);
            if(asciiS>=97 && asciiS<=122) {
                asciiS = asciiS-32;
                upperS += (char)asciiS;
            }
            else {
                upperS += s.at(i);
            }
        }
        cout<<upperS<<endl;
    }
    void display() {
        cout<<s<<endl;
    };
};


int main() {
    myString S;
    S.init("hello");
    S.display();
    cout<<"The length is: "<<S.length()<<endl;
    S.upper();
}