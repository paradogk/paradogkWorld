//Uva 1260
#include <stdio.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int num, i, total = 0;
		int arry[5000] = { 0, };
		scanf("%d", &num);

		for (i = 0; i < num; i++)
		{
			int input, j, cnt = 0;
			scanf("%d", &input);
			arry[i] = input;
			if (i == 0)
				continue;
			for (j = 0; j < i; j++)
			{
				if (arry[i] >= arry[j])
					cnt++;
			}
			total += cnt;
		}
		printf("%d\n", total);
	}
	return 0;
}
