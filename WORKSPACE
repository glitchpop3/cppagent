load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

http_archive(
    name = "io_opentelemetry_cpp",
    strip_prefix = "opentelemetry-cpp-1.14.2",
    urls = [
        "https://github.com/open-telemetry/opentelemetry-cpp/archive/refs/tags/v1.14.2.tar.gz"
    ],
)


http_archive(
  name = "bazel_skylib",
  urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz"],
  sha256 = "f7be3474d42aae265405a592bb7da8e171919d74c16f082a5457840f06054728",
)

new_git_repository(
  name = "drogon",
  remote = "https://github.com/drogonframework/drogon.git",
  recursive_init_submodules = True,
  tag = "v1.9.3",
  build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "drogon",
    hdrs = glob([
      "lib/**/*.h",
    ]),
    strip_include_prefix = "lib",
    visibility = [
        "//visibility:public",
    ],
)
        """,
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
