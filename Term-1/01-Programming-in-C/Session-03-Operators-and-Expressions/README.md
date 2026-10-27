# Session 03: Operators and Expressions

> Module: Programming in C · Diploma in Cybersecurity and Digital Forensics · Term 1 · ⏱ ~2 hours

Operators are the verbs of a programming language: they add, compare, combine and change values. Security work uses them all the time, for example bitwise operators to read flags in a TCP header or to calculate a network address from an IP and a subnet mask. This session covers every operator family you need, plus casts and precedence.

## 🎯 Learning Objectives

- Use simple and compound assignment operators
- Write arithmetic expressions, including increment and decrement
- Compare values with relational operators and combine them with logical operators
- Apply bitwise operators `& | ^ ~ << >>` to integers
- Convert types with casts
- Predict results using operator precedence

## 📖 Concepts Explained

### 1. Assignment operators

| Operator | Example | Same as |
|---|---|---|
| `=` | `x = 5` | put 5 in x |
| `+=` | `x += 3` | `x = x + 3` |
| `-=` | `x -= 2` | `x = x - 2` |
| `*=` | `x *= 4` | `x = x * 4` |
| `/=` | `x /= 2` | `x = x / 2` |
| `%=` | `x %= 3` | `x = x % 3` |

### 2. Arithmetic expressions, increment and decrement

An **expression** is any combination of values, variables and operators that produces a value, such as `price * qty + tax`.

`++` adds 1 and `--` subtracts 1:

- `count++` (postfix): use the old value first, then add 1.
- `++count` (prefix): add 1 first, then use the new value.

### 3. Relational operators

They compare two values and give **1 (true)** or **0 (false)**.

| Operator | Meaning |
|---|---|
| `==` | equal to (two `=` signs!) |
| `!=` | not equal to |
| `>` `<` | greater / less than |
| `>=` `<=` | greater or equal / less or equal |

> ⚠️ A classic bug: `if (x = 5)` assigns 5 and is always true. You meant `if (x == 5)`.

### 4. Logical operators

| Operator | Name | True when |
|---|---|---|
| `&&` | AND | both sides are true |
| `\|\|` | OR | at least one side is true |
| `!` | NOT | the value is false |

C uses **short-circuit** evaluation: in `a && b`, if `a` is false, `b` is not even checked.

### 5. Bitwise operators

These work on the individual bits of an integer.

| Operator | Name | `12 ? 10` (1100 and 1010) |
|---|---|---|
| `&` | AND | `1000` = 8 |
| `\|` | OR | `1110` = 14 |
| `^` | XOR | `0110` = 6 |
| `~` | NOT (flip all bits) | `~12` = -13 for a signed int |
| `<<` | shift left | `12 << 1` = 24 |
| `>>` | shift right | `12 >> 2` = 3 |

**Security uses:** checking permission flags, computing network addresses (`ip & mask`), and the simple XOR cipher you will see below (for learning only; it is not real encryption).

### 6. Casts (type conversion)

- **Implicit:** C converts automatically, e.g. `int + double` becomes `double`.
- **Explicit cast:** you force a type: `(double)total / count`.

```c
int marks = 7, subjects = 2;
double avg1 = marks / subjects;           // 3.0  (int division first)
double avg2 = (double)marks / subjects;   // 3.5  (correct)
```

### 7. Precedence and associativity

When an expression has many operators, C follows an order (high to low, simplified):

| Level | Operators |
|---|---|
| 1 | `()` `++` `--` (postfix) |
| 2 | `!` `~` `++` `--` (prefix) casts |
| 3 | `*` `/` `%` |
| 4 | `+` `-` |
| 5 | `<<` `>>` |
| 6 | `<` `<=` `>` `>=` |
| 7 | `==` `!=` |
| 8 | `&` then `^` then `\|` |
| 9 | `&&` then `\|\|` |
| 10 | `=` `+=` `-=` ... |

**Rule of thumb:** when in doubt, add brackets. `(a + b) * c` is clearer than relying on memory.

## 💻 Code Examples

### Example 1: Assignment and increment (`assign_ops.c`)

```c
#include <stdio.h>

int main(void)
{
    int score = 10;

    score += 5;                 // 15
    score *= 2;                 // 30
    score -= 4;                 // 26
    printf("score = %d\n", score);

    int a = 5;
    int b = a++;                // b gets 5, then a becomes 6
    int c = ++a;                // a becomes 7, then c gets 7
    printf("a=%d b=%d c=%d\n", a, b, c);
    return 0;
}
```

**How it works:** compound operators update a variable in one step. Postfix gives the old value, prefix gives the new one.

### Example 2: Password rule checker (`logic_ops.c`)

```c
#include <stdio.h>

int main(void)
{
    int length = 10;        // password length
    int hasDigit = 1;       // 1 = yes, 0 = no
    int hasSymbol = 0;

    int strong = (length >= 8) && hasDigit && hasSymbol;
    int okay   = (length >= 8) && (hasDigit || hasSymbol);

    printf("Strong: %d\n", strong);   // 0
    printf("Okay  : %d\n", okay);     // 1
    printf("Not strong: %d\n", !strong);
    return 0;
}
```

**How it works:** relational operators give 1/0, logical operators combine them into a final rule.

### Example 3: Network address with bitwise AND (`bitwise_ops.c`)

```c
#include <stdio.h>

int main(void)
{
    unsigned int lastOctet = 200;   // host part of 192.168.1.200
    unsigned int maskOctet = 192;   // last octet of mask 255.255.255.192

    // network = ip AND mask
    printf("Network octet  : %u\n", lastOctet & maskOctet);   // 192

    unsigned int flags = 0;
    flags = flags | 4;          // turn ON bit 2 (value 4)
    printf("Flag 4 set? %u\n", (flags & 4) != 0);

    printf("8 << 1 = %u\n", 8u << 1);   // 16
    printf("8 >> 2 = %u\n", 8u >> 2);   // 2
    return 0;
}
```

**How it works:** `&` keeps only bits that are 1 in both numbers, which is exactly how a router finds the network part of an address.

### Example 4: Casts and precedence (`casts_precedence.c`)

The file shows integer vs. real division, and how `2 + 3 * 4` (14) differs from `(2 + 3) * 4` (20).

## 🧪 Lab Practice

1. Run `assign_ops.c`. Predict each printed value on paper first, then compare.
2. In `logic_ops.c`, set `hasSymbol = 1` and check that `strong` becomes 1.
3. Change `lastOctet` in `bitwise_ops.c` to 70 and 130 and write down the network octet each time.
4. Write `xor_demo.c`: store `char letter = 'A'`, XOR it with key `7`, print the result, then XOR again and show you get `'A'` back.
5. Evaluate by hand, then in code: `10 - 4 / 2 * 3` and `(10 - 4) / (2 * 3)`.

## 📝 Assignment

Write `even_odd_bits.c` that reads an integer and prints whether it is even or odd using **two methods**: the `%` operator and the bitwise `& 1` test. Also print the number multiplied by 8 using a left shift.

## ❓ Quick Quiz

1. What is the value of `x` after `int x = 7; x %= 4;`?
2. What does `5 > 3 && 2 > 4` give?
3. What is `6 & 3`?
4. Why does `(double)7 / 2` give 3.5 but `7 / 2` gives 3?
5. Which runs first in `a + b * c`?

<details>
<summary>Show answers</summary>

1. `3`
2. `0` (false), because the second part is false
3. `2` (110 & 011 = 010)
4. The cast makes one operand `double`, so real division is used instead of integer division.
5. `b * c` (multiplication has higher precedence)

</details>

## 💼 Interview Questions

**1. Difference between `=` and `==`?**

> `=` assigns a value; `==` compares two values. Mixing them up is a common bug that compilers warn about with `-Wall`.

**2. Where are bitwise operators used in networking?**

> Subnet calculations (`ip & mask`), reading flag bits in packet headers (SYN, ACK), and packing/unpacking protocol fields with shifts.

**3. What is short-circuit evaluation?**

> In `&&` and `||`, C stops evaluating once the result is known. It is used safely, e.g. `if (p != NULL && p->value > 0)`.

## ✅ Summary

- Compound assignment (`+=` etc.) and `++`/`--` shorten common updates.
- Relational operators give 1/0; logical operators combine conditions with short-circuiting.
- Bitwise operators work bit by bit and power subnetting and flag checks.
- Use casts to control division and brackets to control precedence.

---

[⬅ Previous](../Session-02-Variables-Data-Types-and-Input-Output/README.md) · [🏠 Module Home](../README.md) · [Next ➡](../Session-04-Conditions-if-else-and-switch/README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
