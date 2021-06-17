/*
                             GCD using euclid Algorithm 
                             
euclid Algorithm: gcd(a,b) = gcd(b, a % b);

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

We will end up proving euclid algorithm

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

Time Complexity: log(min(a,b)) 
For proof of Time complexity :
         https://www.geeksforgeeks.org/time-complexity-of-euclidean-algorithm/

*/

#include <iostream>
using namespace std;

class gcdEuclid
{
public:
    int gcdEuclidIter(int a, int b);
    int gcdEuclidRec(int a, int b);
    int lcm(int a, int b); // can be found using identity gcd(a,b)*lcm(a,b) = a*b
};

int gcdEuclid::gcdEuclidRec(int a, int b)
{
    if (b == 0)
        return a;

    return gcdEuclidRec(b, a % b);
}
int gcdEuclid::gcdEuclidIter(int a, int b)
{
    while (b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
int gcdEuclid::lcm(int a, int b)
{
    return (a * b) / gcdEuclidIter(a, b);
}
/*
                             GCD using stein's Algorithm 

            The modulo operator are bit slower than other basic arthematic operator like
            addition, substraction. There is a bit of optimization that can be done using 
            stein's algorithm which tries to overcome this by using bit shift rather than modulo operator.
            Similar to euclid, this also tries to reduce the input into smaller number by using 
            gcd(a, b)  = gcd(a, b - a);

        Steps:
        (i) If a or b is 0, return the non zero argument as gcd
        (ii) If both a and b are even then use this trivial identity 
                        gcd(a, b) = 2 * gcd(a/2, b/2)
        (iii) If one of then is even and other is odd, then 2 cannot be the gcd so 
             divide the even no by 2 till it become odd --> g(even, odd) = gcd(even/2, odd)
        (iv) If both are odd, 
                then gcd(large, small) = gcd((large-small)/2, small) 

Detail Explanation : https://iq.opengenus.org/binary-gcd-algorithm/

*/
class gcdStein
{
public:
    int gcdSteinRec(int a, int b);
    int gcdSteinIter(int a, int b);
};

int gcdStein::gcdSteinIter(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int commonPowerTwo = 0;
    while ((a | b) & 1 == 0)
    {
        a >>= 1;
        b >>= 1;
        commonPowerTwo++;
    }
    while ((a & 1) == 0)
        a >>= 1;
    while (b != 0)
    {
        while ((b & 1) == 0)
            b >>= 1;
        if (a > b)
            swap(a, b);
        b = b - a;
    }
    return a << commonPowerTwo;
}

int gcdStein::gcdSteinRec(int a, int b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a & 1)
    {
        if (b & 1)
        {
            if (a > b)
                swap(a, b);
            return gcdSteinRec((b - a) >> 1, a);
        }
        else
            return gcdSteinRec(a, b >> 1);
    }
    else
    {
        if (b & 1)
        {
            return gcdSteinRec(a >> 1, b);
        }
        else
            return gcdSteinRec(a >> 1, b >> 1) << 1;
    }
}
