#include <iostream>
using namespace std;
int n;
int rec(int left,int right) {
    if (left==right) return 0;
    if (left+1==right) return left*right;
    int mid=(left+right)/2;
    return  rec(left,mid)+rec(mid+1,right);
}
int main () {
cin >> n;
cout << rec(1,n) << endl;
}