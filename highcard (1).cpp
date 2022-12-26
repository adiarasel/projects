#include <iostream>
using namespace std;
bool elscard[100004];
int n, counter=0, ans=0;
int main()
{
    cin>>n;
    int x;
    for(int i=1; i<=n; i++){
        cin>>x;
        elscard[x] = true;
    }
    for(int i=1; i <= 2 * n; i++){
        if(elscard[i] == true){
            counter++;
        }
        if(elscard[i] == false && counter != 0){
            counter--;
            ans++;
        }
    }
    cout<<ans<<endl;
}