#include <iostream>
using namespace std;
int main()
{
    int n;
    do
    {
        cout << "Enter N:";
        cin >> n;
    } while (n <= 0);
    cout << "Divisor of N are: ";
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}