#include "hello.h"

#include "absl/strings/str_cat.h"

namespace hello {
std::string GetGreeting(const std::string& name) { return absl::StrCat("Hello, ", name, "!"); }
}  // namespace hello
