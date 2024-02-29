# include <iostream>
# include <queue>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int q=0;q<t;q++) {
        int n, k;
        cin>>n>>k;
        queue<int> people;
        for(int i=0;i<n;i++) {
            people.push(i+1);
        }
        while(true) {
            if(people.size()==1) {
                break;
            }
            for(int i=0;i<k;i++) {
                people.push(people.front());
                people.pop();
            }
            people.pop();
        }
        cout<<people.front()<<endl;
    }
}