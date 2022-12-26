#include <iostream>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m;
char maze[301][301];
bool visited[301][301];
struct thing{
    int row;
    int col;
    int mov;
};
int slides[26][4], freq[26];
queue<thing> q;
int main()
{
    cin>>n>>m;
    int strow, stcol;
    FOR(i ,n){
        FOR(j, m){
            cin>>maze[i][j];
            if(maze[i][j] == '@'){
                strow = i;
                stcol = j;
            }
            if('A' <= maze[i][j] && maze[i][j] <= 'Z' && freq[maze[i][j] - 'A'] == 0){
                slides[maze[i][j] - 'A'][0] = i;
                slides[maze[i][j] - 'A'][1] = j;
                freq[maze[i][j] - 'A']++;
            }
            if('A' <= maze[i][j] && maze[i][j] <= 'Z' && freq[maze[i][j] - 'A'] == 1){
                slides[maze[i][j] - 'A'][2] = i;
                slides[maze[i][j] - 'A'][3] = j;
                freq[maze[i][j] - 'A']++;
            }
        }
    }
    thing cur, temp;
    visited[strow][stcol] = true;
    temp.row = strow;
    temp.col = stcol;
    temp.mov = 0;
    q.push(temp);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(maze[cur.row][cur.col] == '='){
            cout<<cur.mov<<endl;
            break;
        }
        if(maze[cur.row][cur.col + 1] == '.'){ // first neighbor
            temp.row = cur.row;
            temp.col = cur.col + 1;
            temp.mov = cur.mov + 1;
            q.push(temp);
        }
        else if('A' <= maze[cur.row][cur.col + 1] && maze[cur.row][cur.col + 1] <= 'Z'){
            if (slides[maze[cur.row][cur.col + 1] - 'A'][0] == cur.row && slides[maze[cur.row][cur.col + 1] - 'A'][1] == cur.col){
                visited[maze[cur.row][cur.col + 1] - 'A'][2]][maze[cur.row][cur.col + 1] - 'A'][3]] = true;
            }
        }
        if(maze[cur.row + 1][cur.col] == '.'){ // second neighbor
            temp.row = cur.row + 1;
            temp.col = cur.col;
            temp.mov = cur.mov + 1;
            q.push(temp);
        }
        else if('A' <= maze[cur.row + 1][cur.col] && maze[cur.row + 1][cur.col] <= 'Z'){
            
        }
        if(maze[cur.row][cur.col - 1] == '.'){ // second neighbor
            temp.row = cur.row;
            temp.col = cur.col - 1;
            temp.mov = cur.mov + 1;
            q.push(temp);
        }
        else if('A' <= maze[cur.row][cur.col - 1] && maze[cur.row][cur.col - 1] <= 'Z'){
            
        }
        if(maze[cur.row - 1][cur.col] == '.'){ // second neighbor
            temp.row = cur.row - 1;
            temp.col = cur.col;
            temp.mov = cur.mov + 1;
            q.push(temp);
        }
        else if('A' <= maze[cur.row - 1][cur.col] && maze[cur.row - 1][cur.col] <= 'Z'){
            
        }
    }
}