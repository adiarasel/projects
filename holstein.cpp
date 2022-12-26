#include <iostream>
#include <vector>
using namespace std;
int v, g;
int reqs[25], amounts[25], scoops[15][25]; 
bool elements[15];
vector<int> best;
vector<int> current;
void process()
{
    current.clear();
    for(int i=0; i<v; i++){
        amounts[i] = 0;
    }
    for(int i=0; i<g; i++){
        if(elements[i] == 1){
            current.push_back(i);
            for(int j=0; j<v; j++){
                amounts[j] += scoops[i][j];
            }
        }
        
    }
    bool ok=true;
    for(int j=0; j<v; j++){
        if(amounts[j] < reqs[j]){
            ok = false;
        }
    }
    if(!ok){
        return;
    }
    if(best.size() == 0){
        best=current;
        return;
    }
    if(best.size() < current.size()){
        return;
    }
    if(current.size() < best.size()){
        best = current;
        return;
    }
    for(int i=0; i<best.size(); i++){
        if(best[i] < current[i]){
            return;
        }
        if(current[i] < best[i]){
            best = current;
            return;
        }
    }
}
void subset(int e)
{
    if(e == g){
        process();
        return;
    }
    elements[e] = 1;
    subset(e+1);
    elements[e] = 0;
    subset(e+1);
}
int main()
{
    cin>>v;
    for(int i=0; i<v; i++){
        cin>>reqs[i];
    }
    cin>>g;
    for(int i=0; i<g; i++){
        for(int j=0; j<v; j++){
            cin>>scoops[i][j];
        }
    }
    subset(0);
    cout<< best.size()<<" ";
    for(int i=0; i< best.size(); i++){
        cout<<best[i] + 1<<" ";
    }
}