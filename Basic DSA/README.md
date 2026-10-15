# Basic DSA

This folder is a hands-on introduction to **data structures** in C++. Each data structure gets its own subfolder, and inside it each operation gets its own small, self-contained `.cpp` file you can read, compile, and run on its own.

Expect plain, beginner-friendly code with comments that explain the *why*, not just the *what*. It will not be as expansive as a full algorithms course — the goal is to make the **syntax and core logic** click. After that, the best teacher is solving problems and coding challenges.

## What's Inside

| Data Structure | Folder | What you'll learn |
|----------------|--------|-------------------|
| [Linked List](Linked%20List/README.md) | `Linked List/` | Nodes, head pointers, pointer manipulation, two ways to build a list (manual linking and a `LinkedList` class), insert at first / last / position, delete at front, traversal, heap memory (`new`/`delete`) |
| ↳ operations | `Linked List/Insertion/`, `Linked List/Deletion/` | One `.cpp` per operation — insert at first, insert at last, insert at position, delete at the beginning |

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

- **One operation per file.** Each `.cpp` demonstrates exactly one idea (e.g., insert at last, delete at the beginning).
- **Self-contained files.** Every file redefines its own `Node` plus its helpers (`printList`, or the `LinkedList` class) so it compiles alone. Repeated code has no re-explanations — concepts are taught only in the first file that needs them, then the later files say "see `InsertAtFirst.cpp`".
- **Modern C++ (C++17).** `nullptr` instead of `NULL`, member initializer lists, `struct` for plain data. (The class-based files use `NULL` and `this->` — both styles appear in real code, so you should be able to read either.)
- **Actual output included.** The [Linked List README](Linked%20List/README.md) shows the real console output of every file, and the files that document it inline keep it in a comment block at the end.
- **Heap memory is the whole point.** Linked lists live on the heap via `new`, so the basics file ends with the manual cleanup loop (`delete` every node before the program ends). The later operation-focused files stop right after printing so each file stays on one idea — in real code a destructor or a smart pointer does that cleanup for you (see `OOPM/4Abstraction.cpp` and `OOPM/9More_About_Constructors.cpp`).

More data structures will be added here as separate subfolders over time — each with its own README explaining the concept.
