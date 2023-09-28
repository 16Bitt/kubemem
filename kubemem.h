#ifndef KUBEMEM_H
#define KUBEMEM_H

#define ERR_MALLOC_FAILED 1
#define ERR_CGROUP_READ_FAILED 2
#define ERR_ARGUMENTS_FAILED 3
#define ERR_MEMORY_LOW 4
#define ERR_LOGFILE_FAILED 5

#define DEFAULT_WARNING_RATIO 0.75
#define DEFAULT_FAILURE_RATIO 0.90
#define DEFAULT_LOGFILE_PATH "/dev/stdout"

#define WARNING_FLAG "--warning"
#define FAILURE_FLAG "--failure"
#define LOGFILE_FLAG "--logfile"

#define CGROUP_BYTES_USED "/sys/fs/cgroup/memory.current"
#define CGROUP_BYTES_LIMIT "/sys/fs/cgroup/memory.max"

struct kubemem_arguments {
  double warning_ratio;
  double failure_ratio;
  char *logfile_path;
};

double free_ram_ratio();
int kubemem_arguments(int argc, char **argv, struct kubemem_arguments *args);

#endif
