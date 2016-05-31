#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int emp;
	while(scanf("%d", &emp) == 1)
	{
		vector<int> vec[2501];
		for (int i = 0; i < emp; ++i)
		{
			int nmbfrnds; //set de friends
			scanf("%d", &nmbfrnds);
			for (int j = 1; j <= nmbfrnds; ++j)
			{
				int frn;
				scanf("%d", &frn);
				if(i!=frn)vec[i].push_back(frn);
				 
			}
		}
		int tstCases = 0;
		scanf("%d", &tstCases);
		while(tstCases--)
		{
			int mark[2501];
			int source;
			scanf("%d", &source);
			int days[2501];
			queue<int>que;
			que.push(source);
			memset(mark, 0, sizeof(mark));
			memset(days, 0, sizeof(days));
			mark[source] = 1;
			int maxBoom = 0, firstDay = 0;
			while(!que.empty())
			{
				int next = que.front(); 
				que.pop();
				for (int i = 0; i < vec[next].size(); i++)
				{
					int w = vec[next][i];
					if (!mark[w])
					{
						mark[w] = mark[next] + 1;
						que.push(w);
						days[mark[w]] = days[mark[w]] + 1;
						if (maxBoom < days[mark[w]])
						{
							maxBoom = days[mark[w]];
							firstDay = mark[w]-1;
						}
					}
				}
			}
			if (vec[source].size() < 1)
			{
				printf("0\n");
			}
			else{
				printf("%d %d\n", maxBoom, firstDay);
			}
		}
	}
	return 0;
}