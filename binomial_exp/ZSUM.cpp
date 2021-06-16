/*
Problem Link : https://www.spoj.com/problems/ZSUM/
Problem set from cp algorithm: https://cp-algorithms.com/algebra/binary-exp.html
*/

#include <iostream>
using namespace std;
typedef long long int ll;
const int m = 10000007;
ll binpow(ll base, ll exp)
{
    base %= m;
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = result * base % m;
        base = base * base % m;
        exp = exp / 2;
    }
    return result % m;
}
ll reducedFun(int n, int k)
{
    // (Zn +Zn-1 - 2Zn-2) = 2*( n-1^n + n-1^n-1 )+ n^k + n^n
    return (2 * binpow(n - 1, k) + 2 * binpow(n - 1, n - 1) + binpow(n, k) + binpow(n, n)) % m;
}
int main()
{
    while (true)
    {
        ll n, k;
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        cout << reducedFun(n, k) << endl;
    }
}
