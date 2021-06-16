/*
                             GCD using Eculid Algorithm 
                             
Eculid Algorithm: gcd(a,b) = gcd(b, a % b);

Proof:

(i) gcd(a,b) = gcd(b,a) (trivial)
(ii) gcd(0,a) = a (trivial)
(iii) Lets say if we could prove some how that 
        gcd(a,b) = gcd(b,a-b)
then doing this step iteratively ,
        gcd(a,b) = gcd(b,a-2*b)
        gcd(a,b) = gcd(b,a-3*b)
        .
        .
till    gcd(a,b) = gcd(b,r)  where r = a - x*b => r = a % b

We will end up proving eculid algorithm

(iv) To prove : gcd(a,b) = gcd(b, a - b)
    let say  a - b = c -- (i)
    a = gcd(a, b) * x -- (ii)
    b = gcd(a, b) * y -- (iii)
    Now Putting (ii) and (iii) in (i);
    gcd(a,b) * (x-y) = c
    => gcd(a,b) is a factor of c
    Now manupulating first equation into b + c = a
    and using same steps  => gcd(b, c) is a factor of a

    Now a has two factors gcd(a, b) and gcd(b, c)
                 --> (gcd(a,b) => gcd(b,c)) since gcd(a,b) should be the largest factor of a (iv)
    and similarly c jas two factors gcd(b, c) and gcd(a, b) 
                --> (gcd(a,b) <= gcd(b,c)) since gcd(b,c) should be the largest factor of c  (v)

    Now from (vi) and (v) it can be easily seen that both equations can only be satisfied at
    equality
    Hence gcd(a, b) = gcd(b, c) = gcd(b, a - b)

*/

#include <iostream>
using namespace std;

class gcd
{
public:
    int gcdEculidIter(int a, int b);
    int gcdEculidRec(int a, int b);
};

int gcd::gcdEculidRec(int a, int b)
{
    if (b == 0)
        return a;

    return gcdEculidRec(b, a % b);
}
int gcd::gcdEculidIter(int a, int b)
{
    while (b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
