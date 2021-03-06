#include <stdio.h>

int main() {
	int m[5] = {1,4,5,6,3};
	int n[5] = {2,1,4,5,6};

	int p[2][3] = {{4,2,2},{3,2,1}};

	printf("%p\t%d\n",m,*m);
	printf("%p\t%d\n",n,*n);
	printf("%p\t%d\n",p,p[0][0]);
	
	int i;
	int tmp;

	printf("m=");
	for(i=0;i<5;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	printf("n=");
	for(i=0;i<5;i++) {
		printf("%d",n[i]);
	}
	printf("\n");

	for(i=0;i<5;i++) {
		tmp = m[i];
		m[i] = n[i];
		n[i] = tmp;
	}

	printf("After m=");
	for(i=0;i<5;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	printf("After n=");
	for(i=0;i<5;i++) {
		printf("%d",n[i]);
	}

	printf("\n");
	return 0;
}
