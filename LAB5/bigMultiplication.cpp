# include <iostream>
# include <stack>
# include <algorithm>
using namespace std;

string bigSum(string s1, string s2) {
    string ans;
    int length1 = s1.length();
    int length2 = s2.length();
    int carry = 0;
    for(int i=0;i<length1;i++) {
        if(i<length2) {
            int d1 = s1.at(length1-i-1) - '0';
            int d2 = s2.at(length2-i-1) - '0';
            int sum = d1+d2+carry;
            string sums = to_string(sum);
            if(sum>=10) {
                ans += sums.at(1);
                carry = sums.at(0) - '0';
            }
            else {
                ans += sums.at(0);
                carry = 0;
            }
        }
        else {
            int d1 = s1.at(length1-i-1) - '0';
            int sum = d1+0+carry;
            string sums = to_string(sum);
            if(sum>=10) {
                ans += sums.at(1);
                carry = sums.at(0) - '0';
            }
            else {
                ans += sums.at(0);
                carry = 0;
            }
        }
        if(i==length1-1 && carry!=0) {
            ans += to_string(carry);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

stack<string> bigMul(string s1, string s2) {
    string ans;
    stack<string> answers;
    int length1 = s1.length();
    int length2 = s2.length();
    int carry = 0;
    for(int i=0;i<length2;i++) {
        int d2 = s2.at(length2-i-1) - '0';
        carry=0;
        ans = "";
        for(int k=0;k<i;k++) {
            ans += "0";
        }
        for(int j=0;j<length1;j++) {
            int d1 = s1.at(length1-j-1) - '0';
            int prod = d1*d2+carry;
            string prods = to_string(prod);
            if(prod>=10) {
                ans += prods.at(1);
                carry = prods.at(0) - '0';
            }
            else {
                ans += prods.at(0);
                carry = 0;
            }
            if(j==length1-1 && carry!=0) {
                ans += to_string(carry);
            }
        }
        reverse(ans.begin(), ans.end());
        // cout<<"mul: "<<ans<<endl;
        answers.push(ans);
    }
    return answers;
}

int main() {
    string s1;
    string s2;
    int t;
    cin>>t;
    for(int q=0;q<t;q++) {
        cin>>s1;
        cin>>s2;
        string finalans;
        stack<string> answers;
        if(s1.length()>=s2.length()) {
            answers = bigMul(s1, s2);
        }
        else if(s1.length()<s2.length()) {
            answers = bigMul(s2, s1);
        }
        while(answers.size()!=1) {
            string ss1=answers.top();
            answers.pop();
            string ss2=answers.top();
            answers.pop();
            string ans;
            if(ss1.length()>=ss2.length()) {
                ans = bigSum(ss1, ss2);
            }
            else if(ss1.length()<ss2.length()) {
                ans = bigSum(ss2, ss1);
            }
            // cout<<"add: "<<ans<<endl;
            answers.push(ans);
        }
        finalans = answers.top();

        int count = 0;
        for(int i=0;i<finalans.length();i++) {
            if(finalans.at(i)=='0') {
                count++;
            }
        }
        // cout<<"Ans: ";
        if(count==finalans.length()) {
            cout<<"0"<<endl;
        }
        else {
            for(int i=0;i<finalans.length();i++) {
                cout<<finalans.at(i);
            }
            cout<<endl;
        }
    }
}