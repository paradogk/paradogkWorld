//Uva 1237
#include <stdio.h>

typedef struct _maker
{
	char name[20];
	int low;
	int high;
}Maker;

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int nMaker, nInput, i, j;
		Maker myMaker[10000];

		scanf("%d", &nMaker);
		for (i = 0; i < nMaker; i++)
			scanf("%s %d %d", myMaker[i].name, &myMaker[i].low, &myMaker[i].high);

		scanf("%d", &nInput);
		for (i = 0; i < nInput; i++)
		{
			int res = -1, p;
			scanf("%d", &p);

			for (j = 0; j < nMaker; j++)
			{
				if (myMaker[j].low <= p && myMaker[j].high >= p && res != -2)
				{
					if (res >= 0)
						res = -2;
					else
						res = j;
				}
			}

			if (res == -2 || res == -1)
				printf("UNDETERMINED\n");
			else
				printf("%s\n", myMaker[res].name);
		}

		if(t != T)
			printf("\n");
	}

	return 0;
}
