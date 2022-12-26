#include <iostream>
#include <algorithm>
#include <cmath>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int cloc[3][3], dummy[3][3], counter;
void func1()
{
    FOR(i, 2){
        FOR(j, 2){
            dummy[i][j] = (dummy[i][j] + 1) % 4;
        }
    }
}
void func2()
{
    FOR(i, 3){
        dummy[0][i] = (dummy[0][i] + 1) % 4;
    }
}
void func3()
{
    FOR(i,2){
        for(int j=1; j<3; j++){
            dummy[i][j] = (dummy[i][j] + 1) % 4;
        }
    }
}
void func4()
{
    FOR(i, 3){
        dummy[i][0] = (dummy[i][0] + 1) % 4;
    }
}
void func5()
{
    dummy[0][1] = (dummy[0][1] + 1) % 4;
    FOR(i, 3){
        dummy[1][i] = (dummy[1][i] + 1) % 4;
    }
    dummy[2][1] = (dummy[2][1] + 1) % 4;
}
void func6()
{
    FOR(i, 3){
        dummy[i][2] = (dummy[i][2] + 1) % 4;
    }
}
void func7()
{
    for(int i=1; i<3; i++){
        FOR(j, 2){
            dummy[i][j] = (dummy[i][j] + 1) % 4;
        }
    }
}
void func8()
{
    FOR(i, 3){
        dummy[2][i] = (dummy[2][i] + 1) % 4;
    }
}
void func9()
{
    for(int i=1; i<3; i++){
        for(int j=1; j<3; j++){
            dummy[i][j] = (dummy[i][j] + 1) % 4;
        }
    }
}
int main()
{
    FOR(i, 3){
        FOR(j, 3){
            cin>>cloc[i][j];
            cloc[i][j] = (cloc[i][j]%12)/3;
            dummy[i][j] = cloc[i][j];
        }
    }
    FOR(i1,4){ // switch 1
        FOR(i2,4){ // switch 2
            FOR(i3,4){ // switch 3
                FOR(i4,4){ // switch 4
                    FOR(i5,4){ // switch 5
                        FOR(i6,4){ // switch 6
                            FOR(i7,4){ // switch 7
                                FOR(i8,4){ // switch 8
                                    FOR(i9,4){ // switch 9
                                        // cout<<i1<<i2<<i3<<i4<<i5<<i6<<i7<<i8<<i9<<endl;
                                        FOR(t, i1){
                                            func1();
                                        }
                                        FOR(t, i2){
                                            func2();
                                        }
                                        FOR(t, i3){
                                            func3();
                                        }
                                        FOR(t, i4){
                                            func4();
                                        }
                                        FOR(t, i5){
                                            func5();
                                        }
                                        FOR(t, i6){
                                            func6();
                                        }
                                        FOR(t, i7){
                                            func7();
                                        }
                                        FOR(t, i8){
                                            func8();
                                        }
                                        FOR(t, i9){
                                            func9();
                                        }
                                        FOR(i, 3){
                                            FOR(j, 3){
                                                if(dummy[i][j]==0) counter++;
                                            }
                                        }
                                        if(counter==9){
                                            FOR(t, i1){
                                                cout<<1<<" ";
                                            }
                                            FOR(t, i2){
                                                cout<<2<<" ";
                                            }
                                            FOR(t, i3){
                                                cout<<3<<" ";
                                            }
                                            FOR(t, i4){
                                                cout<<4<<" ";
                                            }
                                            FOR(t, i5){
                                                cout<<5<<" ";
                                            }
                                            FOR(t, i6){
                                                cout<<6<<" ";
                                            }
                                            FOR(t, i7){
                                                cout<<7<<" ";
                                            }
                                            FOR(t, i8){
                                                cout<<8<<" ";
                                            }
                                            FOR(t, i9){
                                                cout<<9<<" ";
                                            }
                                            return 0;
                                        }
                                        FOR(i, 3){
                                            FOR(j, 3){
                                                dummy[i][j] = cloc[i][j];
                                            }
                                        }
                                        counter = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
/*
9 9 12
6 6 6
6 3 6
*/