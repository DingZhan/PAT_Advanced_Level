#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>


using namespace std;
#define MAX_N 2002
#define MAX_K 11
/*
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/


int main()
{
	int i, j, k1, k2;
	float results[MAX_N], coeff1[MAX_K], coeff2[MAX_K];
	int exp1[MAX_K], exp2[MAX_K];
	bool bFirst = true;

	memset(results, 0, sizeof(float)*MAX_N);
	cin >> k1;
	for (i = 0; i < k1; ++i)
		cin >> exp1[i] >> coeff1[i];
	cin >> k2;
	for (i = 0; i < k2; ++i)
		cin >> exp2[i] >> coeff2[i];
	for (i = 0; i<k1; ++i)
	{
		for (j = 0; j < k2; ++j)
			results[exp1[i] + exp2[j]] += coeff1[i] * coeff2[j];
	}
	j = 0;
	for (i = 0; i < MAX_N; ++i)
	{
		if (fabs(results[i]) > 0.0001)
			++j;
	}
	cout << j << " ";
	for (i = MAX_N - 1; i >= 0; --i)
	{
		if (fabs(results[i]) > 0.0001)
		{
			if (bFirst)
				bFirst = false;
			else
				cout << " ";
			cout << i << " " << std::fixed << std::setprecision(1) << results[i];
		}
	}
	return 0;
}
