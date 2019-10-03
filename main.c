#include "stdio.h"
#include "stdlib.h"
#include "kubemem.h"

int main(int argc, char **argv) {
  struct kubemem_arguments args;
  int arg_result = kubemem_arguments(argc, argv, &args);
  if(arg_result != 0) {
    exit(arg_result);
  }

  double ratio = free_ram_ratio();
  if(ratio >= args.failure_ratio) {
    fprintf(stderr, "FAILURE: hit memory limit %F (at %F)\n", args.failure_ratio * 100.0, ratio * 100.0);
    return ERR_MEMORY_LOW;
  }

  if(ratio >= args.warning_ratio) {
    fprintf(stderr, "WARN: approaching memory limit %F (at %F)\n", args.failure_ratio * 100.0, ratio * 100.0);
  }

  return 0;
}
