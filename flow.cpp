#include <iostream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, t1, t2, t3, a[53][53], k=52; // a is the adjmat
char ch1, ch2;
void cut(int pos)
{
    if(pos == 0 || pos == 25) return; //edge nodes
    FOR(i, k){
        if(a[pos][i] > 0){
            return;
        }
    }
    FOR(i, k){
        if(a[i][pos]>0){
            a[i][pos] = 0;
            cut(i);
        }
    }
}
void reduce(int pos)
{
    if(pos == 0 || pos == 25) return;
    int parent = 0, child = 0, parentofpos, childofpos;
    FOR(i, k){
        if(a[i][pos] > 0){
            parent++;
            parentofpos = i;
        }
        if(a[pos][i] > 0){
            child++;
            childofpos = i;
        }
    }
    if(parent != 1 || child != 1) return;
    a[parentofpos][childofpos] += min(a[parentofpos][pos], a[pos][childofpos]);
    a[parentofpos][pos] = 0; a[pos][childofpos] = 0;
    reduce(parentofpos);
    reduce(childofpos);
}
int main()
{
    cin>>n;
    FOR(i, n){
        cin>>ch1>>ch2>>t3;
        if(ch1 >= 'A' && ch1 <= 'Z'){
            t1 = ch1 - 'A';
        }
        else{
            t1 = ch1 - 'a' + 26;
        }
        if(ch2 >= 'A' && ch2 <= 'Z'){
            t2 = ch2 - 'A';
        }
        else{
            t2 = ch2 - 'a' + 26;
        }
        a[t1][t2] += t3;
    }
    FOR(i, k){
        cut(i);
    }
    FOR(i, k){
        reduce(i);
    }
    cout<<a[0][25]<<endl;
}
/*
5
A B 3
B C 3
C D 5
D Z 4
B Z 6
*/