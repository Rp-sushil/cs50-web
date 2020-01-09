#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    do
    {
        cout << "Enter N: ";
        cin >> n;
    } while (n <= 0);
    int arr[n];

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    int maxfreq = 0, element = 0;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if (i->second > maxfreq)
        {
            maxfreq = i->second;
            element = i->first;
        }
    }
    cout << "Element " << element << " has maximum frequency " << maxfreq << endl;
}