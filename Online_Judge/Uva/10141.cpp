//Uva 10141
#include <iostream>
#include <limits.h>
#include <string>
#include <memory.h>

int main(void)
{
	int requirmentCnt, proposalCnt, cntCase = 1, flag = 0;
	char res[100], temp[100];
	while (scanf("%d %d\n", &requirmentCnt, &proposalCnt) && (requirmentCnt || proposalCnt)) {
		int i, maxMet = 0, tempMet, j;
		int  minPrice = INT_MAX;
		if (flag) // end of printed solution line shoud be not blank
			printf("\n");
		
		for (i = 0; i < requirmentCnt; i++)
			fgets(temp, 100, stdin); //skip
			
		for (j = 0; j < proposalCnt; j++) {
			float tempPrice;
			fgets(temp, 100, stdin);
			scanf("%f %d\n", &tempPrice, &tempMet);

			if (tempMet > maxMet) {
				minPrice = tempPrice;
				maxMet = tempMet;
				memset(res, 0, sizeof(res));
				memcpy(res, temp, strlen(temp));
			}
			else if (tempMet == maxMet && tempPrice < minPrice) {
				minPrice = tempPrice;
				memset(res, 0, sizeof(res));
				memcpy(res, temp, strlen(temp));
			}
			for (i = 0; i < tempMet; i++)
				fgets(temp, 100, stdin); //skip
		}
		printf("RFP #%d\n%s", cntCase, res);
		cntCase++;
		flag = 1;
	}
	return 0;
}