#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
   double k=1, pi, pi1=3.1415;
   while (fabs(k)>0.0001)
   {
        int g=0, i=0;
         for(;g<999999;g++)
         {
            double x = (rand() + 0.0) / RAND_MAX;
            double y = (rand() + 0.0) / RAND_MAX;
            if (x*x + y*y <1) i += 1;
         }
          pi = i * 4.0 / g;
         k = pi - pi1;
         //printf("%.4lf\n", pi);
    }
   printf("%.4lf\n", pi);
    return 0;
}

