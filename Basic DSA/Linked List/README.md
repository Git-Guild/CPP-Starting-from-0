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

## Why Do We Need Linked Lists?

Arrays come first — and they are *good*. The linked list only earns its place where the array's memory shape breaks down. Walk the two array flavours below, watch each one hit a wall, and the answer writes itself.

---

### 1. The Array — one solid block

Every element sits **next to its neighbour**, so the address of `a[i]` is pure arithmetic — no lookup, no walking:

```
   &a[i] = base + i × sizeof(int)      one multiplication  →  O(1)

index:    0      1      2      3      4          base = 0x1000
         +------+------+------+------+------+
    a →  |  10  |  20  |  30  |  40  |  50  |
         +------+------+------+------+------+
addr:   0x1000 0x1004 0x1008 0x100C 0x1010
         ▲ one contiguous block — no gaps
```

- **Fast:** jump straight to `a[3]`, and the CPU pre-fetches the neighbours too (cache-friendly).
- **Wall #1 — inserting at the front shoves everything sideways:**

```
insert 5 at index 0                       elements moved: 5 4 3 2 1 0

before   [10][20][30][40][50]
                    └──── all slide right ────▶
shift    [   ][10][20][30][40][50]
after    [ 5 ][10][20][30][40][50]         O(n) — n moves for ONE insert
```

- **Wall #2 — the size is baked in:** `int a[5];` can never hold a 6th number.

---

### 2. ArrayList — the array that learned to grow

An **ArrayList** (Java's `ArrayList`, C++'s `std::vector`) keeps two counters: `size` (what's used) and `capacity` (what's reserved), and over-allocates on purpose so appends rarely resize:

```
size = 3, capacity = 8

index:  0     1     2     3     4     5     6     7
      +-----+-----+-----+-----+-----+-----+-----+-----+
      |  10 |  20 |  30 |  ~  |  ~  |  ~  |  ~  |  ~  |
      +-----+-----+-----+-----+-----+-----+-----+-----+
       \_________ used ________/ \_______ free _______/

add(40) → drop it in slot 3, size++        O(1), nothing shifts
```

- **Wall #1 still stands** — `add(0, 5)` at the front slides every element, exactly like a plain array.
- **Wall #3 — running out of room means copying everything:**

```
capacity 4, size 4 — FULL
      +-----+-----+-----+-----+
      |  10 |  20 |  30 |  40 |
      +-----+-----+-----+-----+
             │  allocate 8 slots, COPY all 4  →  O(n) hitch
             ▼
      +-----+-----+-----+-----+-----+-----+-----+-----+
      |  10 |  20 |  30 |  40 |  ~  |  ~  |  ~  |  ~  |   old block freed
      +-----+-----+-----+-----+-----+-----+-----+-----+

Because capacity DOUBLES (4 → 8 → 16 …), copies happen 1, 2, 4, 8 … times,
so the cost SPREADS OUT: appends are only *amortized* O(1).
```

---

### 3. Both walls break → that's what a linked list is for

```
   Array / ArrayList                    Linked List
   = parked cars in a row               = cars joined by tow ropes

   [10][20][30][40][50]                 (10) ─▶ (20) ─▶ (30) ─▶ (40)
    ▲ to make room at the front           ▲ to make room at the front:
      every car backs up                   untie one rope, move head — done
```

---

### Which one should I pick?

```
          do you read a[i] by index a lot? / need max speed?
                          │
              ┌── yes ────┴──── no ────┐
              ▼                         ▼
      insert only at the end?    insert / delete often at
              │                  the FRONT or MIDDLE?
       ┌─ yes ┴─ no ─┐                │
       ▼             ▼          ┌─ yes ┴─ no ─┐
   ArrayList     plain array    ▼             ▼
  (std::vector)                 Linked List   ArrayList is plenty
```

**One-line rule:** arrays are for *looking things up*, linked lists are for *rewiring the order*.

---

### Cost at a glance

`█` ≈ one unit of work — longer bar = slower

```
                        Array / ArrayList         Linked List
read by index a[i]      ██  O(1)                  ██████████  O(n)
insert at front         ██████████  O(n)          ██  O(1)
insert at back          ██  O(1) *                ██████████  O(n)
insert at position p    █████  O(p)               █████  O(p) once you arrive
search / traverse       ██████████  O(n)          ██████████  O(n)
reserve new memory      one contiguous block      never — nodes fit anywhere

* amortized: a rare O(n) resize hides inside the average
```

### Array vs ArrayList vs Linked List

| | Plain Array | ArrayList (`std::vector`) | Linked List |
|---|---|---|---|
| Memory | One contiguous block | One contiguous block | Scattered nodes, joined by pointers |
| Size | Fixed at compile time | Grows/shrinks at runtime | Grows/shrinks freely, one node at a time |
| Access by index | O(1) | O(1) | O(n) — must walk from `head` |
| Insert at front | O(n) — shift everything | O(n) — shift everything | **O(1)** — relink the head |
| Insert in middle | O(n) — shift the tail | O(n) — shift the tail | **O(1)** — relink 2 pointers |
| Insert at end | O(n) or fixed full | Amortized O(1) | O(n) — walk to the last node (no `tail` pointer here) |
| Growing | Impossible | Resize = copy the whole block | Allocate just the one node |
| Wasted memory | None | `capacity − size` idle slots | One pointer per node |
| Cache behaviour | Excellent (contiguous) | Excellent (contiguous) | Poor (nodes scatter) |

## Files

The *why* is above. The *how* lives only in the code — every `.cpp` is commented, self-contained (it redefines `Node`, `printList`, and the cleanup loop), and compiles on its own.

| # | File | Teaches | Cost |
|---|------|---------|------|
| 1 | [`Insertion/InsertAtFirst.cpp`](Insertion/InsertAtFirst.cpp) | Node anatomy, `head`, `new`/`delete`, `Node *&head`, traversal | O(1) |
| 2 | [`Insertion/InsertAtLast.cpp`](Insertion/InsertAtLast.cpp) | Empty-list branch, walking to the last node | O(n) |
| 3 | [`Insertion/InsertAtPos.cpp`](Insertion/InsertAtPos.cpp) | 1-indexed positions, bounds checking, splicing, no leaks | O(pos) |

**Read them in that order** — each file only comments what is *new*; anything already covered in file 1 is left uncommented afterwards.

> The duplicated setup across files is intentional for standalone compiling, not a pattern to copy into real projects.

## Next Steps

Once these three are comfortable: **deletion**, **searching**, **reversing**, a **`tail` pointer** (O(1) append), then a **doubly linked list** (`prev` in each node). Write them from scratch before looking up solutions.
