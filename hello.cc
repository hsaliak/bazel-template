#include "hello.h"

namespace hello {
std::string GetGreeting(const std::string& name) { return "Hello, " + name + "!"; }
}  // namespace hello
