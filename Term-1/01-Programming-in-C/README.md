# Module 01: Programming in C

![C](https://img.shields.io/badge/Language-C17-A8B9CC?logo=c&logoColor=white) ![GCC](https://img.shields.io/badge/Compiler-GCC-2C3E50?logo=gnu&logoColor=white) ![VS Code](https://img.shields.io/badge/Editor-VS_Code-007ACC?logo=visualstudiocode&logoColor=white) ![Level](https://img.shields.io/badge/Level-Beginner-2EA44F)

> Diploma in Cybersecurity and Digital Forensics · Term 1 · 10 sessions × 2 hours · [⬅ Term Home](../README.md)

C is the language of operating systems, network devices and many security tools. Learning it gives you two things a cyber security professional needs: the habit of thinking step by step like a programmer, and an understanding of how memory works, which is the root of many real vulnerabilities such as buffer overflows and use-after-free. Every example in this module is short, commented and runnable, and many use small security-flavoured scenarios (ports, PINs, logs, ciphers).

## 🎯 What You Will Learn

- Plan solutions with algorithms and flowcharts, then write, compile and run C programs
- Store data with variables, constants and the right data types; use `printf`/`scanf` safely
- Use arithmetic, relational, logical and bitwise operators, casts and precedence
- Make decisions with `if`, `else if`, nested `if` and `switch`
- Repeat work with `for`, `while` and `do-while`, and control loops with `break`/`continue`
- Organise code into functions, understand scope, storage classes and multi-file programs
- Work with arrays, strings and 2D arrays, and avoid buffer overflows
- Understand pointers, pointer arithmetic and dynamic memory (`malloc`/`free`)

## 📋 Prerequisites

- Basic computer skills: files, folders, installing software
- Comfort with simple maths (percentages, remainders)
- No previous programming needed

## 🛠 Tools to Install

| Tool | Why you need it | Official link |
|---|---|---|
| GCC (MinGW-w64 on Windows, `build-essential` on Ubuntu/Kali) | the C compiler | [https://gcc.gnu.org/](https://gcc.gnu.org/) · [https://www.mingw-w64.org/](https://www.mingw-w64.org/) |
| Visual Studio Code + C/C++ extension | editor with highlighting and debugging | [https://code.visualstudio.com/docs/languages/cpp](https://code.visualstudio.com/docs/languages/cpp) |
| Code::Blocks (optional, all-in-one IDE) | simple IDE with a bundled compiler | [https://www.codeblocks.org/downloads/](https://www.codeblocks.org/downloads/) |
| Apache NetBeans (optional) | IDE used in some Aptech labs | [https://netbeans.apache.org/](https://netbeans.apache.org/) |

**Compile and run any example:**

```bash
gcc -Wall -Wextra file.c -o file   # compile with warnings on
./file                             # run (Windows: file.exe)
```

## 📚 Session Index

| Session | Topic | Link |
|---|---|---|
| 01 | Basics of C, Algorithms and Flowcharts | [Open notes](./Session-01-Basics-of-C-Algorithms-and-Flowcharts/README.md) |
| 02 | Variables, Data Types and Input/Output | [Open notes](./Session-02-Variables-Data-Types-and-Input-Output/README.md) |
| 03 | Operators and Expressions | [Open notes](./Session-03-Operators-and-Expressions/README.md) |
| 04 | Conditions: if, else and switch | [Open notes](./Session-04-Conditions-if-else-and-switch/README.md) |
| 05 | Practice Lab: C Basics to Conditions | [Open notes](./Session-05-Practice-Lab-C-Basics-to-Conditions/README.md) |
| 06 | Loops: for, while and do-while | [Open notes](./Session-06-Loops-for-while-do-while/README.md) |
| 07 | Functions and Storage Classes | [Open notes](./Session-07-Functions-and-Storage-Classes/README.md) |
| 08 | Arrays and Strings | [Open notes](./Session-08-Arrays-and-Strings/README.md) |
| 09 | Pointers and Memory | [Open notes](./Session-09-Pointers-and-Memory/README.md) |
| 10 | Practice Lab: Loops to Pointers | [Open notes](./Session-10-Practice-Lab-Loops-to-Pointers/README.md) |

## 🚀 Module Mini-Project

**Mini Security Toolkit (console app)** - one C program with a `do-while` menu:

1. **Port validator** - read a port, say if it is valid (0-65535) and well-known (0-1023), and name common services with `switch`.
2. **Password checker** - read with `fgets`, count upper/lower/digits/symbols, print a strength score.
3. **Caesar tool** - encrypt and decrypt a message with a chosen key; add a brute-force option.
4. **Login log summary** - store at least 10 records in arrays, count failures per user and flag suspicious users.
5. Use at least five functions, one pointer parameter, one `static` variable and one `malloc`/`free` pair.
6. Submit the `.c` file(s), a README explaining each option, and screenshots of test runs (normal, boundary and invalid input).

## 🔗 Resources (official documentation)

- [GCC online documentation](https://gcc.gnu.org/onlinedocs/)
- [C language reference (cppreference)](https://en.cppreference.com/w/c)
- [GNU C Library manual](https://www.gnu.org/software/libc/manual/)
- [SEI CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)
- [VS Code: C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)

---

[⬅ Term Home](../README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
