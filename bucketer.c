#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  //taking an example rated capacity
  int rated_capacity=120;
  for(int i=0;i<nBatteries;i++)
    {
      //calculating soh
      float soh=((float)presentCapacities[i]/rated_capacity)*100;
      if(soh>80 && soh<=100)
      {
        counts.healthy++;
      }
      else if(soh>=62 && soh<=80)
      {
        counts.exchange++;
      }
      else
      {
        counts.failed++;
      }
    }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
