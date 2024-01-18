# include <iostream>
using namespace std;

class sortedArray
{
private:
    /* data */
    int sizee;
    int count=0;
    int *arr;
    int eleIndex = -1;
public:
    ~sortedArray();
    void reserve(int k) {
        sizee = k;
        arr = new int[sizee];
    }
    int size() {
        return count;
    }
    void insert(int ele) {
        if(count<sizee) {
            arr[count] = ele;
            count++;
        }
        else {
            cout<<"Limit Reached"<<endl;
        }
        
    }
    bool search(int ele ) {
        for(int i=0;i<count;i++) {
            if(arr[i]==ele) {
                eleIndex = i;
                return true;
            }
        }
        return false;
    }
    void delet(int ele) {
        if(search(ele)) {
            for(int i=eleIndex;i<count-1;i++) {
                arr[i] = arr[i+1];
            }
            count--;
        }
        else {
            cout<<"Element Not Found"<<endl;
        }
    }
    void display() {
        for(int i=0;i<count;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


// sortedArray::sortedArray(int n) {
//     arr = new int[n];
// }

sortedArray::~sortedArray() {
    delete[] arr;
}


int main() {
    sortedArray myArray;
    myArray.reserve(3);
    cout<<myArray.size()<<endl;
    myArray.insert(71);
    myArray.insert(43);
    myArray.insert(97);
    myArray.insert(197);
    myArray.insert(917);
    cout<<myArray.size()<<endl;
    myArray.display();
    myArray.delet(32);
    myArray.display();
    cout<<myArray.size()<<endl;
}