# include <iostream>
# include <stack>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int q=0;q<t;q++) {
        int r, c;
        cin>>r>>c;
        bool ispathPossible = false;
        int arr[r][c];
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>arr[i][j];
            }
        }

        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;

        pair<int, int> source, target;
        source.first = r1; source.second = c1;
        target.first = r2; target.second = c2;
        
        int i = source.first;
        int j = source.second;
        stack<pair<int, int>> otherPaths;
        while(true) {
            if(i==target.first && j==target.second) {
                ispathPossible = true;
                break;
            }
            if(i+1<r && j+1<c && arr[i+1][j]==1 && arr[i][j+1]==1) {
                pair<int, int> coor;
                coor.first = i+1;
                coor.second = j;
                otherPaths.push(coor);
                j++;
            }
            else if(i+1<r && arr[i+1][j]==1) {
                i++;
            }
            else if(j+1<c && arr[i][j+1]==1) {
                j++;
            }
            else if((i+1<r && j+1<c && arr[i+1][j]==0 && arr[i][j+1]==0) || (i+1<r && arr[i+1][j]==0 && j+1==c) || (j+1<c && arr[i][j+1]==0 && i+1==r) || (i+1==r && j+1==c)) {
                if(!otherPaths.empty()) {
                    i=otherPaths.top().first;
                    j=otherPaths.top().second;
                    otherPaths.pop();
                }
                else {
                    break;
                }
            }
            else if((i+1==r || j+1==r) && otherPaths.empty()) {
                break;
            }
        }
        if(ispathPossible) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
}