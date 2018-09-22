#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>


using namespace std;
#define MAX_N 101
/*
Sample Input
2 1
01 1 02
Sample Output
0 1
*/

int main()
{
	int M, N, i, ID, K, j, childID;
	std::vector<int> children[MAX_N];
	std::vector<int> seedNodes, newSeedNodes;
	bool bFirst = true;

	cin >> N >> M;
	for (i = 0; i < M; ++i)
	{
		cin >> ID >> K;
		for (j = 0; j < K; ++j)
		{
			cin >> childID;
			children[ID].push_back(childID);
		}
	}
	seedNodes.push_back(1);

	while (true)
	{
		K = 0;
		newSeedNodes.clear();
		for (i = 0; i < seedNodes.size(); ++i)
		{
			childID = seedNodes[i];
			if (children[childID].empty())
				++K;
			else
				newSeedNodes.insert(newSeedNodes.end(), children[childID].begin(), children[childID].end());
		}
		if (bFirst)
			bFirst = false;
		else
			cout << " ";
		std::cout << K;

		if (newSeedNodes.empty())
			break;
		seedNodes = newSeedNodes;
	}

	return 0;
}
