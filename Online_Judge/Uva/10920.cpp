//Uva 10920 not solve
#include <stdio.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);

	int sz, p;
	while (scanf("%d %d", &sz, &p) && (sz || p)) {
		int circle = 1, totalCellCnt = 1, px = (sz / 2 + 1), py = (sz / 2 + 1);
		int max, min, res = 0, edge = 1;

		if (p == 1)
		{
			printf("Line = %d, column = %d.\n", px, py);
			continue;
		}
		while (totalCellCnt < p)
		{
			circle++;
			totalCellCnt += (2*((2 * circle - 1) + (2 * circle - 3)));
		}

		max = totalCellCnt; min = totalCellCnt - ((circle-1)*2 - 1);

		for (edge = 1; edge <= 4 && !res; edge++)
		{
			if (p <= max && p >= min)
			{
				int i;
				switch (edge)
				{
				case 1:
					px += (circle - 1);  py += (circle - 1);
					for (i = 0; i < (circle * 2 - 2); i++)
					{
						if (max == p)
						{
							printf("Line = %d, column = %d.\n", py - i, px);
							res = 1;
							break;
						}
						max--;
					}
					break;
				case 2:
					px += (circle - 1); py -= (circle - 1);
					for (i = 0; i < (circle * 2 - 2); i++)
					{
						if (max == p)
						{
							printf("Line = %d, column = %d.\n",py, px - i);
							res = 1;
							break;
						}
						max--;
					}
					break;
				case 3:
					px -= (circle - 1); py -= (circle - 1);
					for (i = 0; i < (circle * 2 - 2); i++)
					{
						if (max == p)
						{
							printf("Line = %d, column = %d.\n",py + i, px);
							res = 1;
							break;
						}
						max--;
					}
					break;
				case 4:
					px -= (circle - 1); py += (circle - 1);
					for (i = 0; i < (circle * 2 - 2); i++)
					{
						if (max == p)
						{
							printf("Line = %d, column = %d.\n", py, px + i);
							res = 1;
							break;
						}
						max--;
					}
					break;
				}
			}
			else
			{
				max -= (circle * 2 - 2);
				min -= (circle * 2 - 2);
			}
		}

	}

	return 0;
}