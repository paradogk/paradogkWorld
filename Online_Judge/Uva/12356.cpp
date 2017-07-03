//Uva 12356
#include <stdio.h>
#include <memory.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);

	int S, B;

	while (scanf("%d %d", &S, &B) && (S || B))
	{
		char soldierArray[100001] = { 0, };
		int L = 0, R = 0, i = 0, rmL, rmR;

		for (i = 0; i < B; i++)
		{
			scanf("%d %d", &L, &R);
			memset(soldierArray + L, 1, R - L + 1);
			while (soldierArray[L] && L > 0) L--;
			while (soldierArray[R] && R <= S) R++;
			if (L <= 0)
				printf("* ");
			else
				printf("%d ", L);

			if (R > S)
				printf("*\n");
			else
				printf("%d\n", R);
		}
		printf("-\n");
	}

	return 0;
}