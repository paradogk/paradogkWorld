//Uva 573
#include <stdio.h>
#include <limits.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	int H, U, D, F;
	while (scanf("%d %d %d %d", &H, &U, &D, &F)) {
		if (H == 0)
			break;
		int idx = 1, flag = 0, originU = U;
		int res = 0, temp = 0;
		H *= 100; U *= 100; D *= 100;
		for (idx = 1; ; idx++)
		{	
			temp = U - ((originU * F) * (idx - 1));
			if (temp >= 0)
				res += temp;

			if (res > H) {
				flag = 1;
				break;
			}
			res -= D;
			if (res < 0)
				break;
		}
		printf("%s on day %d\n", flag ? "success" : "failure", idx);
	}

	return 0;
}
