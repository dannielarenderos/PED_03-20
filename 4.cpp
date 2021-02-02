
#include <iostream>
using namespace std;

int contNum(int n) //10
{
    cout << n << endl; //10
    if (n == 10)
        return n;
    else
        return contNum(n + 1); //10
}

int contNumN(int n, int tope)
{
    cout << n << endl;
    if (n == tope)
        return n;
    else
        return contNumN(n + 1, tope);
}


int contNumDes(int n)
{
    cout << n << endl;
    if (n == 1)
        return n;
    else
        return contNumDes(n - 1);
}


int sumNumInter(int a, int b, int sum) //  3 3 3
{
    sum = sum+a; // 3 + 3 = 6
    if (a == b)
        return sum;
    else
        return sumNumInter(a+1, b, sum); // 
}

int main(int argc, char const *argv[])
{
    cout<< sumNumInter(1, 3, 0);
    return 0;
}
