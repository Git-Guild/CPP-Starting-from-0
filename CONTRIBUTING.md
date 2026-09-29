# Contributing to C++ Starting from Zero

Thanks for your interest in contributing! This repository is a learning resource for C++ beginners, and contributions that improve or expand the learning material are always welcome.

## Ways to Contribute

- **Add new examples** -- Write clean, well-commented `.cpp` files that teach a specific concept.
- **Improve existing code** -- Fix bugs, clarify comments, or refactor for readability.
- **Fix errors** -- Correct typos, broken logic, or misleading explanations.
- **Add projects** -- Create small, beginner-friendly projects that combine multiple concepts.

## Guidelines

1. **Keep it beginner-friendly.** Code should be easy to read and understand. Use clear variable names and add comments explaining the "why," not just the "what."

2. **Follow the file naming convention.** Learning files are numbered in order of complexity (`1First_Steps.cpp`, `2Conditions.cpp`, etc.). OOPM files are named after the concept they teach. Project files use `PascalCase_with_underscores.cpp`.

3. **One concept per file.** Each Learning file should focus on teaching one or two related concepts. Don't bundle unrelated topics together.

4. **Include comments.** Use `//` or `/* */` to explain non-obvious parts of the code. Special comment tags like `// TODO:`, `//!`, and `//?` are used throughout the repo for emphasis.

5. **Test your code.** Make sure the code compiles and runs without errors before submitting.

## How to Submit Changes

1. Fork the repository.
2. Create a new branch for your changes:
   ```bash
   git checkout -b add-<topic-name>
   ```
3. Make your changes and commit with a clear message:
   ```bash
   git commit -m "Add: file-based I/O example to Learning folder"
   ```
4. Push to your fork:
   ```bash
   git push origin add-<topic-name>
   ```
5. Open a Pull Request against the `main` branch with a description of what you added or changed.

## Code Style

- Use `using namespace std;` for simplicity (this is a beginner repo).
- Keep functions short and focused.
- Use `camelCase` for variable and function names.
- Use `PascalCase` for class and struct names.
- Prefer `<iostream>`, `<vector>`, `<string>`, and other standard headers over third-party libraries.

## Reporting Issues

If you find a bug or have a suggestion, open an [Issue](https://github.com/gitguild/CPP-Starting-from-0/issues) with:

- A clear title
- A description of the problem or suggestion
- The file(s) involved, if applicable

## License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).
