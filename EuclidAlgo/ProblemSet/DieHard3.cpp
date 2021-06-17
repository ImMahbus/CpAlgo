
// Problem Link = https://www.hackerrank.com/challenges/die-hard-3/problem

#include <iostream>
#include <algorithm>
using namespace std;
/*
The best way to approach this is to think about the set of values c can 
take. Trying out few examples, here are some trivial values of c that can be measured
using Jug
                A    (measure using first jug)
                B    (measure using second jug)
                A - B assumeing A>B (fill the first Jug and then use this to fill the 
                                    second jug. At the end, Jug A will contain A-B)
                A - 2B assuming A>2B (just procced like above, but empty the content of
                                    second Jug and fill it with Jug A)
                .
                .
                A - xB till A - xB>0 i.e A % B
This set of values have a underlying structure to then. More formally 

        c = pA + qB i.e c is a linear combination of A and B

Now because of this fact, we can say that c has to be divisible by gcd(A,B)
only then this linear combination will have a interger coefficient.
{Extended Euclid Algorithm}

*/

string PossibleToMeasure(int a, int b, int c)
{
    if (c > max(a, b))
        return "NO";
    else if (c % __gcd(a, b) == 0)
        return "YES";
    else
        return "NO";
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << PossibleToMeasure(a, b, c) << endl;
}