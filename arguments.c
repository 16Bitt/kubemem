#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "kubemem.h"

int kubemem_arguments(int argc, char **argv, struct kubemem_arguments *args) {
  args->warning_ratio = DEFAULT_WARNING_RATIO;
  args->failure_ratio = DEFAULT_FAILURE_RATIO;

  for(int i = 1; i < argc; i++) {
    if(strcmp(argv[i], WARNING_FLAG) == 0) {
      args->warning_ratio = strtod(argv[++i], NULL);
      if(args->warning_ratio != 0.0) {
        args->warning_ratio /= 100.0;
      }
    } else if(strcmp(argv[i], FAILURE_FLAG) == 0) {
      args->failure_ratio = strtod(argv[++i], NULL);
      if(args->failure_ratio != 0.0) {
        args->failure_ratio /= 100.0;
      }
    } else {
      fprintf(stderr, "Unrecognized argument: %s\n", argv[i]);
      return ERR_ARGUMENTS_FAILED;
    }
  }

  return 0;
}
