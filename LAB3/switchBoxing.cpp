# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int q=0;q<t;q++) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(i+1);
        }
        vector<pair<int, int>> pairs;
        for(int i=0;i<n/2;i++) {
            int pin1, pin2;
            cin>>pin1>>pin2;
            pair<int, int> pair;
            if(pin2>=pin1) {
                pair.first = pin1;
                pair.second = pin2;
            }
            else {
                pair.first = pin2;
                pair.second = pin1;
            }
            pairs.push_back(pair);
        }
        bool isPossible=true;
        for(int i=0;i<pairs.size();i++) {
            for(int j=0;j<i;j++) {
                if((pairs.at(i).first<pairs.at(j).first && pairs.at(i).second>pairs.at(j).first && pairs.at(i).second<pairs.at(j).second)
                || (pairs.at(i).first>pairs.at(j).first && pairs.at(i).first<pairs.at(j).second && pairs.at(i).second>pairs.at(j).second)) {
                    isPossible = false;
                    break;
                }
            }
            if(!isPossible) {
                break;
            }
        }
        if(isPossible) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}