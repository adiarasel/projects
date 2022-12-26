#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int cereal[10000];
int f[10000], s[10000];
int n,m;
int eatcereal(int cow)
{
    if(cereal[f[cow]]==1){
        cereal[f[cow]]=0;
        cout<<"ENTERED FIRST CHOICE"<<endl;
        return 1;
    }
    if(cereal[s[cow]]==1 && cereal[f[cow]]==0){
        cereal[s[cow]]=0;
        cout<<"ENTERED SECOND CHOICE"<<endl;
        return 1;
    }
    if(cereal[s[cow]]==0 && cereal[f[cow]]==0){
        cout<<"NO FOOD FOR COW"<<endl;
        return 0;
    }
}

int main()
{
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");
    queue<int> cows;
    queue<int> dummy;
    fin>>n>>m;
    for(int i=0; i<n; i++){
        fin>>f[i]>>s[i];
    }
    for(int i=0; i<m; i++){
        cereal[i]=1;
    }
    for(int i=0; i<n; i++){
        cows.push(i);
        dummy.push(i);
    }
    int counter=0, sum=0;
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=0; j<counter;j++){
            dummy.pop();
        }
        for(int k=0; k<n-counter; k++){
            fout<<"sum before = "<<sum<<endl;
            fout<<"eatcereal = "<<eatcereal(dummy.front())<<endl;
            sum = sum + eatcereal(dummy.front());
            fout<<dummy.front()<<" "<<sum<<endl;
            dummy.pop();
        }
        fout<<"counter = "<<counter<<endl;
        counter++;
        for(int i=0; i<m; i++){
            cereal[i]=1;
        }
        if(dummy.empty()==true);
        else{
            while(dummy.empty()==false){
                dummy.pop();
            }
        }
        for(int i=0; i<n; i++){
            dummy.push(i);
        }
        fout<<"sum = "<<sum<<endl;
    }
}