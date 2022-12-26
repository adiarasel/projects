#include <iostream>
#include <algorithm>
using namespace std;
struct hay
{
    int width;
    int breadth;
};
hay bales[21];
int n, ans = -1;
bool comp(hay a, hay b){
    if(a.width < b.width){
        return true;
    }
    else{
        return false;
    }
}
void findans(int x, int maxbreadth, int height)
{
    if(x == n){
        ans = max(ans, height);
        return;
    }
    if(bales[x].breadth < maxbreadth){
        findans(x+1, maxbreadth, height);
    }
    else{
        findans(x+1, bales[x].breadth, height+1);
        findans(x+1, maxbreadth, height);
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>bales[i].width>>bales[i].breadth;
    }
    sort(bales, bales+n, comp);
    findans(0,0,0);
    cout<<ans<<endl;
}