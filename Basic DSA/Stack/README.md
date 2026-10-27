# Stack

A **stack** is a data structure that follows **LIFO** — *Last In, First Out*. The element added last is the first one removed, like a pile of plates: you place a plate on top and take the top plate off again.

```
            push 30
              │
              ▼
        +-----------+
        |    30     |  ◀── top   ← pop removes this one first
        +-----------+
        |    20     |
        +-----------+
        |    10     |
        +-----------+
           bottom
```

Only the **top** is reachable. You cannot pull a plate out of the middle without removing the ones above it — that restriction is exactly what makes a stack useful for undo history, function calls, back-tracking, and expression evaluation.

## The Core Operations

| Operation | What it does | Cost |
|-----------|--------------|------|
| `push(x)` | Add `x` on top | O(1) |
| `pop()` | Remove the top element | O(1) |
| `top()` / `peek` | Look at the top without removing it | O(1) |
| `empty()` | Is the stack empty? | O(1) |

Two things can go wrong, and both must be checked:

- **Overflow** — pushing onto a full stack (only possible when the capacity is fixed).
- **Underflow** — popping from an empty stack.

## Files

This folder has two files, and they teach the same structure from opposite directions.

| # | File | Approach | Size |
|---|------|----------|------|
| 1 | [`Building a Stack.cpp`](Building%20a%20Stack.cpp) | Write the stack yourself: a `Stack` class with an array/`vector` and a `top` index | Fixed — chosen at runtime |
| 2 | [`Pre-built Stack.cpp`](Pre-built%20Stack.cpp) | Use C++'s `std::stack` from `<stack>` and just call its methods | Dynamic — grows as needed |

### 1. Building a Stack — from scratch

The class keeps three things:

```cpp
int size;            // capacity set by the user
int top = -1;        // index of the top element; -1 means empty
vector<int> stack;   // the actual storage
```

`top = -1` is the key trick: an empty stack has no valid index, and the first `push` moves `top` to `0`.

```cpp
void push(int val) {
    if (top == size - 1) {
        cout << "OVERFLOW! Cannot push " << val << endl;   // full
    } else {
        top++;              // move to the next free slot
        stack[top] = val;   // store there
    }
}

void pop() {
    if (top == -1) {
        cout << "UNDERFLOW! Stack is empty." << endl;      // empty
    } else {
        cout << "Popped " << stack[top] << endl;
        top--;              // just lower the index
    }
}
```

Notice that `pop()` does not erase the value — it only moves `top` down, so the slot is simply treated as unused from then on. Writing a stack by hand makes the two boundary checks impossible to forget, which is why it comes first.

### 2. Pre-built Stack — the STL version

C++ ships the same thing as `std::stack<int>`, so none of the bookkeeping is yours to write:

```cpp
stack<int> s;

s.push(5);              // add on top
s.size();               // how many elements
s.top();                // look at the top (this is the "peek")
s.pop();                // remove the top
s.empty();              // true when nothing is left
```

Two differences from the hand-written version:

- **No overflow check is needed** — the STL stack is dynamic and resizes automatically.
- **`pop()` returns nothing** — unlike the custom `pop()` which prints the value. To know what you removed, read `s.top()` *before* calling `s.pop()`.

Printing a stack therefore means popping it until it is empty:

```cpp
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

This empties the stack as a side effect — the only way to see every element is to destroy the stack in the process.

> **Rule of thumb:** use `std::stack` in real code; build one by hand once so you know what `std::stack` is doing underneath.

## Output

**`Building a Stack.cpp` — size `5`, so the sixth push overflows**
```
Enter size of stack: 5
Pushed 5
Pushed 10
Pushed 15
Pushed 25
Pushed 19
OVERFLOW! Cannot push 9
Stack elements (Top -> Bottom): 19 25 15 10 5
Popped 19
Stack elements (Top -> Bottom): 25 15 10 5
```

**`Pre-built Stack.cpp`**
```
Total elements in stack: 5
Element at the top: 19
Popping the top element...
New element at the top: 25
Remaining elements (Top -> Bottom): 25 15 10 5
The stack is now completely empty.
```

## Next Steps

- **Reverse a string** — push every character, then pop them all.
- **Balanced brackets** — push openers, pop on a closer, and check what was on top.
- **Postfix evaluation** — push numbers, pop two on an operator.
- **Stack using a linked list** — same LIFO behaviour, but unbounded like `std::stack`.
- **Queue** — the opposite rule: First In, First Out.
