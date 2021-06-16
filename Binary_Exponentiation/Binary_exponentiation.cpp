#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;


class BinaryExponentiation
{
public:
    ll binaryExpRec(ll base, ll exp);             //using recursion O(log(n)) (Fast but uses extra space in stack)
    ll binaryExpIter(ll base, ll exp);            // iterative solution O(log(n)) (fastest among all of the above method)
    ll binaryExpMod(ll base, ll exp, ll m);      // same as above function with mod
    ll binaryExpPrimeMod(ll base, ll exp, ll m); // if m is prime, x^(exp) and x^(exp mod (m-1)) is same using fermat theoram
    // best way to calculate Mod if m is prime
};

ll BinaryExponentiation::binaryExpRec(ll base, ll exp)
{
    if (exp == 0)
        return 1;

    ll result = binaryExpRec(base, exp / 2);
    if (exp % 2 == 1)
        result = result * result * base;
    else
        result = result * result;
    return result;
}

ll BinaryExponentiation::binaryExpIter(ll base, ll exp)
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
ll BinaryExponentiation::binaryExpMod(ll base, ll exp, ll m)
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

ll BinaryExponentiation::binaryExpPrimeMod(ll base, ll exp, ll m)
{
    exp = exp % (m - 1);
    return binaryExpMod(base, exp, m);
}

