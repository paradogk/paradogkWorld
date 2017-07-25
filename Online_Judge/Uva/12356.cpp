//Uva 12356 not solve
#include <stdio.h>
#include <memory.h>

void init_arr(char* prev, char* next);

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);

	int S, B;

	while (scanf("%d %d", &S, &B) && (S || B))
	{
		char prevArray[100002] = { 0, };
		char nextArray[100002] = { 0, };
		char IsRemoved[100002] = { 0, };
		int i, L, R;

		init_arr(prevArray, nextArray);

		prevArray[0] = '*'; nextArray[S+1] = '*';
		for (i = 0; i < B; i++)
		{
			scanf("%d %d", &L, &R);

			if((L - 1) - (prevArray[L - 1]) == 1 && prevArray[L - 1] != '*') // exist prev node
				memset(prevArray + L, prevArray[L], R - L + 1);
			else
				memset(prevArray + L, prevArray[L - 1], R - L + 1);
			if ((nextArray[R + 1]) - (R + 1) == 1 && nextArray[R + 1] != '*') // exist prev node
				memset(nextArray + L, nextArray[R], R - L + 1);
			else
				memset(nextArray + L, nextArray[R + 1], R - L + 1);

			memset(IsRemoved + L, 1, R - L + 1);
			while (prevArray[L] != '*' && IsRemoved[L]) L = prevArray[L];
			while (nextArray[R] != '*' && IsRemoved[R]) R = nextArray[R];

			if (prevArray[L] == '*')
				printf("* ");
			else
				printf("%d ", L); // 1 is head

			if (nextArray[R] == '*')
				printf("*\n");
			else
				printf("%d\n", R); // R == S is tail
		}
		
		printf("-\n");
	}

	return 0;
}
void init_arr(char* prev, char* next)
{
	int i;
	for (i = 1; i <= 100000; i++)
	{
		prev[i] = i - 1;
		next[i] = i + 1;
	}
}