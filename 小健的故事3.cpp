#include <iostream>
#include <vector>
using namespace std;

int N,M;
#define num 5003
int P[num];
int A[num];
int mon;

int deal(int N,int* P,int* A) {
    mon=0;
    for (int i = 0; i < M; i++) {
      int tmp = N < A[i]? N : A[i];
      mon += tmp * P[i];
      N -= tmp;
    }
    return mon;
}

void sort(int* a,int* b) {
    for(int m = 1; m < M; m++){
        int t = a[m];
        int q = b[m];
        for(int j=m;a[j]<a[j-1];j--){
            a[j]=a[j-1];
            a[j-1]=t;
            b[j]=b[j-1];
            b[j-1]=q;
        }
    }
}

int main(int argc, char const *argv[]) {

    while (cin >> N >> M) {
        for (int i = 0; i < M; i++) {
            cin >> P[i];
            cin >> A[i];
        }
        sort(P,A);
        deal(N,P,A);
        cout << mon << endl;
    }

    return 0;
}


