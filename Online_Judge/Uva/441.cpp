//Uva 441
#include <stdio.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	int N;
	bool isfirst = true;

	while (scanf("%d", &N) && N)
	{
		int arr[13] = { 0, }, idx;
		int a, b, c, d, e, f;

		for (idx = 0; idx < N; idx++)
			scanf("%d", &arr[idx]);
		if (isfirst)
			isfirst = !isfirst;
		else	
			printf("\n");

		for (a = 0; a < N - 5; a++)
			for (b = a + 1; b < N - 4; b++)
				for (c = b + 1; c < N - 3; c++)
					for (d = c + 1; d < N - 2; d++)
						for (e = d + 1; e < N - 1; e++)
							for (f = e + 1; f < N; f++)
								printf("%d %d %d %d %d %d\n",
									arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
	}
	return 0;
}

