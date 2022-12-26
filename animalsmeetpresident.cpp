#include <iostream>
#include <fstream>
using namespace std;
int sum;
int main ()
{
    ifstream fin ("animalsmeetpesident.in");
    ofstream fout ("animalsmeetpesident.out");
    int c, p, k, n, qc, qp, qk, rc, rp, rk;
    fin >> c >> p >> k;
    qc = (c+3) / 3;
    rc = c % 3;
    qp = (p + 3) / 3;
    rp = p % 3;
    qk = (k + 3) / 3;
    rk = k % 3;
    if ((rc == 0 && rp == 0 && rk == 0) || (c == k && p == c))
    {
        sum = 9 * qc;
    }
    else
    {
        sum = 9 * qc;
        if(qc == 1 && qp == 1 && qk == 1)
        {
            sum += 9;
        }
        if(c == 1 && qp == 1 && qk == 2)
        {
            sum += 9;
        }
        if(c == 1 && qp == 2 && qk == 1)
        {
            sum += 12;
        }
        if(c == 1 && qp == 2 && qk == 2)
        {
            sum += 12;
        }
        if(c == 2 && qp == 1 && qk == 1)
        {
            sum += 12;
        }
        if(c == 2 && qp == 1 && qk == 2)
        {
            sum += 12;
        }
        if(c == 2 && qp == 2 && qk == 1)
        {
            sum += 12;
        }
        if(c == 2 && qp == 2 && qk == 2)
        {
            sum += 18;
        }
    }
    fout<<sum<<endl;
}
