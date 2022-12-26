#include <iostream>
#define FOR(i, n) for(int i=0; i<n; i++) // PREFIX SUMS
#define A first
#define B second
using namespace std;
int n, q;
struct pre{
    int hol; // # holsteins at this point, 1
    int gue; // # guernseys at this point, 2
    int jer; // # jerseys at this point  , 3
};
pre pref[100004];
int cows[100000];
pair<int, int> queries[100000];
int main()
{
    cin>>n>>q;
    int a, b, c;
    FOR(i, n){
        cin>>cows[i];
    }
    FOR(i, q){
        cin>>queries[i].A>>queries[i].B;
    }
    for(int i=1; i<=n; i++){
        if(cows[i-1] == 1){
            pref[i].hol = pref[i-1].hol + 1;
            pref[i].gue = pref[i-1].gue;
            pref[i].jer = pref[i-1].jer;
        }
        if(cows[i-1] == 2){
            pref[i].gue = pref[i-1].gue + 1;
            pref[i].hol = pref[i-1].hol;
            pref[i].jer = pref[i-1].jer;
        }
        if(cows[i-1] == 3){
            pref[i].jer = pref[i-1].jer + 1;
            pref[i].hol = pref[i-1].hol;
            pref[i].gue = pref[i-1].gue;
        }
    }
    for(int i=0; i<q; i++){
        cout<<pref[queries[i].B].hol - pref[queries[i].A - 1].hol<<" ";
        cout<<pref[queries[i].B].gue - pref[queries[i].A - 1].gue<<" ";
        cout<<pref[queries[i].B].jer - pref[queries[i].A - 1].jer;
        cout<<endl;
    }
}