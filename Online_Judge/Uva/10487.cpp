//Uva 10487
#include <stdio.h>
#include <limits.h>
#define ABS(X)	((X) < 0 ? -(X) : (X))
int arry[1000][1000];
void init(void);

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);

	int n, nCase = 1;
	while (scanf("%d", &n) && n)
	{
		int i, j, k, nQ, query, res = INT_MAX;
		
		init();
		for (i = 0; i < n; i++)
			scanf("%d", &arry[0][i]);

		for(i = 1; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				arry[i][j] = arry[0][i] + arry[0][j];
			}
		printf("Case %d:\n", nCase++);
		scanf("%d", &nQ);
		for (k = 0; k < nQ; k++)
		{
			scanf("%d", &query);
			for (i = 1; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (ABS(query - arry[i][j]) <= ABS(res - query) && arry[i][j])
						res = arry[i][j];
				}
			printf("Closest sum to %d is %d.\n",query, res);
		}
	}
	return 0;
}
void init(void)
{
	int i, j;
	for (i = 0; i < 1000; i++)
		for (j = 0; j < 1000; j++)
			arry[i][j] = 0;
}