#include <iostream>
using namespace std;
int main()
{
    string names[3]={
        "cat",
        "dog",
        "bin",
    };
    for(int i=0; i<3; i++){
        for(int j=2; j>=0; j--){
            cout<<names[i][j];
        }
        cout<<endl;
    }
    cout<<"eeeee"<<" ";
}
/*void leftwardshift(int shiftamt, int piece)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            x[i-shiftamt][j] = x[i][j];
        }
    }
}
void rightwardshift(int shiftamt, char x[8][8])
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            x[i+shiftamt][j] = x[i][j];
        }
    }
}
void upwardshift(int shiftamt, char x[8][8])
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            x[i][j-shiftamt] = x[i][j];
        }
    }
}
void downwardshift(int shiftamt, char x[8][8])
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            x[i][j+shiftamt] = x[i][j];
        }
    }

bool supimpandcomp(  )
{
    char c[8][8];
    int counter=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]=='#'){
                c[i][j]='#';
            }
            if(b[i][j]=='#'){
                c[i][j]='#';
            }
            if(a[i][j]=='.' && b[i][j]=='.'){
                c[i][j]='.';
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(c[i][j]!=orig[i][j]){
                return false; //not equal; case doesn't work
            }
        }
    }
    return true; //equal, case works
    
}*/