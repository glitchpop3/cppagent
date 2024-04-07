load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_opentelemetry_cpp",
    strip_prefix = "opentelemetry-cpp-1.14.2",
    urls = [
        "https://github.com/open-telemetry/opentelemetry-cpp/archive/refs/tags/v1.14.2.tar.gz"
    ],
)

# Load OpenTelemetry dependencies after load.
load("@io_opentelemetry_cpp//bazel:repository.bzl", "opentelemetry_cpp_deps")

opentelemetry_cpp_deps()

# (required after v1.8.0) Load extra dependencies required for OpenTelemetry
load("@io_opentelemetry_cpp//bazel:extra_deps.bzl", "opentelemetry_extra_deps")

opentelemetry_extra_deps()

# Load gRPC dependencies after load.
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

# Load extra gRPC dependencies due to https://github.com/grpc/grpc/issues/20511
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()
