//Uva 11340
#include <stdio.h>
#include <memory.h>

int main(void)
{
	setbuf(stdout, NULL);
	freopen("indata.txt", "r", stdin);
	int t, T;
	scanf("%d\n", &T);
	for (t = 0; t < T; t++) {
		int nCharacter, val, i, line, currentline = 0, total = 0;
		unsigned char character;
		int valTable[256] = { 0, }; //character should be unsigned char
		scanf("%d\n", &nCharacter);
		for (i = 0; i < nCharacter; i++) {
			scanf("%c %d\n", &character, &val);
			valTable[character] = val;
		}
		scanf("%d\n", &line);
		for(i = 0; i < line; i++)
		{
			unsigned char temp;
			while (scanf("%c", &temp) != EOF && temp != '\n') {
					total += valTable[temp];
			}
		}

		printf("%d.%02d$\n", total / 100, total % 100);
	}

	return 0;
}