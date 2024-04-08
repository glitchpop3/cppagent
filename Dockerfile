FROM gcr.io/bazel-public/bazel:latest
COPY . .
RUN bazel build //src:hello-world