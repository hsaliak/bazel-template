# AGENTS.md

## Repository conventions

- Exceptions are disabled in this repository. Must use `std::expected` for error handling instead of throwing exceptions.
- Use Google Test for unit tests.
- Use Google Fuzz / FuzzTest for fuzzing.
- Keep new code aligned with C++23 and the existing Bazel layout.
- Do not add Abseil dependencies back into the workspace.
