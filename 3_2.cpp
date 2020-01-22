#include <iostream>
using namespace std;
int main()
{
    cout << "Dimension of Matrix: ";
    int n, m;
    cin >> n >> m;
    int A[n][m];
    cout << "Enter Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int colIndex, min = INT_MAX; 		// here max is used for both , row and column
        for (int j = 0; j < m; j++)	   	// finding minimun in row
        {
            if (A[i][j] < min)
            {
		min = A[i][j];
                colIndex = j;
            }
        }
	int k = 0;
	cout<<min<<endl;
        for (k = 0; k < n; k++)			// finding maximum in columns
        {
        	if(min < A[k][colIndex])
			break;
     	}
        if (k == n)
        {
            cout << "Saddle point is: " << A[i][colIndex] << "  row: " << i + 1 << " col: " << colIndex + 1;
            return 0;
        }
    }
    cout << "No saddle point\n";
    return 0;
}
