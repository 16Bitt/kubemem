#ifndef KUBEMEM_H
#define KUBEMEM_H

#define ERR_MALLOC_FAILED 1
#define ERR_SYSINFO_FAILED 2
#define ERR_ARGUMENTS_FAILED 2
#define ERR_MEMORY_LOW 3

#define DEFAULT_WARNING_RATIO 0.75
#define DEFAULT_FAILURE_RATIO 0.90

#define WARNING_FLAG "--warning"
#define FAILURE_FLAG "--failure"

struct kubemem_arguments {
  double warning_ratio;
  double failure_ratio;
};

double free_ram_ratio();
int kubemem_arguments(int argc, char **argv, struct kubemem_arguments *args);

#endif
