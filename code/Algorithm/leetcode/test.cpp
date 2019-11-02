#include <iostream>
#include <cmath>
using namespace std;

unsigned int p31 = 01 << 31;

int reverse(long x)
{
    long long arr[40];
    int len = 0;
    long long res = 0;
    long long temp = abs(x);
    while (temp != 0)
    {
        arr[++len] = temp % 10;
        temp /= 10;
    }
    long long base = 1;
    for (int i = len; i >= 1; i--)
    {
        res += base * arr[i];
        base *= 10;
    }

    if (x >= 0 && res <= p31 - 1)
        return res;
    else if (x < 0 && res <= p31)
        return res * -1;
    else
        return 0;
}

int main()
{

    cout << reverse(-123) << endl;

    return 0;
}