#include <iostream>
#include <algorithm>
using namespace std;
int n, q, haybales[100001], A[100001], B[100001];
int UB(int x){
    int L=0,  R=n, mid;
    while (L<R){
        mid = (R+L)/2; // <-------------- This is integer division
        if  (x >= haybales[mid]){
            L = mid + 1;
        }
        else{
            R = mid;
        }
    }
    return L;
}
int LB(int x){
    int L=0,  R=n, mid;
    while (L<R){
        mid = (R+L)/2; // <-------------- This is also integer division
        if  (x <= haybales[mid]){
            R = mid;
        }
        else {
            L = mid + 1;
        }
    }
    return R; //<----At this point since L and R are equal you can return either one
}
int main()
{
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>haybales[i];
    }
    sort (haybales, haybales + n);
    for(int j=0; j<q; j++){
        cin>>A[j]>>B[j];
    }
    cout<<endl<<endl;
    for(int i=0; i<q; i++){
        cout<< UB(B[i]) - LB(A[i]) <<endl;
    }
}
/* 4 6
3 2 7 5
2 3
2 4
2 5
2 7
4 6
8 10 */