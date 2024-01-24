# include <iostream>
# include <stack>
using namespace std;

int main() {
    bool terminate = false;
    while(!terminate) {
        bool exit2 = false;
        while(true) {
            int n;
            if(!exit2) {
                cin>>n;
            }
            if(n==0) {
                terminate=true;
                break;
            }
            int arr1[n];
            int arr3[n];
            stack<int> s2;
            for(int i=0;i<n;i++) {
                arr1[n-1-i] = i+1;
            }
            for(int i=0;i<n;i++) {
                int ele;
                cin>>ele;
                if(i==0 and ele==0) {
                    exit2 = false;
                    break;
                }
                else {
                    exit2 = true;
                }
                arr3[i] = ele;
            }
            if(!exit2) {
                cout<<endl;
                break;
            }
            bool isPossible = false;
            // bool exit=false;
            int arr1i = n-1;
            int arr3i = 0;
            while(true) {
                if(arr3i==n) {
                    isPossible = true;
                    break;
                }
                if(arr1[arr1i]<arr3[arr3i] && arr1i>=0) {
                    s2.push(arr1[arr1i]);
                    arr1i--;
                }
                else if(arr1[arr1i]==arr3[arr3i] && arr1i>=0) {
                    arr1i--;
                    arr3i++;
                }
                else if(!s2.empty() && s2.top()==arr3[arr3i]) {
                    arr3i++;
                    s2.pop();
                }
                else {
                    break;
                }
            }
            if(exit2) {
                if(isPossible) {
                    cout<<"YES"<<endl;
                }
                else {
                    cout<<"NO"<<endl;
                }
            }
        }
        if(terminate) {
            break;
        }
    }
}