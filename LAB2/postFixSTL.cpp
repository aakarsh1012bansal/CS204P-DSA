# include <iostream>
# include <cmath>
# include <stack>
using namespace std;

int main() {
    string s = "20 3 + 4 * 5 / 1 -";
    stack<int> eva;
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
                num += (s.at(j)-'0')*(int)pow(10, count);
                j++;
            }
            i=j;
            cout<<"num: "<<num<<endl;
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