#include <iostream>
using namespace std;
int n, weights[22], best = 0;
bool checar(int x, int y)
{
    while(x > 0 && y > 0){
        if (x % 10 + y % 10 >= 10){
            return false;
        }
        x /= 10;
        y /= 10;
    }
    return true;
}

void subgen(int x, int sum, int counter)
{
    if (counter > best){
        best = counter;
    }
    if (x >= n || counter + n - x <= best){
        return;
    }
    if (checar(sum, weights[x])){
        subgen(x + 1, sum + weights[x], counter + 1);
    }
    subgen(x + 1, sum, counter);
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> weights[i];
    }
    subgen(0,0,0);
    cout << best << endl;
}