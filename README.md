# C++ Starting from Zero

A hands-on learning repository for C++ fundamentals, object-oriented programming, and small practical projects. Designed for beginners who want to learn C++ by reading, modifying, and running real code examples.

Maintained by [GitGuild](https://github.com/gitguild).

## Video Resources

These videos walk through the concepts covered in this repository. Follow along with the code examples as you watch.

| Topic | Video |
|-------|-------|
| C++ Full Course (Beginner to Advanced) | [YouTube](https://youtu.be/-TkoO8Z07hI) |
| Object-Oriented Programming in C++ | [YouTube](https://youtu.be/wN0x9eZLix4) |

## Repository Structure

```
CPP-Starting-from-0/
├── Learning/          # Core C++ concept examples, ordered by topic
├── OOPM/              # Object-Oriented Programming & Modularity examples
└── Projects/          # Mini-projects combining everything learned
```

## Learning Path

Follow the files in order to progress from basics to more advanced concepts.

### 1. Learning — Core Concepts

| # | File | Topics Covered |
|---|------|----------------|
| 1 | `1First_Steps.cpp` | Output, variables, data types, arithmetic, user input, math functions |
| 2 | `2Conditions.cpp` | `if`, `else if`, `else`, comparison operators |
| 3 | `3StringsAndLoops.cpp` | String manipulation, `for` loops, `while` loops |
| 4 | `4Function_Overloading.cpp` | Writing functions, overloading (same name, different parameters) |
| 5 | `5Arrays_and_foreachloop.cpp` | Arrays, range-based `for` loops |
| 6 | `6MemoryAddresses.cpp` | Pointers, memory addresses, pass-by-reference |
| 7 | `7RecursionsANDStructs.cpp` | Recursion, `struct` definition and usage |
| 8 | `8OOPS.cpp` | Classes, objects, access modifiers, basic OOP |
| 9 | `9Overloading.cpp` | Operator and function overloading |
| 10 | `CollegeOverloading.cpp` | Additional overloading exercises |
| 11 | `HigherCollegeOverloading.cpp` | Advanced overloading examples |
| 12 | `Matrix.cpp` | 2D arrays and matrix operations |

### 2. OOPM — Object-Oriented Programming & Modularity

| File | Topics Covered |
|------|----------------|
| `Classes and Objects.cpp` | Defining classes, creating objects, public members |
| `Constructor1.cpp` | Constructors, parameterized initialization |
| `Getters and Setters (Encapsulation).cpp` | Getters, setters, encapsulation principles |
| `Abstraction.cpp` | Abstract classes, hiding implementation details |

### 3. Projects — Practice Projects

| File | Description |
|------|-------------|
| `Banking_program.cpp` | Deposit, withdrawal, and balance checking with input validation |
| `Credit_CardValidator.cpp` | Luhn algorithm implementation for card number validation |
| `Quiz.cpp` | Interactive quiz application |
| `Random_game.cpp` | Number guessing game |
| `TTT.cpp` | Tic-Tac-Toe game |

## Getting Started

### Prerequisites

- A C++ compiler (GCC, Clang, or MSVC)
- A text editor or IDE (VS Code recommended)

### Running the Examples

**Using g++ (Linux/macOS/MinGW):**

```bash
g++ Learning/1First_Steps.cpp -o first_steps
./first_steps
```

**Using VS Code with the C/C++ Extension Pack:**

1. Install the [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) from the VS Code Marketplace.
2. Open the folder in VS Code.
3. Open any `.cpp` file and press `Ctrl+F5` to run without debugging, or `F5` to run with debugging.

**Using Visual Studio (Windows):**

1. Create a new **Console Application** project.
2. Replace the generated code with the contents of any `.cpp` file.
3. Press `Ctrl+F5` to build and run.

## Recommended VS Code Extensions

| Extension | Purpose |
|-----------|---------|
| **C/C++ Extension Pack** | Core C/C++ language support, debugging, and IntelliSense |
| **C++ Quick Start Snippets** | Common C++ templates and code snippets |
| **Code Runner** | Compile and run code directly from the editor |
| **Code Spell Checker** | Catch spelling mistakes in comments and strings |
| **Colorful Comments** | Highlight special comments like `TODO`, `NOTE` for readability |
| **Indent Rainbow** | Visual indentation guides for easier alignment |

## Contributing

Contributions are welcome. If you have suggestions for new examples or improvements:

1. Fork the [repository](https://github.com/gitguild/CPP-Starting-from-0).
2. Create a new branch for your changes.
3. Add or modify `.cpp` files following the existing naming and structure conventions.
4. Open a pull request with a clear description of what was added or changed.

## License

This repository is available under the [MIT License](LICENSE).
