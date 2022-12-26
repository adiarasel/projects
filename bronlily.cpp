#include <iostream>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int m, n, m1, m2;
struct thing{
    int r; //row
    int c; //col
    int d; //dist
};
queue<thing> q;
int pond[32][32];
bool visited[32][32];
int main()
{
    int strow, stcol;
    cin>>m>>n>>m1>>m2;
    FOR(i, m){
        FOR(j, n){
            cin>>pond[i][j];
            if(pond[i][j] == 3){
                strow = i;
                stcol = j;
            }
        }
    }
    int row, col, dist;
    thing re;
    re.r = strow;
    re.c = stcol;
    re.d = 0;
    q.push(re);
    while(!q.empty()){
        row = q.front().r;
        col = q.front().c;
        dist= q.front().d;
        q.pop();
        if(row <= m && col <= n && row >= 0 && col >= 0 && visited[row][col] == false 
        && (pond[row][col] == 1 || pond[row][col] == 3 || pond[row][col] == 4)){
            visited[row][col] = true;
            if(pond[row][col] == 4){
                cout<<dist<<endl;
                break;
            }
            thing a;
            a.d = dist + 1;
            a.r = row + m1;
            a.c = col + m2;
            q.push(a);
            a.r = row + m1;
            a.c = col - m2;
            q.push(a);
            a.r = row - m1;
            a.c = col + m2;
            q.push(a);
            a.r = row - m1;
            a.c = col - m2;
            q.push(a);
            a.r = row + m2;
            a.c = col + m1;
            q.push(a);
            a.r = row + m2;
            a.c = col - m1;
            q.push(a);
            a.r = row - m2;
            a.c = col + m1;
            q.push(a);
            a.r = row - m2;
            a.c = col - m1;
            q.push(a);
        }
    }
}
/*
4 5 1 2
1 0 1 0 1
3 0 2 0 4
0 1 2 0 0
0 0 0 1 0
*/