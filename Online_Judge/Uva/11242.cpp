//Uva 11242
#include <stdio.h>
void qsort(float *arr, int n);

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	
	int nFront, nRear;
	while (scanf("%d %d", &nFront, &nRear) && (nFront))
	{
		float front[10] = { 0, }, rear[10] = { 0, };
		float ratio[100] = { 0, };
		int idx = 0, i, j;
		float res = 0;
		
		for (idx = 0; idx < nFront; idx++)
			scanf("%d", &front[idx]);
		for (idx = 0; idx < nRear; idx++)
			scanf("%d", &rear[idx]);

		for (i = 0; i < nFront; i++)
			for (j = 0; j < nRear; j++)
				ratio[(i * nRear) + j] = rear[j] / front[i];
		
		qsort(ratio, nFront * nRear);

		for (i = 1; i < nFront * nRear; i++)
		{
			if (ratio[i] / ratio[i - 1] > res)
				res = ratio[i] / ratio[i - 1];
		}

		printf("%.2f\n", res);
	}
	
	return 0;
}

void qsort(float *arr, int n)
{
#define MAXLEVEL	300

	int L, R, beg[MAXLEVEL], end[MAXLEVEL], i = 0, swap;
	float piv;
	beg[0] = 0; end[0] = n;

	while (i >= 0)
	{
		L = beg[i]; R = end[i] - 1;
		if (L < R)
		{
			piv = arr[L];
			while (L < R) {
				while (piv <= arr[R] && L < R) R--; if (L < R) arr[L++] = arr[R];
				while (piv >= arr[L] && L < R) L++; if (L < R) arr[R--] = arr[L];
			}
			arr[L] = piv; beg[i + 1] = L + 1; end[i + 1] = end[i]; end[i++] = L;
			if (end[i] - beg[i] > end[i - 1] - beg[i - 1])
			{
				swap = end[i - 1]; end[i - 1] = end[i]; end[i] = swap;
				swap = beg[i - 1]; beg[i - 1] = beg[i]; beg[i] = swap;
			}
		}
		else
			i--;
	}
}