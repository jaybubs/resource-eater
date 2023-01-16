#include <stdio.h>
#include <math.h>
#include <deque>
#include <time.h>

// This program can be used for simple CPU and MEM load tests
// This program puts almost 100% load on one cpu core and consumes specified amount of RAM (main memory)
// Please note that the timing behaviour changes based on CPU clock etc., so tune the constant accordingly
// Usage eat <num-of-seconds-to-run> <mem-in-gb>

int main( int argc, char *argv[] )  {

  long * holder;

  // 134217728 B = 128 MB
  long long timed,
       mem_in_gb;

  double x=945346346464.3453453453,
         y=7899.345345345,
         z=2343523523.242342342;

  time_t end;

  if( argc == 3 ) {
    // printf("The argument supplied is %s\n", argv[1]);
    timed = atoi(argv[1]);
    mem_in_gb = atoi(argv[2]);

    printf("This program will run for approximately %s seconds and consumes %s GB of RAM \n", argv[1], argv[2]);
  }
  else if( argc > 3 ) {
    printf("Usage eat <num-of-seconds-to-run> <mem-in-gb>\n");
    exit(0);
  }
  else {
    printf("Usage eat <num-of-seconds-to-run> <mem-in-gb>\n");
    exit(0);
  }

  // 4 bytes to int, 1024^3 from bytes to gigs
  std::deque<int> d(mem_in_gb * 1024 * 1024 * 256, 1);

  end = time(NULL) + timed;

  // Burst CPU

  while(time(NULL) < end)
  {
    y = sqrt(x) * sin(z) * pow(25,y);
  }
  return 0;

}
