# include <iostream>
# include <time.h>
using namespace std;

// 0 1 1 2 3 5 8 13 ...

long int fibR(int n) {
    if (n==1) {
        return 0;
    }
    if(n==2) {
        return 1;
    }
    else {
        long sum = fibR(n-1)+fibR(n-2);
        return sum;
    }
}

long int fibL(int n) {
    int first = 0;
    int second = 1;
    long int third;
    for(int i=0;i<n-2;i++) {
        third = first+second;
        first = second;
        second = third;
    }
    return third;
}

int main() {
    for(int i=0;i<5;i++) {
        int n;
        cin>>n;
        clock_t tR;
        tR = clock();
        cout<<"Ans: "<<fibR(n)<<endl;
        tR = clock() - tR;
        cout<<"Time Taken for Recurssion: "<<(((double)tR)/CLOCKS_PER_SEC)*1000000<<" micro-s"<<endl; 
        clock_t tL;
        tL = clock();
        long int number = fibL(n);
        tL = clock() - tL;
        cout<<"Time Taken for Loop: "<<(((double)tL)/CLOCKS_PER_SEC)*1000000000<<" ns"<<endl; 
    }
}