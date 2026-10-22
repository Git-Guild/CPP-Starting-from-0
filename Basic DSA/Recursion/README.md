# Recursion

A **recursive function** is a function that calls *itself* on a smaller version of the same problem. It keeps shrinking the problem until it reaches a **base case** — the point where the answer is small enough to return directly. Without a base case, the calls never stop and the program crashes with a **stack overflow**.

```
solve(problem)
   │
   ├── small enough? ── yes ──▶ return the answer        ← base case
   │
   └── no ──▶ solve(smaller version) ──▶ use the answer  ← recursive call
```

## A First Example: Factorial

The classic starting point — and the first file here — is [`Factorial.cpp`](Factorial.cpp):

```cpp
int factorial(int n) {
    if (n <= 1) return 1;          // base case: stop calling
    return n * factorial(n - 1);   // smaller problem: n - 1
}
```

`factorial(4)` goes **down** until it hits the base case, then the answers come back **up**:

```
factorial(4)
  = 4 * factorial(3)
        = 3 * factorial(2)
              = 2 * factorial(1)
                    = 1                 ← base case
              = 2 * 1 = 2
        = 3 * 2 = 6
  = 4 * 6 = 24
```

Each call pauses at `factorial(n - 1)` and waits. When the base case returns `1`, the paused calls resume from the bottom up, multiplying as they go. That "go down, then come back up" shape is the whole idea.

## The Three Rules

Every recursive function needs exactly these:

| # | Rule | In `factorial` |
|---|------|----------------|
| 1 | **Base case** — when to stop | `if (n <= 1) return 1;` |
| 2 | **Progress** — every call must get closer to the base case | `n - 1` |
| 3 | **Recursive call** — solve the smaller problem | `factorial(n - 1)` |

Miss one and it breaks:

- no base case → the calls never end (stack overflow)
- no progress → the same call repeats forever
- no recursive call → it's just a normal function

## Why Not Just Use Loops?

Loops are simpler when the number of levels is fixed. Picking 2 characters from a string needs two nested loops; picking 3 needs three. But [`Combinations.cpp`](Combinations.cpp) lets the user choose the combination length `k`, and `k` is only known when the program runs:

```
k = 2   →   2 nested loops      easy
k = 3   →   3 nested loops      fine
k = 10  →  10 nested loops      unreadable
k = ?   →   decided by the user
```

You cannot add loops to source code while the program is running. Recursion gets around that: **one call per level**, and the number of levels can depend on the input.

```
nested loops                    recursion
────────────                    ─────────
loop for slot 1                 call for slot 1
  loop for slot 2                 call for slot 2
    ...                             ...
fixed depth in the code         depth decided at runtime
```

Tower of Hanoi has the same shape: the number of disks is an input, and the recursion goes one level deeper for each disk. A loop would have to know that depth in advance.

## More Examples

### Fibonacci — two calls per level

[`Fibonacci.cpp`](Fibonacci.cpp) adds a second base case and calls itself **twice**:

```cpp
int fib(int n) {
    if (n == 0) return 0;              // base case 1
    if (n == 1) return 1;              // base case 2
    return fib(n - 1) + fib(n - 2);    // two smaller problems
}
```

Two base cases are needed because the sequence starts with two values: `0, 1, 1, 2, 3, 5, 8, ...`. Each call branches into two more, so the call tree grows fast — `fib(30)` already makes over a million calls, recomputing the same values again and again. Caching those values (**memoization**) is the usual fix.

### Combinations — choose, recurse, un-choose

The combination code uses the three rules, plus one extra step:

```cpp
if (current.length() == k) {          // 1. base case
    arr.push_back(current);
    return;
}

for (int i = start; i < str.size(); i++) {
    current.push_back(str[i]);                         // choose
    generateCombinations(str, k, i + 1, current, arr); // 2. recurse
    current.pop_back();                                // 3. un-choose
}
```

- **Base case:** `current` already has `k` characters — save it and stop.
- **Progress:** `start = i + 1` means the next call may only pick characters *after* the one just picked, so the pool shrinks every time and `"21"` is never built after `"12"`.
- **Recursive call:** pick one character, then ask the function to pick the rest.
- **The extra step — un-choose:** after the recursive call returns, `pop_back()` removes that character so the loop can try a different one.

That last step is **backtracking**. Watch one branch for `"123"`, `k = 2`:

```
current = "1"
  push '2' → "12" → base case → save "12" → return
  pop  '2' → "1"
  push '3' → "13" → base case → save "13" → return
  pop  '3' → "1"
```

Without `pop_back()`, the next attempt would start from `"12"` instead of `"1"`, so `"13"` would never be tried. The pattern is simply: **try something, recurse, put it back.**

> The comments inside [`Combinations.cpp`](Combinations.cpp) walk through the combination logic line by line — this README stays focused on recursion.

### Tower of Hanoi — two smaller towers

[`TowerOfHanoi.cpp`](TowerOfHanoi.cpp) looks different, but it is the same idea. To move `n` disks from `src` to `to`:

1. Move the top `n - 1` disks out of the way, from `src` to `help` — **recursive**.
2. Move the biggest disk (`n`) from `src` to `to` — one direct move.
3. Move the `n - 1` disks from `help` onto the biggest disk — **recursive**.

The base case is a single disk: just move it.

```cpp
void TOH(int n, char src, char to, char help) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << to << endl;
        return;
    }

    TOH(n - 1, src, help, to);   // clear the smaller disks
    cout << "Move disk " << n << " from " << src << " to " << to << endl;
    TOH(n - 1, help, to, src);   // put them on top
}
```

This takes exactly `2^n - 1` moves: 1 disk → 1 move, 2 disks → 3, 3 disks → 7, and so on. (The `stepCount` counter in the file is omitted here.)

## Files

| # | File | What it shows | Calls per level |
|---|------|----------------|-----------------|
| 1 | [`Factorial.cpp`](Factorial.cpp) | The simplest recursion: one base case, one smaller call, answer returned back up | 1 |
| 2 | [`Fibonacci.cpp`](Fibonacci.cpp) | Two base cases and branching calls; why naive recursion repeats work | 2 |
| 3 | [`Combinations.cpp`](Combinations.cpp) | Runtime-depth recursion with choose / recurse / un-choose (backtracking) | 1 |
| 4 | [`TowerOfHanoi.cpp`](TowerOfHanoi.cpp) | Split a problem into two smaller copies of itself; `2^n - 1` moves | 2 |

## Output

**`Factorial.cpp` — `5`**
```
Enter a number for factorial: 5
The factorial of 5 is 120
```

**`Fibonacci.cpp` — `6`**
```
Enter a number for Fibonacci: 6
The 6th fibonacci number is 8
```

The code counts from `fib(0) = 0`, so index `6` gives the 7th value in `0, 1, 1, 2, 3, 5, 8, ...`.

**`Combinations.cpp` — `12345`, `k = 2`**
```
Enter your characters: 12345
Enter combination length (e.g., 2, 3, 4): 2
Generated pairs: 12 13 14 15 23 24 25 34 35 45 
```

**`TowerOfHanoi.cpp` — 3 disks**
```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total number of moves: 7
```

## Next Steps

- **Permutations** — allow every unused index, not just indices after `i`.
- **Subsets** — at each character, recurse twice: take it or skip it.
- **Memoization** — cache Fibonacci results and watch the repeated calls disappear.
- **N-Queens / Sudoku** — the same choose, recurse, un-choose pattern.
- **Binary trees** — traversal is recursion on two smaller subtrees.

Once these click, recursion stops looking like magic: it's just a function that trusts a smaller version of itself to be correct.
