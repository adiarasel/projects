#include <iostream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, numopp;
bool found = false;
char board[31][31], dummy[31][31];
vector<pair<int, int> > ans;
void dfs(int row, int col, int num)
{
    int x;
    // cout<<" DFS being called"<<endl;
    if(found == true) return;
    if(num == numopp){
        found = true;
        x = ans.size();
        for(int i = 0; i<x; i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;;
        }
        // cout<<"about to return"<<endl;
        return;
    }
    if(row+2 <= n && row+2 > 0 && col+2 <= n && col+2 > 0){
        // cout<<"case 1 about to enter = "<<row<<" "<<col<< endl;
        if(dummy[row+1][col+1] == 'o'){
            // cout<<"case 1 "<<row<<" "<<col<< endl;
            dummy[row+1][col+1] = '+';
            ans.push_back(make_pair(row+2, col+2));
            dfs(row+2, col+2, num+1);
            dummy[row+1][col+1] = 'o';
            ans.pop_back();
        }
    }
    if(row+2 <= n && row+2 > 0 && col-2 <= n && col-2 > 0){
        // cout<<"case 2 about to enter = "<<row<<" "<<col<< endl;
        if(dummy[row+1][col-1] == 'o'){
            // cout<<"case 2 "<<row<<" "<<col<< endl;
            dummy[row+1][col-1] = '+';
            ans.push_back(make_pair(row+2, col-2));
            dfs(row+2, col-2, num+1);
            dummy[row+1][col-1] = 'o';
            ans.pop_back();
        }
    }
    if(row-2 <= n && row-2 > 0 && col+2 <= n && col+2 > 0){
        // cout<<"case 3 about to enter = "<<row<<" "<<col<< endl;
        if(dummy[row-1][col+1] == 'o'){
            // cout<<"case 3 "<<row<<" "<<col<< endl;
            dummy[row-1][col+1] = '+';
            ans.push_back(make_pair(row-2, col+2));
            dfs(row-2, col+2, num+1);
            dummy[row-1][col+1] = 'o';
            ans.pop_back();
        }
    }
    if(row-2 <= n && row-2 > 0 && col-2 <= n && col-2 > 0){
        // cout<<"case 4 about to enter = "<<row<<" "<<col<<" "<<num<< endl;
        // cout<<"dummy at this place is: "<<dummy[row-1][col-1]<<endl;
        if(dummy[row-1][col-1] == 'o'){
            // cout<<"case 4 "<<row<<" "<<col<<" "<<num<< endl;
            dummy[row-1][col-1] = '+';
            ans.push_back(make_pair(row-2, col-2));
            dfs(row-2, col-2, num+1);
            dummy[row-1][col-1] = 'o';
            ans.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            cin>>board[i][j];
            if(board[i][j] == 'o'){
                numopp++;
            }
        }
    }
    // cout<<n<<" "<<numopp<<endl;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            if(board[i][j] == 'K'){
                for(int l=1; l<=n; l++){
                    for(int k=1; k<=n; k++){
                        dummy[l][k] = board[l][k];
                    }
                }
                ans.clear();
                ans.push_back(make_pair(i, j));
                dfs(i, j, 0);
            }
        }
    }
    if(!found) cout<<"impossible"<<endl;
}
/*
for{8
-+-+-+-+
+-+-+-+-
-+-K-+-+
+-+-+-+-
-o-o-+-+
+-K-+-+-
-o-+-+-+
+-K-+-K-
4
-+-+
+-o-
-+-K
K-K-
5
-K-+-
+-o-K
-+-+-
+-o-K
-+-+-
}
*/