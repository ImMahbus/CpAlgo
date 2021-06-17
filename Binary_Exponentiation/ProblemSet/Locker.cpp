/*
Problem Link : https://www.spoj.com/problems/LOCKER/
Problem set from cp algorithm: https://cp-algorithms.com/algebra/binary-exp.html
Explanation = https://medium.com/@palak001/spoj-locker-magic-of-the-locker-a758bccf432f

*/

#include <iostream>
using namespace std;
typedef long long int ll;
const int m = 1e9 + 7;

ll binpow(ll base, ll exp)
{
    base %= m;
    exp %= m - 1;
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
ll f(ll n)
{
    // Best way to figure out is to check the maxima of fn k^(n/k)
    // This function has maxima at e
    // and trying out few examples after that around e i.e 2,3
    // it can be easily seen, 3 will give max value
    // After that some case work based on mod 3

    if (n <= 4)
        return n;
    else if (n % 3 == 0)
        return binpow(3, n / 3);
    else if (n % 3 == 1)
    {
        return binpow(3, n / 3 - 1) * (4) % m;
    }
    return binpow(3, n / 3) * 2 % m;
}
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        cout << f(n) << endl;
    }
}