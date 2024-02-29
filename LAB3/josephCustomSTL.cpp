#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 1000

class Queue{
    private:
        int frontIndex=0;
        int rearIndex=0;
        int count=0;
        int data[SIZE];
    public:
        void insert(int element);
        void deletEelement();
        int front();
        int size();
};

void Queue::insert(int element){
    if(count<SIZE)
    { 
        data[rearIndex]=element;
        rearIndex=(rearIndex+1)%SIZE;
        count++;
    }
}



void Queue::deletEelement(){
    if(count>0)
    {
        frontIndex=(frontIndex+1)%SIZE;
        count--;
    }
}

int Queue::front(){
    return data[frontIndex];
}


int Queue::size(){
    return count;
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Queue q;

       int i=1;
        while(i<=n){
            q.insert(i);
            i++;
        }
        while(q.size()>1){
            int  j=k;
            while(j--){
                int x = q.front();
                q.deletEelement();
                q.insert(x);
            }
            q.deletEelement();
        }
        
        cout<<q.front()<<endl;
    }
    return 0;
}