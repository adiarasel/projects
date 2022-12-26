#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
#define FoR(i, n) for(int i=1; i<=n; i++)
using namespace std;

int n, x;
bool cards[100001];
int elsie[50000];
vector <int> bessie;
int main()
{
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    
    fin>>n;
    FOR(i , n){
        fin>>elsie[i];
        cards[elsie[i]] = true;
    }
    FoR(i , 2 * n){
        if(!cards[i]){
            bessie.push_back(i);  
        }
    }
    sort(elsie, elsie + n); // no need to sort bessie's since already sorted
    int elsie_index = n-1, ans = 0;
    int bessin = n-1;
    
    for(int elsin = n-1; elsin >= 0; elsin--){
        if (bessin < 0) {
            break;
        }
        if(bessie[bessin]> elsie[elsin]){
            bessin--;
            ans++;
        }
        
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}