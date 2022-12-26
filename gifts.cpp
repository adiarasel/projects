#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long b;
struct item
{
    int p;
    int s;
};
item gifts[1003];
bool comp(item a, item b)
{
    if(a.p + a.s < b.p + b.s){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    cin>>n>>b;
    for(int i=0; i<n; i++){
        cin>>gifts[i].p>>gifts[i].s;
    }
    sort(gifts, gifts + n, comp);
    long long curmon = 0;
    int ans=0, j;
    for(int i=0; i<n; i++){
        curmon += gifts[i].p / 2 + gifts[i].s;
        if(curmon > b){
            continue;
        }
        for(j=0; j<n; j++){
            //cout<<j<<" "<<curmon<<" "<<ans<<endl;
            if(i != j){
                curmon += gifts[j].p + gifts[j].s;
            }
            if(curmon > b){
                break;
            }
        }
        //cout<<ans<<endl;
        if(1+j > ans && i > j){
            ans = 1+j;
        }
        if(j > ans && j > i){
            ans = j;
        }
        curmon = 0;
    }
    cout<<ans<<endl;
}