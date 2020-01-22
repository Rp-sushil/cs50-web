#include <iostream>
using namespace std;
int main()
{

    cout << "Dimension of Matrix A: ";
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
    cout << "Dimension of Matrix B: ";
    int p, q;
    cin >> p >> q;
    int B[p][q];
    cout << "Enter Matrix" << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> B[i][j];
        }
    }
    if (m != p)
    {
        cout << "Wrong dimensions\n";
        return 0;
    }
    int C[n][q];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++)
            C[i][j] = 0;
	
    for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
		    for(int k = 0; k < m; k++){
			    C[i][j] = A[i][k] * B[k][j] + C[i][j];
		    }
	   }
    }

    cout << "\nResultant Matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
