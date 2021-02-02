#include <iostream>
using namespace std;

int funcMCD(int A, int B)
{
    int C = A - B;
    if (C == 0)
    {
        return A;
    }
    else
    {
        if (C > B)
        {
            return funcMCD(C, B);
        }
        else
        {
            return funcMCD(B, C);
        }
    }
}

int mcd(int a, int b)
{
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

int main(void)
{
    int A, B, C;
    int MCD = 0;
    cout << "Numero mayor: ";
    cin >> A;
    cout << "Numero menor: ";
    cin >> B;
    cout << endl
         << "El MCD de los numero ingresados es : " << funcMCD(A, B) << endl;
    cout << "El MCD de los numero ingresados es : " << mcd(A, B) << endl;

    return 0;
}
