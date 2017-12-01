#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "coords.h"

void writeOutDistance(coord a, coord b, double distance) {
  FILE *fp = fopen("distances.out", "a");

  fprintf(fp, "The distance between (%f,%f) and (%f,%f) is %f\n", a.lat,a.lon,b.lat,b.lon,distance);

  fclose(fp);

  return;
}

float calcDistance(double latHome, double lonHome, double latDest, double lonDest) {
    double pi = 3.141592653589793;
    int R = 6371;
    latHome = (pi/180)*(latHome);
    latDest = (pi/180)*(latDest);
    double differenceLon = (pi/180)*(lonDest - lonHome);
    double differenceLat = (latDest - latHome);
    double a = sin(differenceLat/2) * sin(differenceLat/2) +
    cos(latHome) * cos(latDest) *
    sin(differenceLon/2) * sin(differenceLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c;
    printf("%f\n", distance);
    return distance;
}

void doComparison(int n) {

  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      float dist = calcDistance(array[i].lat, array[i].lon, array[j].lat, array[j].lon);
      writeOutDistance(array[i], array[j], dist);
    }
  }

  return;
}

int main(void) {

  printf("Hello, time to show off gprof\n");

  int num_elements = sizeof(array)/sizeof(array[0]);
  printf("We have %i elements to compare\n", num_elements);

  doComparison(num_elements);

  return 0;
}
