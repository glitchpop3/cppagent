#include "sdk/include/opentelemetry/sdk/trace/tracer_provider.h"

#include <iostream>

#include "opentelemetry/exporters/ostream/span_exporter_factory.h"
#include "opentelemetry/sdk/common/attribute_utils.h"
#include "opentelemetry/sdk/trace/exporter.h"
#include "sdk/include/opentelemetry/sdk/trace/batch_span_processor_factory.h"
#include "sdk/include/opentelemetry/sdk/trace/batch_span_processor_options.h"
#include "sdk/include/opentelemetry/sdk/trace/tracer_context.h"
#include "sdk/src/trace/span.h"
#include "tracer_provider.h"

namespace glitchpop3 {

TracerProvider::TracerProvider(std::string& service_name) {
  // create span exporter
  std::unique_ptr<opentelemetry::sdk::trace::SpanExporter> exporter =
      opentelemetry::exporter::trace::OStreamSpanExporterFactory::Create();

  // create batchspanexporter processor
  opentelemetry::sdk::trace::BatchSpanProcessorOptions bsp_options;
  std::unique_ptr<opentelemetry::sdk::trace::SpanProcessor>
      batch_span_processor =
          opentelemetry::sdk::trace::BatchSpanProcessorFactory::Create(
              std::move(exporter), bsp_options);

  opentelemetry::sdk::common::AttributeMap common_attributes;
  common_attributes.SetAttribute("service.name", service_name);

  // create the resource for setting otel sdk details and service name
  opentelemetry::sdk::resource::Resource resource =
      opentelemetry::sdk::resource::Resource::Create(common_attributes);

  tp_ = std::make_unique<opentelemetry::sdk::trace::TracerProvider>(
      std::move(batch_span_processor), resource);
}

std::shared_ptr<opentelemetry::trace::Tracer> TracerProvider::GetTracer(
    const std::string& module_name, const std::string& module_version) {
  auto temp = tp_->GetTracer(module_name, module_version);
  std::shared_ptr<opentelemetry::trace::Tracer> ptr(temp.get());
  return ptr;
}

}  // namespace glitchpop3

int main() {
  std::string service_name = "test";
  glitchpop3::TracerProvider tracerProvider(service_name);
  std::shared_ptr<opentelemetry::trace::Tracer> tracer =
      tracerProvider.GetTracer("test", "test");
  auto span = tracer->StartSpan("test span");
  span->SetAttribute("jacob", "test");
  span->End();
  std::cout << "Hello World\n";
}