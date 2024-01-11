#include <stdio.h>

int main()
{
	int i, j;
	
	for(i = 100; i <= 200; i++){    /* 外层循环*/
		j=2;
		while (j<i && i%j!=0) j++;  /* 内层循环,判别i是否是素数*/
		if (j==i) printf("%d ", i);   
          /*j==i说明在上面的while循环中i都不能被j整除，因此i是素数 */
	}
	
	return 0;
}
