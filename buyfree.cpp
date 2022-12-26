#include <iostream>
#include <algorithm>
using namespace std;
int n, m, counter, ans;
pair<int, int> haybales[20002]; 
// first number is value of haybale
// second number is either 0 or 1
// 0 is high-quality, 1 is low-quality
bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b.first){
        return true;
    }
    else{
        if(a.first == b.first){
            if(a.second < b.second){
                return true;
            }
            return false;
        }
        return false;
    }
}
int main()
{
    cin>>n>>m;
    int x;
    for(int i=1; i<= n + m; i++){
        cin>>haybales[i].first;
        if(i <= n){
            haybales[i].second = 0;
        }
        else{
            haybales[i].second = 1;
        }
    }
    sort(haybales + 1, haybales + n + m + 1, comp);
    for(int i=1; i <= n + m; i++){
        if(haybales[i].second == 1){
            counter++;
        }
        if(haybales[i].second == 0 && counter != 0){
            counter--;
            ans++;
        }
    }
    cout<<ans + n<<endl;
}