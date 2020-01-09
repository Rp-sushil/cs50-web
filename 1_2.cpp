#include <iostream>
using namespace std;
bool isPrime(long long n)
{
    if (n == 2)
        return true;
    for (long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long n;
    do
    {
        cout << "Enter N: ";
        cin >> n;
    } while (n <= 0);
    cout << "Prime divisor of N are: ";
    bool flag = true;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            if (isPrime(i))
                cout << i << " ";
            if (i * i == n)
                continue;
            if (isPrime(n / i))
                cout << n / i << " ";
        }
    }
    if (flag == true)
        cout << n << endl;
    return 0;
}