#include <iostream>
using namespace std;
long int factorial(long int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    int n;
    do
    {
        cout << "Enter N: ";
        cin >> n;
    } while (n <= 0);
    cout << "factorial of N: " << factorial(n) << endl;
    return 0;
}