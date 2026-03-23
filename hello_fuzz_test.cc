#include "hello.h"

#include "fuzztest/fuzztest.h"
#include <gtest/gtest.h>

namespace hello {
namespace {

void GreetingConcatenatesInput(const std::string& name) {
  EXPECT_EQ(GetGreeting(name), "Hello, " + name + "!");
}

FUZZ_TEST(HelloFuzzTest, GreetingConcatenatesInput);

}  // namespace
}  // namespace hello
