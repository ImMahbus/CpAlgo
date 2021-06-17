/*
Problem Link : https://codeforces.com/problemset/problem/630/I
Problem set from cp algorithm: https://cp-algorithms.com/algebra/binary-exp.html
*/

#include <iostream>
using namespace std;
typedef long long int ll;
ll binpow(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = result * base;
        base = base * base;
        exp = exp / 2;
    }
    return result;
}
ll count(int n)
{
    /*
        Consider two cases 
    (i) When all n consecutive cars in the beginning or the end
         aaaa......(n cars) b......
         ..............baaaa..(n cars)
        In this case only one constraint is present ie. just put different car at
        the end or starting of this sequence .
        so total no of ways are =  
        2(no of position i.e end or start)*4(selecting any car for n length sequence)*3(No of ways to choseing terminal)
        * 4^(2n - 2 - (n+1))(choosing any car for remaining sequence)
    (ii) When all n consecutive cars in the middle
        ...baaa..(n cars)..aad....
        In this case, now terminal 
        can be choosen in 3^2 different ways. Since both end needs to be different from n len sequence
        The number of ways to place n cars is a bit tricky
        Total positions = 2*n-2;
        first and last position care considered in case (i) 
        so remaining positions are  = Total - 2( considered in case (i)) - (n-1)(this term is subtracted, 
                                            because of sequence length is n so 
                                            (n-1) will always be filled)
                                    = 2*n - 2 - 2 - n + 1
                                    = n - 3
        so total no fo ways are =  
        (n-3) * 4(selecting any car for n length sequence)*3^2(No of ways to choseing terminal)
        * 4^(2n - 2 - (n+2))(choosing any car for remaining sequence)
    */

    return (2 * 4 * 3 * binpow(4, (2 * n - 2 - (n + 1)))) 
                    + ((n - 3) * 4 * 3 * 3 * binpow(4, (2 * n - 2 - (n + 2))));
}
int main()
{
    ll n;
    cin >> n;
    cout << count(n) << endl;
}