FROM alpine:latest AS builder

RUN apk update && apk add build-base
WORKDIR /kubemem
COPY *.c *.h Makefile ./
RUN make

FROM alpine:latest
COPY --from=builder /kubemem/kubemem /bin
CMD ["/bin/kubemem"]
