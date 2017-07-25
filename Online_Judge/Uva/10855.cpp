//Uva 10855
#include <stdio.h>
#include <memory.h>
#define MAXLEN 1000
char big[MAXLEN][MAXLEN] = { 0, };
char small[MAXLEN][MAXLEN] = { 0, };
char copiedSmall[MAXLEN][MAXLEN] = { 0, };
void init(int N, int n);
void rotate(int n);
int check(char *src, char(*dst)[MAXLEN], int N, int n);

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);

	int N, n;
	while (scanf("%d %d", &N, &n) && (N || n)) {
		int i, j, t, result[4] = {0, };
		
		init(N, n);

		for (i = 0; i < N; i++)
			scanf("%s", big[i]);
		for (i = 0; i < n; i++)
			scanf("%s", small[i]);

		for (t = 0; t < 4; t++) {
			int i, j, res = 0;
			for (i = 0; i <= N - n; i++)
			{
				for (j = 0; j <= N - n; j++)
				{
					if (small[0][0] == big[i][j])
					{
						res += check(&big[i][j], small, N, n);
					}
				}
			}
			result[t] = res;
			rotate(n);
		}
		printf("%d %d %d %d\n", result[0], result[1], result[2], result[3]);
	}

	return 0;
}
void init(int N, int n) 
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			big[i][j] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			small[i][j] = 0;
			copiedSmall[i][j] = 0;
		}
}
void rotate(int n)
{
	int i, j;

	for (i = 0; i < n; i++) 
		memcpy(copiedSmall[i], small[i], n);

	for (i = 1; i <= n; i++) {
		for (j = 0; j < n; j++) {
			small[j][n - i] = copiedSmall[i-1][j];
		}
	}
}
int check(char *src, char(*dst)[MAXLEN], int N, int n)
{
	int k, l;
	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++)
		{
			if (*(src+(k*MAXLEN)+l) != dst[k][l])
				return 0;
		}
	}
	return 1;
}