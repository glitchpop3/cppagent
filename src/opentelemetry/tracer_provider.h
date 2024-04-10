#include "api/include/opentelemetry/trace/tracer_provider.h"
#include "sdk/include/opentelemetry/sdk/trace/tracer_context.h"
#include "sdk/src/trace/span.h"

namespace glitchpop3 {

class TracerProvider {
 public:
  TracerProvider(std::string& service_name);
  std::shared_ptr<opentelemetry::trace::Tracer> GetTracer(
      const std::string& module_name, const std::string& module_version);

 private:
  std::unique_ptr<opentelemetry::trace::TracerProvider> tp_;
};

}  // namespace glitchpop3
