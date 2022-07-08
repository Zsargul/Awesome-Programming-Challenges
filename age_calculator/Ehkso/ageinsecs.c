#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  double years = 0;
  double secs = 0; // U have no secs lol
  double bils=0,mils=0,thous=0;

  printf("How old are you (in years)? \n"); // the tin
  scanf("%lf", &years);
  //printf("%lf", years); // Just checking
  secs = (years * 365.2425) * 86400; // A day has 86400, Gregorian calendar says 365.2425 days/year
  printf("That's ");
  if (secs >= 1000000000){
    bils = floor(secs / 1000000000);
    printf("%.0lf billion, ", bils);
    secs -= bils * 1000000000;
  }
  if (secs >= 1000000){
    mils = floor(secs / 1000000);
    printf("%.0lf million, ", mils);
    secs -= mils * 1000000;
  }
  if (secs >= 1000){
    thous = floor(secs / 1000);
    printf("%.0lf thousand, and ", thous);
    secs -= thous * 1000;
  }
  printf("%.0lf second(s). And counting.", secs);
}
