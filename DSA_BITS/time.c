//Procedure to find running time of algorithm

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
	// freopen("input.txt","r",stdin);
	long int s1,s2,u1,u2;
	struct timeval tp1, tp2;
	struct timezone tzp1, tzp2;
	int result,t,n;
	double u;
	int tmp;
	result = gettimeofday(&tp1,&tzp1);
	// while(scanf("%d",&tmp) != EOF);

	// algo(n);

	result = gettimeofday(&tp2,&tzp2);
	s1 = tp1.tv_sec;
	u1 = tp1.tv_usec;
	s2 = tp2.tv_sec;
	u2 = tp2.tv_usec;
	u = (s2-s1) + (u2-u1)/1000000.0;
	printf("%lf\n", u);
	return 0;
}