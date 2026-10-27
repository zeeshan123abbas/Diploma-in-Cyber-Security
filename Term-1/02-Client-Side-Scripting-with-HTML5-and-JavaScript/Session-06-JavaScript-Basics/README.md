# Session 06: JavaScript Basics

> Module: Client-Side Scripting with HTML5 and JavaScript · Diploma in Cybersecurity and Digital Forensics · Term 1 · ⏱ ~2 hours

JavaScript turns a static page into an interactive one. It is also the language attackers use in XSS payloads and the language defenders read when analysing malicious web pages. This session is a fast but complete tour of JavaScript basics: variables, output, operators, regular expressions, decisions, loops, arrays, events and a first look at jQuery.

## 🎯 Learning Objectives

- Explain scripting and the difference between client-side and server-side JavaScript
- Declare variables with `let` and `const` and use JavaScript data types
- Display information with `console.log`, `alert`, `textContent` and use escape sequences and built-in functions
- Use operators, regular expressions and decision statements
- Repeat work with `while`, `for`, `do...while`, `break`, `continue`, `for...in` and `for...of`
- Work with one- and two-dimensional arrays, handle events, and recognise jQuery and jQuery Mobile code

## 📖 Concepts Explained

### 1. Scripting and where JavaScript runs

A **script** is a program interpreted at run time rather than compiled first. JavaScript was created in 1995 for browsers.

| Client-side JavaScript | Server-side JavaScript |
|---|---|
| runs in the user's browser | runs on a server (Node.js) |
| changes the page, validates forms | reads databases, sends e-mails |
| code is visible to anyone (View Source) | code is hidden from users |

Add JS with `<script src="app.js" defer></script>`. `defer` waits until the HTML is loaded.

### 2. Variables and data types

| Keyword | Use |
|---|---|
| `const` | value will not be reassigned (use by default) |
| `let` | value will change |
| `var` | old style; avoid (function scope, confusing) |

| Type | Example |
|---|---|
| Number | `443`, `3.14` |
| String | `"admin"`, `'x'`, `` `Hi ${name}` `` |
| Boolean | `true`, `false` |
| Undefined | declared but no value |
| Null | intentionally empty |
| Object / Array | `{ ip: "10.0.0.1" }`, `[22, 80]` |

`typeof x` tells you the type.

### 3. Showing information

| Method | Where it appears |
|---|---|
| `console.log()` | DevTools Console (best for learning and debugging) |
| `alert()` | pop-up box |
| `element.textContent = ...` | inside the page (safe: treats input as text) |
| `element.innerHTML = ...` | inside the page as HTML (**dangerous with user input: XSS**) |
| `document.write()` | old; avoid |

**Escape sequences** in strings: `\n` new line, `\t` tab, `\'`, `\"`, `\\`.

**Built-in functions:** `parseInt("42")`, `parseFloat("3.5")`, `Number("7")`, `isNaN(x)`, `String(5)`, `Math.round()`, `Math.random()`, `prompt()`, `confirm()`.

### 4. Operators

| Type | Operators |
|---|---|
| Arithmetic | `+ - * / % ** ++ --` |
| Assignment | `= += -= *= /=` |
| Comparison | `===` (equal value **and** type), `!==`, `>`, `<`, `>=`, `<=` |
| Logical | `&& \|\| !` |
| String | `+` joins strings |
| Ternary | `cond ? a : b` |

> Always use `===`. `"5" == 5` is `true` (type conversion), but `"5" === 5` is `false`.

### 5. Regular expressions

A **regex** is a pattern for matching text, written between slashes.

| Pattern | Meaning |
|---|---|
| `^` / `$` | start / end of text |
| `\d` | a digit |
| `[A-Z]` | one capital letter |
| `{3}` / `+` / `*` | exactly 3 / one or more / zero or more |
| `i` flag | ignore case |

`/^\d{1,3}(\.\d{1,3}){3}$/.test("192.168.1.10")` checks an IPv4-looking string.

### 6. Decisions and loops

`if / else if / else` and `switch` work like C. Loops: `for`, `while`, `do...while`, with `break` and `continue`.

| Loop | Iterates over |
|---|---|
| `for...in` | **keys** (property names, or indexes as strings) |
| `for...of` | **values** of an array or string |

### 7. Arrays

```js
const ports = [22, 80, 443];         // one-dimensional
ports.push(8080);                    // add at end
const grid = [[1, 0], [0, 1]];       // two-dimensional
grid[1][0];                          // row 1, column 0 -> 0
```

Useful: `length`, `push`, `pop`, `includes`, `indexOf`, `join`, `sort`.

### 8. Events and event handling

An **event** is something that happens: `click`, `input`, `submit`, `keydown`, `load`, `mouseover`. Handle it with `addEventListener`:

```js
button.addEventListener("click", function () { ... });
```

Avoid inline `onclick="..."` attributes in new code; separating JS from HTML is cleaner and works with strict Content Security Policies.

### 9. jQuery and jQuery Mobile

jQuery wraps common tasks: `$("#msg").text("Hi")` equals `document.querySelector("#msg").textContent = "Hi"`. **jQuery Mobile** was a touch-friendly UI framework built on jQuery; it is no longer maintained, so new mobile pages use responsive CSS instead. You should still recognise both when you read older sites or audit them for outdated, vulnerable libraries.

## 💻 Code Examples

### Example 1: Variables, types and output (`basics.js` with `basics.html`)

```js
const course = "Cybersecurity";     // string
let sessions = 10;                  // number
const isActive = true;              // boolean

console.log(course, typeof course);
console.log(`Sessions: ${sessions}`);     // template literal
sessions++;
console.log("After ++ :", sessions);
console.log("5" == 5, "5" === 5);         // true false
console.log(parseInt("42px"), Number("42px"));   // 42 NaN
document.querySelector("#out").textContent = `${course} has ${sessions} sessions`;
```

**How it works:** values are stored, printed to the Console, and finally written into the page safely with `textContent`.

### Example 2: IP validator with regex and events (`validator.html`)

```js
const input = document.querySelector("#ip");
const result = document.querySelector("#result");
const ipPattern = /^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$/;

input.addEventListener("input", function () {
  const match = ipPattern.exec(input.value);       // null if no match
  if (match === null) {
    result.textContent = "Not an IPv4 format";
    return;
  }
  const octets = match.slice(1).map(Number);       // four numbers
  const allValid = octets.every(n => n >= 0 && n <= 255);
  result.textContent = allValid ? "Valid IPv4 address" : "Each part must be 0-255";
});
```

**How it works:** on every keystroke the regex checks the shape, then each octet is checked for range.

### Example 3: Loops and arrays (`loops_arrays.js`)

```js
const openPorts = [22, 80, 443, 3306];

for (let i = 0; i < openPorts.length; i++) {
  if (openPorts[i] === 3306) {
    console.log("3306 (MySQL) should not be public!");
    continue;
  }
  console.log("Port", openPorts[i]);
}

for (const port of openPorts) console.log("of ->", port);   // values
for (const index in openPorts) console.log("in ->", index); // keys "0".."3"

const lab = [["PC1", "on"], ["PC2", "off"]];               // 2D array
for (const row of lab) console.log(row[0], "is", row[1]);
```

**How it works:** `for`, `for...of` and `for...in` each walk the array differently; the 2D array is an array of rows.

### Example 4: jQuery comparison (`jquery_demo.html`)

The file loads jQuery from its official CDN and shows the same click handler written in jQuery and in plain JavaScript.

## 🧪 Lab Practice

1. Open `basics.html`, press F12 → Console, and read each line of output. Add a variable of type `null` and print its `typeof`.
2. In the Console, try `0.1 + 0.2`, `"3" + 4`, `"3" * 4`, `[] + []`. Explain each result.
3. Extend `validator.html` to also accept a regex for a Pakistani mobile number `03XX-XXXXXXX`.
4. Write a loop that prints the 12 times table into a `<pre>` element.
5. In `jquery_demo.html`, add a button that hides a paragraph, first with jQuery `.hide()`, then with plain JS (`element.hidden = true`).

## 📝 Assignment

Create `password-meter.html`: as the user types in a password box, use regexes to test for lowercase, uppercase, digit, symbol and length ≥ 12, show a score from 0-5 and a label (Weak/Medium/Strong) using `textContent`, and change the label colour with an `if`/`else if` ladder. No password is sent anywhere.

## ❓ Quick Quiz

1. Which keyword should you use for a value that never gets reassigned?
2. What is the result of `"5" === 5`?
3. Why is `innerHTML` with user input dangerous?
4. What does `for...of` give you for an array?
5. What does the regex `^\d{4}$` match?

<details>
<summary>Show answers</summary>

1. `const`
2. `false` (different types)
3. The input is parsed as HTML, so injected `<script>` or event-handler code may run (XSS).
4. Each value
5. A string of exactly four digits

</details>

## 💼 Interview Questions

**1. Difference between `let`, `const` and `var`?**

> `let` and `const` are block-scoped; `const` cannot be reassigned. `var` is function-scoped and hoisted, which causes confusing bugs.

**2. Difference between `==` and `===`?**

> `==` converts types before comparing; `===` compares value and type with no conversion, so it is predictable.

**3. Is client-side JavaScript code secret?**

> No. Anyone can read it in the browser. Never put passwords, API keys or security decisions only in client-side code.

## ✅ Summary

- JavaScript runs in the browser (client) or on servers (Node.js); client code is public.
- Use `const`/`let`, `===`, template literals and `textContent`.
- Regular expressions validate patterns; loops and arrays process lists.
- Events plus `addEventListener` make pages interactive; jQuery is a helper you will meet in older code.

---

[⬅ Previous](../Session-05-Practice-Lab-HTML5-and-CSS3/README.md) · [🏠 Module Home](../README.md) · [Next ➡](../Session-07-Functions-Objects-DOM-and-Modern-JavaScript/README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
