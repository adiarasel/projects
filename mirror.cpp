#include <iostream>
using namespace std;
// direction: 0 1 2 3
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int bounce1[] = {3, 2, 1, 0};
int bounce2[] = {1, 0, 3, 2};
int n, m;
string a[1010];
int trace(int r, int c, int dir) {
    int result = 0;
    while(0 <= r && r < n && 0 <= c && c < m) {
        if(a[r][c] == '/')
            dir = bounce1[dir];
        else
            dir = bounce2[dir];
        r += dr[dir];
        c += dc[dir];
        result++;
    }
    return result;
}
int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int best = 0;
    for(int i = 0; i < n; i++) {
        best = max(best, trace(i, 0, 1));
        best = max(best, trace(i, m - 1, 3));
    }
    for(int i = 0; i < m; i++) {
        best = max(best, trace(0, i, 0));
        best = max(best, trace(n - 1, i, 2));
    }
    cout << best << endl;
}