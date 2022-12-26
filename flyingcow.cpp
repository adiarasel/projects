#include <iostream>
#include <queue>
using namespace std;
int n;
queue<pair<int, int> > q; //1st is pos, 2nd is # moves
bool visited[2000001];
int main()
{
    int n;
    cin>>n;
    pair<int, int> a, b;
    a.first = 1;
    a.second = 0;
    q.push(a);
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        if (p.first > 2 * n || p.first < 1 || visited[p.first]) continue;
        visited[p.first] = true;
        if(p.first == n){ // is number the answer?
            cout<<p.second<<endl;
            break;
        }
        b.first = p.first * 3;
        b.second = p.second + 1;
        q.push(b);
        b.first = p.first + 1;
        q.push(b);
        b.first = p.first - 1;
        q.push(b);
    }
}