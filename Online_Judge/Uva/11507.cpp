//Uva 11507
#include <stdio.h>

int main(void)
{
	//setbuf(stdout, NULL);
	//freopen("indata.txt", "r", stdin);
	int L;
	while (scanf("%d\n", &L) && L) {
		char bend[2] = { 0, };
		char currentDir = 'x', currentSign = '+';
		while (scanf("%c", &bend[1]) && bend[1] != '\n') {
			if (bend[1] == ' ')
				continue;
			else if (bend[1] == 'N') {
				scanf("%c", &bend[0]);
				continue;
			}
			scanf("%c", &bend[0]);
			if (currentDir == 'x') {
				if (currentSign == '-') {
					if (bend[1] == '+') currentSign = '-';
					else currentSign = '+';
				}
				else
					currentSign = bend[1];

				currentDir = bend[0];
			}
			else if (currentDir == 'y') {
				if (bend[0] == 'y') {
					if (bend[1] != currentSign)
						currentSign = '+';
					else
						currentSign = '-';

					currentDir = 'x';
				}
			}
			else if (currentDir == 'z') {
				if (bend[0] == 'z') {
					if (bend[1] != currentSign)
						currentSign = '+';
					else
						currentSign = '-';

					currentDir = 'x';
				}
			}
		}
		printf("%c%c\n", currentSign, currentDir);
	}
	return 0;
}