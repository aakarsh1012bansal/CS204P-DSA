#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(string s) {
    stack<char> s1;
    for(int i=0;i<s.length();i++) {
        if(s.at(i)=='(' || s.at(i)=='{' || s.at(i)=='[') {
            s1.push(s.at(i));
        }
        else if(s.at(i)==')' || s.at(i)=='}' || s.at(i)==']') {
            if(s1.empty()) {
                return false;
            }
            else {
                if((s1.top()=='(' && s.at(i)!=')') || (s1.top()=='{' && s.at(i)!='}') || (s1.top()=='[' && s.at(i)!=']'))
                {
                    return false;
                }
                s1.pop();
            }
        }
    }
    if(s1.empty()) {
        return true;
    }
    return false;
}


int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        string s;
        cin>>s;
        cout<<isValid(s)<<endl;
    }
}
