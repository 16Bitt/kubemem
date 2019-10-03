# Kubemem
Kubemem is a small binary intended to be used as a liveness probe inside of your
Kubernetes applications that will allow graceful failure when the memory starts
to get too high. As it is not a shell script, it should be fast and portable for
your containers.

> Kubernetes already stops containers from using too much memory! What's the point?

Kubernetes [does not offer a way](https://github.com/kubernetes/kubernetes/issues/40157)
to add a graceful handler for OOM killed containers currently, so this is a nice medium.
Where I work, we have long running Sidekiq jobs with pods that should try to exit
gracefully but are instead immediately trashed once they hit the memory threshold.

## How it works

Kubemem has two options:

* a warning percentage: When your RAM usage hits this threshold, kubemem will log the warning
* a failure percentage: When your RAM usage hits this threshold, kubemem will exit with
  a non-zero exit code, causing kubernetes to trigger a graceful kill of your pod.

Kubemem will use the meminfo kernel interface to get memory info, and then use your options
to either log or fail.

## Usage

First, pick the tag you'd like to use:

* glibc: Debian-based builds
* musl: This is what you'll select for alpine

Simply add this container as another stage in your build:

```Dockerfile
FROM sixteenbitt/kubemem:glibc AS kubemem

# Do your normal build

COPY --from=kubemem /bin/kubemem /bin/kubemem
```

And then add a probe to your deployment:

```yaml
    livenessProbe:
      exec:
        command:
        - kubemem
        - --failure
        - 95 # Fail at 95% memory
        - --warning
        - 85 # Warn at 85% or greater memory usage
      initialDelaySeconds: 5
      periodSeconds: 5
```

If you'd like to play around with it, you can run it from the command line:

```sh
docker run sixteenbitt/kubemem:musl kubemem --warning 80 --failure 90
```
