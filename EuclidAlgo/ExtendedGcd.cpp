/*
                        ---------------------------
                       |Extended Euclid Algorithm |
                       ---------------------------
    This algorithm is the extension of Euclid algorithm for finding gcd.
    Here we try find out the integer linear codefficent of the equation 
                     ax + by = gcd(a, b)   --- (i)
    Side Note: gcd(a,b) is the also the smallest positive value for which
                this linear combination has interger coefficient.
    
    The best way to understand this is to run through a example and
    then figuring out relation between two successive state of euclid algorithm.

    Example : a = 24 , b= 58
        Euclid Algorithm 

        58 = 24 * 2 + 10    =>   10 = 58 - 24 * 2   (1)
        24 = 10 * 2 + 4     =>   4 = 24 - 10 * 2    (2)
        10 = 4 * 2 + 2      =>   2 = 10 - 4 * 2     (3)
        4 = 2 * 2 + 0       =>   0 = 4 - 2 * 2      (4)

    Now look at the 3rd iteration 
                2 = 10 - 4*2
    Here, we manage to write gcd(a, b) i.e 2 as a linear combination of 
    10 and 4 
    But we want to write it as a linear combination of 58 and 24.
    To do that we have to use above equations i.e (2),(1)
    and build our solution recursively.

    Putting (2) in (3), we will get 

    2 = 10 - (24 - 10* 2 ) * 2 
    2 = 10 + 4 * 10 - 24 * 2
    2 = 10 * 5 - 24 * 2 ---  (5)

    Putting (1) in (5)

    2 = (58 - 24 * 2) * 5 - 24 * 2
    2 = 58 * 5 - 24 * 12 

    This is it a nutshell is extended euclid algorithm. But for recursive 
    implemenation we have to find relation between coefficient of two 
    successive states

    lets take any two successive step of euclid algorithm

               a1 * x1 + b1 * y1 = g ---- (1)
               a2 * x2 + b2 * y2 = g -----(2)
    
    we know that gcd(a, b) = gcd(b, a % b), so 

                a2 = b1                               --- (4)
                b2 = a1 % b1 = a1 - floor(a1/b1) * b1 --- (3)

    Puttting (3) and (4) in (2)

    g = b1 * x2 + (a1 - floor(a1/b1)*b1) * y2 = g

    g = a1 * y2 + b1 * (x2 - y2 * floor(a1/b1)) --- (6)

    Comparing 1 and 6

    x1 = y2 
    y1 = x2 - y2 * floor(a1/b1)

*/

class ExtendedEuclid
{
public:
    int gcdExtendedRec(int a, int b, int &x, int &y);
};
int ExtendedEuclid::gcdExtendedRec(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        // if b == 0, then a will contain the gcd , hence a*1 + b*0 = g 
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcdNextIter = gcdExtendedRec(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcdNextIter;
}
