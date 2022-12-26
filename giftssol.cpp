#include <iostream>
#include <fstream>
using namespace std;
int N, B, P[1000], S[1000];
void sort_by_p_plus_s(void)
{
    int i, tmp, done=0;

    while (!done) {
        done = 1;
        for (i=0; i<N-1; i++){
            if (P[i]+S[i] > P[i+1]+S[i+1]) {
                tmp = P[i]; P[i] = P[i+1]; P[i+1] = tmp;
                tmp = S[i]; S[i] = S[i+1]; S[i+1] = tmp;
                done = 0;
            }
        }
    }
}
int try_coupon(int c)
{
    int i, budget = B - (P[c]/2+S[c]), total=1;
    if (budget < 0) return 0;
    for (i=0; i<N; i++) 
    if (P[i]+S[i] <= budget && i!=c) {
        budget -= P[i]+S[i];
        total++;
    }
    return total;
}

int main()
{
    int i, best=0;
    ifstream fin("gifts.in");
    ofstream fout("gifts.out");
    fin>>N>>B;
    for (i=0; i<N; i++){
        fin>>P[i]>>S[i];
    }
    sort_by_p_plus_s();
    for (i=0; i<N; i++){
        if (try_coupon(i) > best){
            best = try_coupon(i);
        }
    }
    fout<<best<<endl;
    return 0;
}