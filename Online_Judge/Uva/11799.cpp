//Uva 11559
#include <stdio.h>
#include <limits.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	int T, t, i;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		int result = 0, nStu, temp = 0, res = 0, j;
		scanf("%d", &nStu);
		for (j = 0; j < nStu; j++) {
			scanf("%d", &temp);
			if (temp > res)
				res = temp;
		}
		printf("Case %d: %d\n", i, res);
	}
}
