# Session 08: Canvas and Web Storage

> Module: Client-Side Scripting with HTML5 and JavaScript · Diploma in Cybersecurity and Digital Forensics · Term 1 · ⏱ ~2 hours

HTML5 gave the browser two powerful abilities: drawing graphics with `<canvas>` and storing data on the user's device with Web Storage and IndexedDB. You will draw shapes, colours, images and text, handle page events, load external content, store data locally, and compare HTML5 web apps with native mobile apps. You will also learn what must **never** be kept in browser storage.

## 🎯 Learning Objectives

- Draw lines, rectangles, circles, text and images on a `<canvas>`
- Use colours, gradients and transparency (`globalAlpha`, `rgba`)
- Create page events with JavaScript and jQuery, and include external content (`fetch`, `<iframe>`)
- Store data with `localStorage` and `sessionStorage` and explain the difference
- Describe the IndexedDB API for larger structured data
- Compare native apps and HTML5 apps and outline how to package a web app as an app

## 📖 Concepts Explained

### 1. The canvas

```html
<canvas id="board" width="400" height="250"></canvas>
```

```js
const ctx = document.querySelector("#board").getContext("2d");
```

The **context** (`ctx`) is your pen. Coordinates start at the **top-left** (0, 0); x grows right, y grows down.

| Task | Methods |
|---|---|
| Line | `beginPath()`, `moveTo(x,y)`, `lineTo(x,y)`, `stroke()` |
| Rectangle | `fillRect(x,y,w,h)`, `strokeRect(...)`, `clearRect(...)` |
| Circle/arc | `arc(x, y, r, startAngle, endAngle)` then `fill()` or `stroke()` |
| Text | `font = "20px Arial"`, `fillText("Hi", x, y)` |
| Image | `drawImage(img, x, y, w, h)` (after the image loads) |
| Style | `fillStyle`, `strokeStyle`, `lineWidth` |

### 2. Colour and transparency

- Colours: `"red"`, `"#0b3d91"`, `"rgb(11,61,145)"`, `"rgba(11,61,145,0.5)"` (0.5 = half transparent).
- `ctx.globalAlpha = 0.3` makes everything drawn after it 30% opaque.
- Gradients: `ctx.createLinearGradient(x0,y0,x1,y1)` with `addColorStop(0, "blue")`.

### 3. Page events with JavaScript and jQuery

| Event | Fires when |
|---|---|
| `DOMContentLoaded` | HTML is parsed |
| `load` | page and images are loaded |
| `click`, `mousemove` | mouse actions (canvas drawing apps use these) |
| `keydown` | key pressed |
| `resize` | window size changes |

jQuery equivalents: `$(document).ready(fn)` and `$("#board").on("click", fn)`.

### 4. Including external content

- `fetch("data.json").then(r => r.json())` loads data from the same site (or another site that allows it via CORS).
- `<iframe src="page.html" title="...">` embeds another page. Use the `sandbox` attribute to limit what an embedded page can do.

### 5. Web Storage

| | `localStorage` | `sessionStorage` |
|---|---|---|
| Lifetime | until deleted | until the tab closes |
| Shared between tabs | yes (same site) | no |
| Size | about 5-10 MB per site | similar |
| API | `setItem`, `getItem`, `removeItem`, `clear` | same |

Values are always **strings**; store objects with `JSON.stringify` and read them with `JSON.parse`.

> 🔐 **Never store passwords, tokens or personal data in Web Storage.** Any script on the page, including an injected XSS script, can read it. Session tokens belong in `HttpOnly` cookies that JavaScript cannot read.

### 6. IndexedDB

A browser database for **large, structured** data (thousands of records, files) with indexes and transactions. Its API is asynchronous and event-based: open a database, create an **object store** in `onupgradeneeded`, then add/read records inside **transactions**. Used by offline apps such as web mail and notes.

### 7. Native apps vs HTML5 apps

| | Native app | HTML5 / web app |
|---|---|---|
| Built with | Kotlin/Java (Android), Swift (iOS) | HTML, CSS, JavaScript |
| Installed from | app store | browser (or installable PWA) |
| Device access | full (camera, sensors, Bluetooth) | limited but growing |
| Performance | best | good for most apps |
| One code base for all platforms | no | yes |
| Updates | through store review | instant on the server |

### 8. Turning an HTML5 app into a "native" app

1. Make it a **Progressive Web App (PWA)**: add a web app manifest (`manifest.json`) and a service worker for offline use; users can "Install" it.
2. Or wrap it with a tool such as **Apache Cordova** or **Capacitor**, which puts the web app inside a native shell and gives access to device APIs.
3. Build, test on devices, sign and publish to the app stores.

## 💻 Code Examples

### Example 1: Drawing a network diagram (`canvas_draw.html`)

```js
const ctx = document.querySelector("#board").getContext("2d");

ctx.strokeStyle = "#555"; ctx.lineWidth = 3;          // cables
ctx.beginPath(); ctx.moveTo(200, 60); ctx.lineTo(80, 180); ctx.stroke();
ctx.beginPath(); ctx.moveTo(200, 60); ctx.lineTo(320, 180); ctx.stroke();

ctx.fillStyle = "#0b3d91";                            // router (circle)
ctx.beginPath(); ctx.arc(200, 60, 30, 0, Math.PI * 2); ctx.fill();

ctx.fillStyle = "rgba(39, 174, 96, 0.7)";             // PCs, semi-transparent
ctx.fillRect(50, 170, 60, 40);
ctx.fillRect(290, 170, 60, 40);

ctx.fillStyle = "#000"; ctx.font = "16px Arial";      // labels
ctx.fillText("Router", 172, 110);
ctx.fillText("PC1", 65, 230); ctx.fillText("PC2", 305, 230);
```

**How it works:** lines are drawn first, then shapes on top, then text. `rgba` with 0.7 makes the PCs slightly transparent.

### Example 2: Theme and notes with Web Storage (`storage.html`)

```js
const notes = document.querySelector("#notes");
notes.value = localStorage.getItem("labNotes") ?? "";        // load saved notes

notes.addEventListener("input", () => {
  localStorage.setItem("labNotes", notes.value);             // save on every change
});

let visits = Number(sessionStorage.getItem("visits") ?? 0) + 1;
sessionStorage.setItem("visits", visits);                    // only for this tab
document.querySelector("#visits").textContent = `Visits in this tab: ${visits}`;
```

**How it works:** notes survive a browser restart (`localStorage`); the visit counter resets when the tab closes (`sessionStorage`).

### Example 3: IndexedDB scan log (`indexeddb.html`)

See the file: opens a database `labDB`, creates a `scans` store, adds a record and lists all records.

### Example 4: Loading external JSON (`fetch_demo.html` + `devices.json`)

Uses `fetch` to load `devices.json` and lists each device. Open it with VS Code Live Server (fetch does not work from `file://`).

## 🧪 Lab Practice

1. In `canvas_draw.html`, add a third PC and a cable, and a gradient background behind everything.
2. Add a `click` listener to the canvas that draws a small circle wherever you click.
3. In `storage.html`, open DevTools → Application → Local Storage and watch the value change as you type.
4. Store an object `{theme: "dark", fontSize: 18}` with `JSON.stringify` and read it back.
5. Run `indexeddb.html`, add three records, then find them in DevTools → Application → IndexedDB.

## 📝 Assignment

Build `sketch-pad.html`: a canvas drawing app (draw with the mouse, choose colour and line width, "Clear" button) that saves the drawing to `localStorage` with `canvas.toDataURL()` and restores it on reload. Add a short paragraph in the page explaining why you would never store a login token the same way.

## ❓ Quick Quiz

1. Where is point (0, 0) on a canvas?
2. Which method draws a circle?
3. Difference between `localStorage` and `sessionStorage`?
4. Why must objects be converted with `JSON.stringify` before storing?
5. Name one way to turn a web app into an installable app.

<details>
<summary>Show answers</summary>

1. The top-left corner
2. `arc()` (with angles 0 to `2 * Math.PI`)
3. `localStorage` stays until deleted; `sessionStorage` is cleared when the tab closes.
4. Web Storage only stores strings.
5. Make it a PWA (manifest + service worker), or wrap it with Cordova/Capacitor.

</details>

## 💼 Interview Questions

**1. Is it safe to store a JWT or session token in `localStorage`?**

> It is risky: any XSS can read it. Prefer `HttpOnly`, `Secure`, `SameSite` cookies, plus strong XSS prevention.

**2. When would you use IndexedDB instead of `localStorage`?**

> For large or structured data, queries by index, binary files, or offline-first apps, because IndexedDB is asynchronous and much bigger.

**3. Canvas vs SVG?**

> Canvas is pixel-based and good for games and many fast-changing shapes; SVG is vector-based, each shape is a DOM element, and it scales perfectly.

## ✅ Summary

- `<canvas>` + a 2D context draws lines, shapes, text and images; colours can be transparent.
- Events (JS or jQuery) make drawings and pages interactive; `fetch` and `<iframe>` bring in external content.
- `localStorage` persists, `sessionStorage` lasts for a tab, IndexedDB handles big structured data.
- Never keep secrets in browser storage.
- HTML5 apps can become installable apps via PWAs or wrappers.

---

[⬅ Previous](../Session-07-Functions-Objects-DOM-and-Modern-JavaScript/README.md) · [🏠 Module Home](../README.md) · [Next ➡](../Session-09-Geolocation-Drag-and-Drop-and-Web-APIs/README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
