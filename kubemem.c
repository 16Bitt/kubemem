#include "kubemem.h"
#include "stdlib.h"
#include "sys/sysinfo.h"

double free_ram_ratio() {
  struct sysinfo *info = (struct sysinfo *) malloc(sizeof(struct sysinfo));
  if(info == NULL) {
    exit(ERR_MALLOC_FAILED);
  }

  int result = sysinfo(info);
  if(result != 0) {
    exit(ERR_SYSINFO_FAILED);
  }
  
  unsigned long used_mem = info->totalram - info->freeram;
  double ratio = (double) used_mem / (double) info->totalram;
  free(info);

  return ratio;
}
