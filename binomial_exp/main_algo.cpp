#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
class BinaryExponentiation
{
public:
    ll BinomialExpNaive(ll base, ll exp);            // naive approach O(n)
    ll binomialExpRec(ll base, ll exp);             //using recursion O(log(n)) (Fast but uses extra space in stack)
    ll binomialExpIter(ll base, ll exp);            // iterative solution O(log(n)) (fastest among all of the above method)
    ll binomialExpMod(ll base, ll exp, ll m);      // same as above function with mod
    ll binomialExpPrimeMod(ll base, ll exp, ll m); // if m is prime, x^(exp) and x^(exp mod (m-1)) is same using fermat theoram
    // best way to calculate Mod if m is prime
};

ll BinaryExponentiation::BinomialExpNaive(ll base, ll exp)
{
    ll result = 1;
    for (int i = 1; i <= exp; i++)
    {
        result *= base;
    }
    return result;
}

ll BinaryExponentiation::binomialExpRec(ll base, ll exp)
{
    if (exp == 0)
        return 1;

    ll result = binomialExpRec(base, exp / 2);
    if (exp % 2 == 1)
        result = result * result * base;
    else
        result = result * result;
    return result;
}

ll BinaryExponentiation::binomialExpIter(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = result * base;
        }
        base = base * base;
        exp = exp / 2;
    }
    return result;
}
ll BinaryExponentiation::binomialExpMod(ll base, ll exp, ll m)
{
    base = base % m;
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = result * base % m;
        }
        base = base * base % m;
        exp = exp / 2;
    }
    return result;
}

ll BinaryExponentiation::binomialExpPrimeMod(ll base, ll exp, ll m)
{
    exp = exp % (m - 1);
    return binomialExpMod(base, exp, m);
}

