#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int firstt[1 << 16];
int sat[1 << 16];
int n;
long long b;
int main()
{
    cin>>n>>b;
    int sss = 0;
    FOR(i, n){
        int a;
        cin>>a;
        if (a == 1) {
            sss = sss | (1 << i);
        }
    }
    FOR(i, (1 << n)){
        firstt[i] = -1;
    }
    int t = 0;
    firstt[sss] = 0;
    sat[0] = t;
    while ((long long) t < b) {
        t++;
        int rot = (sss << 1);
        rot = (rot | (rot >> n)) & ((1 << n) - 1);
        sss = sss ^ rot;
        if (firstt[sss] == -1) {
            firstt[sss] = t;
            sat[t] = sss;
        } else {
            int cyclen = t - firstt[sss];
            int t1 = firstt[sss] + (int) ((b - (long long) firstt[sss]) % (long long) cyclen);
            sss = sat[t1];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", (sss >> i) & 1);
    }
}
