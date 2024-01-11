# include <iostream>
using namespace std;

class relation
{
private:
    /* data */
    int setSize;
    int** arr;
public:
    void init(int n) {
        setSize = n+1;
        arr = new int*[n+1];
        for(int i=0;i<n+1;i++) {
            arr[i] = new int[n+1];
            for(int j=0;j<n+1;j++) {
                arr[i][j] = 0;
            }
        }
    }
    void add(int a, int b) {
        arr[a][b] = 1;
    }
    bool isReflexive() {
        for(int i=0;i<setSize;i++) {
            if(arr[i][i]!=1) {
                return false;
            }
        }
        return true;
    }
    bool isSymmetric() {
        for(int i=0;i<setSize;i++) {
            for(int j=0;j<setSize;j++) {
                if(arr[i][j]!=arr[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
    void display() {
        for(int i=0;i<setSize;i++) {
            for(int j=0;j<setSize;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    ~relation();
};

// relation::relation(/* args */)
// {
// }

relation::~relation()
{
    for(int i=0;i<setSize;i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


int main() {
    relation R;
    R.init(5);
    R.display();
    R.add(1,1);
    R.add(2,3);
    R.add(3,2);
    R.add(4,4);
    R.display();
    cout<<R.isSymmetric()<<endl;
    cout<<R.isReflexive()<<endl;
}