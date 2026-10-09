# Basic DSA

This folder is a hands-on introduction to **data structures** in C++. Each data structure gets its own subfolder, and inside it each operation gets its own small, self-contained `.cpp` file you can read, compile, and run on its own.

Expect plain, beginner-friendly code with comments that explain the *why*, not just the *what*. It will not be as expansive as a full algorithms course — the goal is to make the **syntax and core logic** click. After that, the best teacher is solving problems and coding challenges.

## What's Inside

| Data Structure | Folder | What you'll learn |
|----------------|--------|-------------------|
| [Linked List](Linked%20List/README.md) | `Linked List/` | Nodes, head pointers, pointer manipulation, insert at first / last / position, traversal, heap memory (`new`/`delete`) |

## Prerequisites

You should already be comfortable with (from the `Learning/` folder at the repo root):

| Concept | File |
|---------|------|
| Pointers, memory addresses, pass-by-reference | [`Learning/6MemoryAddresses.cpp`](../Learning/6MemoryAddresses.cpp) |
| `struct` definition and usage | [`Learning/7RecursionsANDStructs.cpp`](../Learning/7RecursionsANDStructs.cpp) |
| Classes, objects, constructors | [`Learning/8OOPS.cpp`](../Learning/8OOPS.cpp) |

Language details that appear in these files (`nullptr`, member initializer lists, `new`/`delete`) are explained **in place, once**, in the first file that uses them — later files don't repeat them. They're tools for building data structures, not separate topics in this folder.

## How to Compile & Run

Because folder names contain spaces, quote the path. Example on Windows:

```bash
g++ -std=c++17 "Linked List/Insertion/InsertAtFirst.cpp" -o InsertAtFirst
InsertAtFirst.exe
```

On Linux/macOS:

```bash
g++ -std=c++17 "Linked List/Insertion/InsertAtFirst.cpp" -o InsertAtFirst
./InsertAtFirst
```

Or open any file in VS Code and press `Ctrl+F5` — see the [root README](../README.md#getting-started) for full setup instructions.

## Conventions in This Folder

- **One operation per file.** Each `.cpp` demonstrates exactly one idea (e.g., insert at last).
- **Self-contained files.** Every file redefines `Node`, `printList`, and the cleanup loop so it compiles alone. Repeated code has no re-explanations — concepts are taught only in the first file that needs them, then the later files say "see `InsertAtFirst.cpp`".
- **Modern C++ (C++17).** `nullptr` instead of `NULL`, member initializer lists, `struct` for plain data.
- **Actual output included.** Each file ends with a comment block showing its real, verified output, and every README shows it too.
- **Every file frees its own heap memory.** Linked lists live on the heap via `new`, so each `main()` ends with a cleanup loop — see the Linked List README for why.

More data structures will be added here as separate subfolders over time — each with its own README explaining the concept.
