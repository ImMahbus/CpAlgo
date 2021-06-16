/*
Problem Link : https://www.spoj.com/problems/ZSUM/
Problem set from cp algorithm: https://cp-algorithms.com/algebra/binary-exp.html
*/

#include <iostream>
using namespace std;
typedef long long int ll;
const int m = 10;
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
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        // finding last digit of a^b is equivalent of a^b mod 10
        ll a, b;
        cin >> a >> b;
        cout << binpow(a, b) << endl;
    }
}
