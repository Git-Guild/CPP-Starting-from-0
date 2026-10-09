# Linked List

A **linked list** is a data structure made of small chunks of memory called *nodes*. Each node stores a value and a link (`next` pointer) to the following node. Unlike an array, the nodes do **not** sit next to each other in memory — they are stitched together by these links.

```
head
 |
 v
+------+    +------+    +------+    +------+
|  5   | -> |  4   | -> |  3   | -> | NULL |
+------+    +------+    +------+    +------+
  node        node        node        end
```

`head` is the only way in: it is a plain pointer to the first node. `NULL` (printed at the end) marks where the list stops — the last node's `next` is `nullptr`.

## Linked List vs Array

| | Array | Linked List |
|---|---|---|
| Memory | One contiguous block | Scattered nodes, joined by pointers |
| Access by index | O(1) — direct `[i]` | O(n) — must walk from `head` |
| Insert at front | O(n) — shift everything | O(1) — relink the head |
| Insert at end | Amortized O(1) | O(n) — walk to the last node (no `tail` pointer here) |
| Size at compile time | Fixed (plain array) | Grows/shrinks freely at runtime |
| Extra memory per element | None | One pointer per node |

## Files in This Folder

| File | What it teaches | Insert cost |
|------|-----------------|-------------|
| [`Insertion/InsertAtFirst.cpp`](Insertion/InsertAtFirst.cpp) | Node anatomy, head pointer, `new`/`delete`, `Node *&head`, traversal | O(1) |
| [`Insertion/InsertAtLast.cpp`](Insertion/InsertAtLast.cpp) | Empty-list branch, walking to the last node | O(n) |
| [`Insertion/InsertAtPos.cpp`](Insertion/InsertAtPos.cpp) | 1-indexed positions, bounds checking, splicing, not leaking on error | O(pos) |

**Read them in that order** — each file only explains what is *new*; everything already covered in `InsertAtFirst.cpp` is left uncommented in the later files.

> Every `.cpp` is self-contained (it redefines `Node`, `printList`, and the cleanup loop) so you can compile any single file on its own. That duplication is intentional, not something you should copy blindly into real projects.

## Core Concepts (explained once, in `InsertAtFirst.cpp`)

### The Node

```cpp
struct Node {
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};
```

- `struct` is a `class` with everything `public` by default — ideal for a dumb data holder like a node.
- `Node *next` is a pointer **to another Node** — that self-reference is what makes a chain possible.
- The constructor uses a **member initializer list** (`: data(data), next(nullptr)`): members are set the moment the node is born, so a new node never points at garbage.

### The Head Pointer & Empty Lists

The whole list is represented by one pointer:

```cpp
Node *head = nullptr; // empty list = head that points to nothing
```

`nullptr` is the Modern C++ (C++11+) way to say "points to nothing". It replaces the old `NULL` macro; lowercase `null` is Java/JS and does not compile in C++.

### Why `Node *&head` (Reference-to-Pointer)

```cpp
void insertAtFirst(Node *&head, int data)
```

`head` is a pointer, but this function needs to **move** it. Passing `Node *head` by value would give the function a *copy* of the pointer — reassigning the copy would do nothing back in `main()`. The `&` makes the parameter an alias of `main()`'s `head`, so the assignment `head = newNode` really updates the caller's list.

### Traversal

```cpp
Node *temp = head;
while (temp != nullptr) {
    // ... use temp->data ...
    temp = temp->next; // hop forward
}
```

Since nodes are not indexed, the only way to reach node *k* is to start at `head` and hop `k` times. This pattern underlies printing, searching, and every insert in this folder.

### Memory: `new`, `delete`, and Leaks

`new Node(data)` allocates on the **heap**; C++ never frees heap memory on its own. If you drop the last pointer to a node without `delete`, that memory is **leaked**. That is why every `main()` ends with:

```cpp
while (head != nullptr) {
    Node *temp = head;
    head = head->next; // advance first...
    delete temp;       // ...then delete the node we left behind
}
```

## Insertion at First — `InsertAtFirst.cpp`

Two pointer writes, nothing else:

```cpp
newNode->next = head; // 1. new node points at the old first node
head = newNode;       // 2. head becomes the new node
```

An empty list works automatically: `head` is `nullptr`, so the new node's `next` is `nullptr` and it becomes the list.

```
Before:   head -> [1] -> [2] -> NULL
Insert 9:
Step 1:            [9] -> [1] -> [2] -> NULL   (newNode->next = head)
Step 2:   head -> [9] -> [1] -> [2] -> NULL   (head = newNode)
```

**Cost:** O(1) — no traversal, always two writes. Inserting 1→5 at the front yields a *reversed* list.

```
$ InsertAtFirst.exe
Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
```

## Insertion at Last — `InsertAtLast.cpp`

Appending needs the **last** node, and only `head` is stored — so we walk:

```cpp
if (head == nullptr) {   // empty list: nothing to walk, new node becomes head
    head = newNode;
    return;
}
Node *temp = head;
while (temp->next != nullptr) { // stop ON the last node, not past it
    temp = temp->next;
}
temp->next = newNode;           // old last node links to the new one
```

Two things are new compared to insert-at-first:

1. **Explicit empty-list branch** — without it, `temp->next` would dereference `nullptr` and crash (segmentation fault).
2. **The `while` checks `temp->next`, not `temp`** — checking `temp` would stop *past* the end with no node to link from.

**Cost:** O(n) — worst case walks the entire list. (A `tail` pointer that always remembers the last node would make this O(1); that's a common upgrade, not implemented here.)

```
$ InsertAtLast.exe
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

## Insertion at Position — `InsertAtPos.cpp`

Positions are **1-indexed**: position 1 is the front, position `len + 1` is a legal append. The function validates before walking, then splices in *behind* the previous node:

```cpp
if (pos < 1) { /* invalid, return before allocating anything */ }

if (pos == 1) { /* identical to insertAtFirst's two lines */ }

// Stop on the PREDECESSOR — the node at position (pos - 1) — then splice
int stepsToPredecessor = pos - 2;
Node *temp = head;
for (int i = 0; i < stepsToPredecessor; i++) { /* ... */ }

newNode->next = temp->next; // new node takes over the old link
temp->next = newNode;       // predecessor points at the new node
```

New ideas in this file:

- **Why `pos - 2` steps, not `pos - 1`?** The new node must land *after* the node at position `pos - 1` (its *predecessor*), so that's where `temp` must stop. `temp` already starts on position 1, so it walks `(pos - 1) - 1 = pos - 2` steps. One more step (`pos - 1`) would overshoot onto the target's own slot:

  ```
  positions:   1      2      3      4
  list:      [10] -> [20] -> [30] -> [50] -> NULL
  Insert 40 at pos = 3  →  predecessor is [20] at pos 2  →  2 - 1 = 1 step
  splice 40 in behind 20:  [10] -> [20] -> [40] -> [30] -> [50] -> NULL
  ```

- **Bounds checks mid- and post-walk** — the list can end before you reach the predecessor (asking for position 7 in a 5-node list).
- **`delete newNode` on every error path** — once `new` has run, an early `return` without `delete` leaks that node. The `pos < 1` check is placed *before* `new` so it needs no cleanup.

**Cost:** O(pos) — walks to the predecessor; worst case (insert at the end) is O(n).

```
$ InsertAtPos.exe
Position out of bounds!
Linked List: 10 -> 20 -> 40 -> 30 -> 50 -> NULL
```

(Each line of `main` inserts values 10/20/30/40/50 at positions 1/2/3/3/5 — the out-of-bounds line is `insertAtPos(head, 99, 7)`, since a 5-node list only accepts positions 1–6. The 40-at-pos-3 call is the walk case shown in the diagram above.)

## Complexity Summary

| Operation | Time | Why |
|-----------|------|-----|
| Insert at first | **O(1)** | Two pointer writes, no walking |
| Insert at last | **O(n)** | Must walk to the last node |
| Insert at position `pos` | **O(pos)** | Walk to the predecessor |
| Print / traverse | **O(n)** | Visits every node once |
| Free the list | **O(n)** | Visits every node once |
| Access by index | **O(n)** | No random access — always walk from `head` |

## Edge Cases to Remember

| Case | What should happen |
|------|--------------------|
| Empty list (`head == nullptr`) | Insert-at-first and insert-at-last must handle it (first does implicitly, last explicitly) |
| Insert at position 1 | Same two lines as insert-at-first |
| Insert past the end (`pos > len + 1`) | Reject — and `delete` the unused node |
| `pos <= 0` | Reject before allocating |
| Forgetting the cleanup loop | Memory leak (invisible in tiny programs, fatal in long-running ones) |

## Next Steps

Once these three files are comfortable, the natural follow-ups within linked lists are: **deletion**, **searching**, **reversing**, and adding a **`tail` pointer** (O(1) append), then a **doubly linked list** (each node also stores `prev`). Practice by writing them from scratch before looking up solutions.
