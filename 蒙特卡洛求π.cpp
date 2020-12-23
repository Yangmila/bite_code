#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main() {
	double x, y, pi;
	int n, count;
	srand((unsigned)time(NULL)); 
	for (n = 1, count = 0; n <= 200000; n++) { 
		x = rand() / (double)RAND_MAX;
		y = rand() / (double)RAND_MAX;  
		if (sqrt((x - 0.5)*(x - 0.5) + (y - 0.5)*(y - 0.5)) < 0.5) { 
			count++;
		}
	}
	pi = 1.0*count/200000;
	printf("%0.4lf\n",4*pi);
	return 0;
}

