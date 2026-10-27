# Session 02: Variables, Data Types and Input/Output

> Module: Programming in C · Diploma in Cybersecurity and Digital Forensics · Term 1 · ⏱ ~2 hours

Every program works with data: a user's age, a password length, an IP address octet. In this session you will learn how C stores data in **variables**, which **data types** to choose, and how to talk to the user with formatted and character input/output.

## 🎯 Learning Objectives

- Explain what a variable is and follow the naming rules
- Tell the difference between a variable and a constant
- Choose the right data type: `int`, `float`, `double`, `char`
- Use arithmetic operators `+ - * / %`
- Read and print data with `scanf()` and `printf()` format specifiers
- Read and print single characters with `getchar()` and `putchar()`

## 📖 Concepts Explained

### 1. What is a variable?

A **variable** is a named box in memory that holds a value. The value can change while the program runs.

```c
int age = 20;     // a box called age holding 20
age = 21;         // the value changes
```

> **Analogy:** a variable is a labelled locker. The label (name) stays the same; what is inside (value) can change.

**Naming rules**

| Rule | Valid | Invalid |
|---|---|---|
| Letters, digits and `_` only | `port_no` | `port-no` |
| Must not start with a digit | `ip1` | `1ip` |
| No C keywords | `total` | `int`, `return` |
| Case-sensitive | `Count` and `count` are different | |

Use meaningful names: `loginAttempts` is better than `x`.

### 2. Constants

A **constant** is a value that must not change.

```c
#define MAX_ATTEMPTS 3          // preprocessor constant (no semicolon)
const float PI = 3.14159f;      // typed constant
```

Literal constants are values written directly: `25`, `3.5`, `'A'`, `"text"`.

### 3. Basic data types

| Type | Stores | Typical size | Example |
|---|---|---|---|
| `char` | one character | 1 byte | `'Y'` |
| `int` | whole numbers | 4 bytes | `443` |
| `float` | decimal, ~6 digits precision | 4 bytes | `98.6f` |
| `double` | decimal, ~15 digits precision | 8 bytes | `3.14159265` |
| `void` | "no value" (used with functions) | - | |

**Modifiers** change range: `short`, `long`, `unsigned`. For example `unsigned int` cannot be negative but holds bigger positive values. Use `sizeof(type)` to see the size on your machine.

### 4. Arithmetic operators

| Operator | Meaning | `17 ? 5` |
|---|---|---|
| `+` | add | 22 |
| `-` | subtract | 12 |
| `*` | multiply | 85 |
| `/` | divide (int / int drops the decimal) | 3 |
| `%` | remainder (modulus, integers only) | 2 |

### 5. Formatted output with `printf()`

| Specifier | Type |
|---|---|
| `%d` | `int` |
| `%f` | `float` / `double` (use `%.2f` for 2 decimals) |
| `%c` | `char` |
| `%s` | string |
| `%u` | `unsigned int` |
| `%zu` | result of `sizeof` |

Escape sequences: `\n` new line, `\t` tab, `\\` backslash, `\"` quote.

### 6. Formatted input with `scanf()`

`scanf` reads typed input and stores it at the **address** of a variable, so we put `&` before the name:

```c
int port;
scanf("%d", &port);     // & means "address of port"
```

> ⚠️ **Security note:** always check what `scanf` returns. It returns the number of values read successfully. If the user types letters instead of a number, it returns 0 and your variable is not set.

### 7. Character I/O

`getchar()` reads one character from the keyboard; `putchar(c)` prints one character. They are simple and fast for single-key menus such as "Continue? (y/n)".

## 💻 Code Examples

### Example 1: Variables and sizes (`variables.c`)

```c
#include <stdio.h>

int main(void)
{
    int    port   = 443;       // whole number
    float  uptime = 99.9f;     // decimal number
    char   grade  = 'A';       // single character

    printf("Port   : %d\n", port);
    printf("Uptime : %.1f%%\n", uptime);   // %% prints a percent sign
    printf("Grade  : %c\n", grade);

    printf("int uses %zu bytes\n", sizeof(int));
    printf("double uses %zu bytes\n", sizeof(double));
    return 0;
}
```

**How it works:** three variables of different types are created and printed with the matching specifier. `sizeof` tells you how many bytes each type uses.

### Example 2: Simple calculator (`calculator.c`)

```c
#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Enter two whole numbers: ");
    if (scanf("%d %d", &a, &b) != 2) {     // check input was valid
        printf("Invalid input.\n");
        return 1;
    }

    printf("Sum        = %d\n", a + b);
    printf("Difference = %d\n", a - b);
    printf("Product    = %d\n", a * b);
    if (b != 0) {                           // never divide by zero
        printf("Quotient   = %d\n", a / b);
        printf("Remainder  = %d\n", a % b);
        printf("Exact      = %.2f\n", (double)a / b);
    }
    return 0;
}
```

**How it works:** `scanf` returns 2 only when both numbers were read. Integer division drops decimals, so for an exact answer we convert `a` to `double` first.

### Example 3: Character I/O (`char_io.c`)

```c
#include <stdio.h>

int main(void)
{
    int key;                         // getchar returns an int

    printf("Press a key and Enter: ");
    key = getchar();                 // read one character

    printf("You pressed: ");
    putchar(key);                    // print that character
    putchar('\n');
    return 0;
}
```

**How it works:** `getchar` waits for one character; `putchar` echoes it back.

### Example 4: Constants (`constants.c`)

The file shows `#define MAX_ATTEMPTS 3` and `const float PI` being used to calculate a circle area.

## 🧪 Lab Practice

1. Run `variables.c`. Add a `long long` variable and print its size with `%zu`.
2. Run `calculator.c` with `17 5`, then with `17 0`, then type `abc`. Observe each result.
3. Write `temp.c` that reads a temperature in Celsius (`float`) and prints Fahrenheit (`F = C * 9 / 5 + 32`).
4. Write a program that reads your initial with `getchar()` and prints it three times with `putchar()`.
5. Change `PI` in `constants.c` with an assignment and read the compiler error. Why is this useful?

## 📝 Assignment

Write `profile.c` that asks for a student's roll number (`int`), percentage (`float`) and section (`char`), then prints a neat profile card using `\t` to align values. Validate that `scanf` read each value.

## ❓ Quick Quiz

1. Which specifier prints a `float` with 2 decimal places?
2. What is the value of `17 / 5` in C when both are `int`?
3. Why do we write `&` before a variable in `scanf`?
4. Which is invalid as a variable name: `total_2`, `2total`, `Total`?
5. What does `getchar()` read?

<details>
<summary>Show answers</summary>

1. `%.2f`
2. `3` (the decimal part is dropped)
3. `scanf` needs the memory address where it should store the value.
4. `2total`
5. A single character from standard input.

</details>

## 💼 Interview Questions

**1. What is the difference between `float` and `double`?**

> `double` uses 8 bytes and keeps about 15 significant digits; `float` uses 4 bytes and about 6. Use `double` when precision matters.

**2. Difference between `#define` and `const`?**

> `#define` is a text replacement done by the preprocessor and has no type. `const` creates a typed, read-only variable that the compiler can check.

**3. Why is unchecked input dangerous?**

> If a program assumes input is valid, wrong or malicious input can cause wrong results, crashes or memory corruption. Always validate input.

## ✅ Summary

- Variables are named memory boxes; constants never change.
- Pick the right type: `char`, `int`, `float`, `double`, with modifiers for range.
- `printf` and `scanf` use format specifiers; `scanf` needs `&` and its return value should be checked.
- `getchar()` and `putchar()` handle one character at a time.

---

[⬅ Previous](../Session-01-Basics-of-C-Algorithms-and-Flowcharts/README.md) · [🏠 Module Home](../README.md) · [Next ➡](../Session-03-Operators-and-Expressions/README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
