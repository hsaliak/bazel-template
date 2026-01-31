# C++ Bazel Template

A hermetic C++ template using Bazel, Clang 17, and modern C++17 standards. This project follows a flat hierarchy for simplicity and includes integrated linting and formatting.

## Features

-   **Hermetic Toolchain**: Uses LLVM 17.0.6 via `toolchains_llvm` for reproducible builds across environments.
-   **Integrated Quality Tools**:
    -   **Clang-Tidy**: Static analysis integrated into the Bazel graph.
    -   **Clang-Format**: Automated code formatting.
-   **Modern Dependencies**: Pre-configured with Abseil (C++ Common Libraries) and GoogleTest.
-   **Hardened Configuration**: Optimized `.bazelrc` with C++17 enabled and specific RPATH fixes for macOS hermeticity.

## Getting Started

### Prerequisites

-   [Bazel](https://bazel.build/install) (or `bazelisk` recommended)
-   A modern C++ compiler (though the template provides its own hermetic LLVM toolchain, Bazel requires a bootstrap compiler on some systems).

### Basic Commands

-   **Build everything**:
    ```bash
    bazel build //...
    ```
-   **Run tests**:
    ```bash
    bazel test //...
    ```
-   **Run linter manually**:
    ```bash
    bazel test //:clang_tidy_test
    ```
-   **Run with Sanitizers**:
    ```bash
    bazel test --config=asan //...
    bazel test --config=tsan //...
    bazel test --config=ubsan //...
    ```
-   **Format code**:
    ```bash
    bazel run //:format
    ```

## C++ Policy
- **No Exceptions**: The project is configured with `-fno-exceptions`. External dependencies are exempted and can still use exceptions if needed.
- **C++17**: The project uses C++17 as the default standard.

## Using as a Template for New Projects

To use this as a starting point for a new project, follow these steps:

### 1. Clone and Detach
```bash
# Clone the repository
git clone <this-repo-url> my-new-project
cd my-new-project

# Remove existing git history to start fresh
rm -rf .git
git init
```

### 2. Configure Project Identity
Open `MODULE.bazel` and update the `module()` declaration with your project name:
```python
module(
    name = "my-new-project",
    version = "0.1.0",
)
```

### 3. Clean up Samples
You can remove the sample files and update `BUILD.bazel`:
```bash
rm hello.cc hello.h hello_test.cc
```
Then, define your own targets in `BUILD.bazel`.

## Project Structure
-   `hello.h` / `hello.cc`: Sample source code.
-   `hello_test.cc`: Sample unit test.
-   `scripts/`: Internal wrappers for hermetic toolchain tools.
-   `linters.bzl`: Starlark logic for linter integration.
-   `BUILD.bazel`: Main build definition file.
-   `.bazelrc`: Global Bazel configuration and flags.
-   `.clang-tidy` & `.clang-format`: Configuration for quality tools.
