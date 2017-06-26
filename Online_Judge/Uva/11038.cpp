//Uva 11507
#include <stdio.h>
#include <memory.h>
#define ABS(X)	((X) > 0 ? (X) : -(X))
int IsVisit[3001] = { 0, };
void qsort(int* arr, int size);
int main(void)
{
	int idx, i, prev, next, flag ;
	while (scanf("%d", &idx) != EOF) {
		memset(IsVisit, 0, sizeof(IsVisit));
		flag = 1;
		scanf("%d", &prev);
		for (i = 0; i < idx - 1; i++)
		{
			int temp;
			scanf("%d", &next);
			temp = ABS(next - prev);
			IsVisit[i] = temp;
			prev = next;
		}
		qsort(IsVisit, idx-1);
		for (i = 1; i <= idx - 1; i++)
		{
			if (IsVisit[i-1] != i)
				flag = 0;
		}
		if (flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}
void qsort(int* arr, int size)
{
#define MAX 300
	int beg[MAX] = { 0, }, end[MAX] = { 0, };
	int L, R, p, i = 0, swap;
	beg[i] = 0; end[i] = size;
	while (i >= 0) {
		L = beg[i]; R = end[i] - 1;
		if (L < R) {
			p = arr[L];
			while (L < R) {
				while (p <= arr[R] && L < R) R--; if (L < R) arr[L++] = arr[R];
				while (p >= arr[L] && L < R) L++; if (L < R) arr[R--] = arr[L];
			}
			arr[L] = p; end[i + 1] = end[i]; beg[i + 1] = L + 1; end[i++] = L;
			if (end[i] - beg[i] < end[i - 1] - beg[i - 1]) {
				swap = end[i]; end[i] = end[i - 1]; end[i - 1] = swap;
				swap = beg[i]; beg[i] = beg[i - 1]; beg[i - 1] = swap;
			}
		}
		else
			i--;
	}
}