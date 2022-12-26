#include <iostream>
#include <cmath>
using namespace std;
int n, fjcombo[3], mrcombo[3], x, y, z;
bool ok(int a, int b)
{
    if(abs(a-b)<=2 || abs(a-b)>=n-2){
        return true;
    }
    return false;
}
int main()
{
    cin>>n;
    int ans=0;
    for(int i=0; i<3; i++){
        cin>>fjcombo[i];
    }
    for(int i=0; i<3; i++){
        cin>>mrcombo[i];
    }
    for(x=1; x<=n; x++){
        for(y=1; y<=n; y++){
            for(z=1; z<=n; z++){
                if(ok(x, fjcombo[0]) == true && ok(y, fjcombo[1]) == true && ok(z, fjcombo[2]) == true){
                    ans++;
                }
                else if(ok(x, mrcombo[0]) == true && ok(y, mrcombo[1]) == true && ok(z, mrcombo[2]) == true){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}