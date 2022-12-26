#include <iostream>
#include <fstream>
using namespace std;
int team[12], skill[12], counter[4], ans= 10000000;
int process()
{
    int minsum = 10000000;
    int maxsum = 0;
    int cursum;
    for(int i=0; i<4; i++){
        cursum = 0;
        for(int j=0; j<12; j++){
            if(team[j]==i){
                cursum+=skill[j];
            }
        }
        minsum = min(minsum, cursum);
        maxsum = max(maxsum, cursum);
    }
    return maxsum-minsum;
}
void balteam(int x)
{
    if(x  == 12){
        ans = min(ans, process());
        return;
    }
    for(int i=0; i<4; i++){
        if(counter[i] != 3){
            team[x] = i;
            counter[i]++;
            balteam(x+1);
            counter[i]--;
        }
    }
}
int main()
{
    ifstream fin("bteams.in");
    ofstream fout("bteams.out");
    for(int i=0; i<12; i++){
        fin>>skill[i];
    }
    balteam(0);
    fout<<ans<<endl;
}