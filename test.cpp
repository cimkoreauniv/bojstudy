#include <stdio.h>

int main(void)
{
	int arr[8] = {-158400, -184000, -25000, -25000, 25000, 20000, 10000, 19425};
	int minidx, minval=100000000;
	for(int i=0; i<128; i++)
	{
		int total = 171270;
		for(int j=0; j<8; j++)
			if((1<<j) & i)
				total += arr[j];
		if(total >= 0 && total < minval)
			minidx = i, minval = total;
	}
	printf("%d %d\n", minidx, minval);
	return 0;
}
