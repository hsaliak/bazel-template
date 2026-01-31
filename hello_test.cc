#include "hello.h"

#include "gtest/gtest.h"

namespace hello {
namespace {

TEST(HelloTest, GetGreeting) { EXPECT_EQ(GetGreeting("World"), "Hello, World!"); }

TEST(HelloTest, NoExceptions) {
#ifdef __EXCEPTIONS
  FAIL() << "Exceptions are enabled, but should be disabled.";
#endif
}

}  // namespace
}  // namespace hello
