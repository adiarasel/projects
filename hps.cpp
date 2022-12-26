#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//ONE-INDEXED PROBLEM
//MAKE SURE YOU CHECK 6 TIMES
int numh, nump, nums;
char games[100002];
int n, preh[100003], prep[100003], pres[100003];
int main()
{
    cin>>n;
    char c;
    for(int i=1; i<=n; i++){
        cin>>c;
        games[i] = c;
        if(c == 'H'){
            numh++;
        }
        if(c == 'P'){
            nump++;
        }
        if(c == 'S'){
            nums++;
        }
    }
    for(int i=1; i<=n; i++){
        preh[i] = preh[i-1];
        prep[i] = prep[i-1];
        pres[i] = pres[i-1];
        if(games[i] == 'H') preh[i]++;
        if(games[i] == 'P') prep[i]++;
        if(games[i] == 'S') pres[i]++;
    }
    int sum = 0, maxsum = -1;
    for(int i=0; i<=n; i++){ //check for max in six loops/cases
        //if the dividing line is at i
        //check h to p
        if(pres[i] > 0){
            sum+=pres[i];
        }
        if(preh[i] < numh){
            sum+=numh - preh[i];
        }
        maxsum = max(sum ,maxsum);
        cout<<"i = "<<i<<" sum = "<<sum<<endl;
        sum = 0;
        //check h to s
        if(pres[i] > 0){
            sum+=pres[i];
        }
        if(prep[i] < nump){
            sum+=nump - prep[i];
        }
        maxsum = max(sum ,maxsum);
        sum = 0;
        //check p to h
        if(preh[i] > 0){
            sum+=preh[i];
        }
        if(pres[i] < nums){
            sum+=nums - pres[i];
        }
        //cout<<"i = "<<i<<" sum = "<<sum<<endl;
        maxsum = max(sum ,maxsum);
        sum = 0;
        //check p to s
        if(preh[i] > 0){
            sum+=preh[i];
        }
        if(prep[i] < nump){
            sum+=nump - prep[i];
        }
        //cout<<"i = "<<i<<" sum = "<<sum<<endl;
        maxsum = max(sum ,maxsum);
        sum = 0;
        //check s to h
        if(prep[i] > 0){
            sum+=prep[i];
        }
        if(pres[i] < nums){
            sum+=nums - pres[i];
        }
        //cout<<"i = "<<i<<" sum = "<<sum<<endl;
        maxsum = max(sum ,maxsum);
        sum = 0;
        //check s to p
        if(prep[i] > 0){
            sum+=prep[i];
        }
        if(preh[i] < numh){
            sum+=numh - preh[i];
        }
        // cout<<"i = "<<i<<" sum = "<<sum<<endl;
        maxsum = max(sum ,maxsum);
        sum = 0;
    }
    cout<<maxsum<<endl;
}