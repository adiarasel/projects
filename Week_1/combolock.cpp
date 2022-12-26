#include <iostream>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
#define For(i) for(int i=-2; i<=2; i++)
using namespace std;

int n, a, b, c, d, e, f;
struct thing{
    int x;
    int y;
    int z;
};  
int cycle(int x, int j){ // checked
    if(x + j > n){
        return (x+j) % n;
    }
    else if(x + j <= 0){
        return (x+j) + n;
    }
    else return x + j;
}
thing first[250], second[250];
int main()
{
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    fin>>n;
    fin>>a>>b>>c>>d>>e>>f;
    int sum = 0;
    int counter = 0;
    For(j){
        For(k){
            For(l){
                first[counter].x = cycle(a,j);
                first[counter].y = cycle(b,k);
                first[counter].z = cycle(c,l);
                counter++;
            }
        }
    }
    counter = 0;
    For(j){
        For(k){
            For(l){
                second[counter].x = cycle(d,j);
                second[counter].y = cycle(e,k);
                second[counter].z = cycle(f,l);
                counter++;
            }
        }
    }
    counter = 0;
    FOR(i ,125){
        for(int j = i + 1; j < 125; j++){
            if(first[i].x == first[j].x && first[i].y == first[j].y && first[i].z == first[j].z && i != j){
                first[j].x = 0;
                first[j].y = 0;
                first[j].z = 0;
            }
            if(second[i].x == second[j].x && second[i].y == second[j].y && second[i].z == second[j].z && i!= j){
                second[j].x = 0;
                second[j].y = 0;
                second[j].z = 0;
            }
            
        }
    }
    FOR(i, 250){
        if(first[i].x != 0) sum++;
        if(second[i].x != 0) sum++;
    }
    // cout<<sum<<endl;
    FOR(i ,125){
        FOR(j, 125){
            if(first[i].x == second[j].x && first[i].y == second[j].y && first[i].z == second[j].z){
                sum--;
            }
        }
    }
    if(n == 1) sum = 1; // only one way to do one number
    if(n == 4){ // IT'S LITERALLY THE SAME ARRAY
        sum = 0;
        FOR(i, 250){
            if(first[i].x != 0) sum++;
        }
    }
    fout<<sum<<endl;
    fin.close();
    fout.close();
    return 0;
}