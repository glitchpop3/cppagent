cc_binary(
    name = "hello-world",
    srcs = [
      "tracing/tracer_provider.h",
      "tracing/tracer_provider.cc"
   ],
    deps = [
      "@io_opentelemetry_cpp//api",
      "@io_opentelemetry_cpp//exporters/ostream:ostream_span_exporter",
      "@io_opentelemetry_cpp//sdk/src/trace",
   ],
)