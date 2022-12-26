#include <iostream>
#include <algorithm>
using namespace std;
int n, x, y, z;
int a[20001], b[20001];
int main()
{
    cin >> n >> x >> y >> z;
    for (int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    a[n] = 1e9 + 7;
    b[n] = 1e9 + 7;
    int i = 0, j = 0;
    int curamt = n * x; // all the cows are cold
    int ans = 0;
    while (i < n || j < n) {
        if (a[i] <= b[j]) {
            curamt += y - x;
            i++;
        } 
        else {
            curamt += z - y;
            j++;
        }
        if (curamt > ans) 
            ans = curamt;
    }
    cout << ans << endl;
}