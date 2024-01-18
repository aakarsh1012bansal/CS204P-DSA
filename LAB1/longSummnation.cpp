# include <iostream>
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
    return ans;
}

int main() {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    string ans;
    if(s1.length()>=s2.length()) {
        ans = bigSum(s1, s2);
    }
    else if(s1.length()<s2.length()) {
        ans = bigSum(s2, s1);
    }
    
    int count = 0;
    for(int i=0;i<ans.length();i++) {
        if(ans.at(i)=='0') {
            count++;
        }
    }
    cout<<"Ans: ";
    if(count==ans.length()) {
        cout<<"0"<<endl;
    }
    else {
        for(int i=ans.length()-1;i>=0;i--) {
            cout<<ans.at(i);
        }
        cout<<endl;
    }
}