#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "kubemem.h"

bool arg_next_bounds_check(char *flag_name, int argc, int idx) {
  if(idx + 1 >= argc) {
    fprintf(stderr, "Missing required parameter for %s\n", flag_name);
    return false;
  }

  return true;
}

int kubemem_arguments(int argc, char **argv, struct kubemem_arguments *args) {
  args->warning_ratio = DEFAULT_WARNING_RATIO;
  args->failure_ratio = DEFAULT_FAILURE_RATIO;
  args->logfile_path = DEFAULT_LOGFILE_PATH;

  for(int i = 1; i < argc; i++) {
    if(strcmp(argv[i], WARNING_FLAG) == 0) {
      if(!arg_next_bounds_check(WARNING_FLAG, argc, i)) {
	return ERR_ARGUMENTS_FAILED;
      }

      args->warning_ratio = strtod(argv[++i], NULL);
      args->warning_ratio /= 100.0;
    } else if(strcmp(argv[i], FAILURE_FLAG) == 0) {
      if(!arg_next_bounds_check(FAILURE_FLAG, argc, i)) {
	return ERR_ARGUMENTS_FAILED;
      }
 
      args->failure_ratio = strtod(argv[++i], NULL);
      args->failure_ratio /= 100.0;
    } else if(strcmp(argv[i], LOGFILE_FLAG) == 0) {
      if(!arg_next_bounds_check(LOGFILE_FLAG, argc, i)) {
	return ERR_ARGUMENTS_FAILED;
      }
      
      args->logfile_path = argv[++i];
    } else {
      fprintf(stderr, "Unrecognized argument: %s\n", argv[i]);
      return ERR_ARGUMENTS_FAILED;
    }
  }

  return 0;
}

