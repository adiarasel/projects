#include <iostream>
#include <fstream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
#define l first
#define r second
using namespace std;
int n, m, k, loop1[1008], visited[1004], cycle = 1, star;
vector<int> seq;
pair<int, int> leftright[1000];
char dirs[503], dummy;
int main()
{
    ifstream fin("cruise.in");
    ofstream fout("cruise.out");
    fin>>n>>m>>k;
    FOR(i, n){
        fin>>leftright[i].l>>leftright[i].r;
    }
    FOR(i, m){
        fin>>dirs[i];
    }
    //creates corresponding nodes for one iteration
    int node = 1;
    for(int i = 1; i <= n; i++){// LOOP1 IS ONE INDEXED.
        node = i;
        FOR(j, m){
            if(dirs[j] == 'L'){
                node = leftright[node-1].l;
            }
            else{
                node = leftright[node-1].r;
            }
            // cout<<"node of"<<i<<" = "<<node<<endl;
        }
        loop1[i] = node;
    }
    // for(int i = 1; i <= n ; i++){
    //     cout<<loop1[i]<<endl;
    // }
    // FOR(i, m){
    //     cout<<dirs[i];
    // }
    int curnode = 1;
    while(true){
        if(visited[curnode] != 1){ // runs thru loops to find a cycle
            // cout<<"HIIII"<<endl;
            visited[curnode] = 1;
            seq.push_back(curnode);
            curnode = loop1[curnode];
        }
        if(visited[curnode] == 1){
            seq.push_back(curnode);
            int len = seq.size();
            FOR(i, 2 * n){
                // cout<<"seq[i] = "<<seq[i]<<" and i = "<<i<<endl;
                if(seq[len - 1] == seq[i] && len-1 != i){
                    // cout<<"len - 1 = "<<len - 1<<" and i = "<<i<<endl;
                    star = min(i, len-1);
                    cycle = len-star-1;
                    break;
                }
            }
            break;
        }
    }
    // cout<<k<<" "<<star<<" "<<cycle<<endl;
    int dummy = (k - star) % cycle;
    curnode = seq[star];
    // cout<<dummy<<endl;
    FOR(i, dummy){
        curnode = loop1[curnode];
    }
    fout<<curnode<<endl;
    fin.close();
    fout.close();
    return 0;
}
/*
50 10 10
6 4
42 48
2 41
40 8
17 29
28 7
34 46
4 9
36 27
9 37
28 32
22 10
30 48
16 31
11 33
36 3
14 39
45 5
46 13
34 23
29 6
3 38
44 30
21 15
41 50
12 9
30 24
45 6
19 39
11 14
2 46
39 22
14 9
48 43
16 50
30 9
32 2
25 24
3 38
11 24
25 3
4 19
9 22
10 19
37 13
14 25
36 29
33 34
21 48
33 2
L L R L L R R R R R
*/