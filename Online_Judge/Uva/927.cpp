//Uva 927
#include <stdio.h>
long long pow(int s, int c);

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);

	int t, T;
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		int d, k, nCoef, tmp = 0, s,i = 0, coef[20] = {0, };
		char c;
		long long res = 0;
		scanf("%d", &nCoef);
		for (i = 0; i <= nCoef; i++)
			scanf("%d", &coef[i]);
		scanf("%d\n%d", &d, &k);

		s = 0;
		while (k > tmp)
		{
			s++;
			tmp += (d*s);
		}

		for (i = 0; i <= nCoef; i++)
			res += coef[i] * pow(s, i);

		printf("%lld\n", res);
	}
	return 0;
}
long long pow(int s, int c)
{
	long long ret = 1;
	int i = 1; 

	if (c == 0)
		return 1;

	for (i = 0; i < c; i++)
		ret *= s;

	return ret;
}