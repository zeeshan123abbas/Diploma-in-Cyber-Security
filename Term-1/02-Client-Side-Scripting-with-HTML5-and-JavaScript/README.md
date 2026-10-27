# Module 02: Client-Side Scripting with HTML5 and JavaScript

![HTML5](https://img.shields.io/badge/HTML5-E34F26?logo=html5&logoColor=white) ![CSS3](https://img.shields.io/badge/CSS3-1572B6?logo=css3&logoColor=white) ![JavaScript](https://img.shields.io/badge/JavaScript-ES2022-F7DF1E?logo=javascript&logoColor=black) ![jQuery](https://img.shields.io/badge/jQuery-3.7-0769AD?logo=jquery&logoColor=white) ![Level](https://img.shields.io/badge/Level-Beginner-2EA44F)

> Diploma in Cybersecurity and Digital Forensics · Term 1 · 10 sessions × 2 hours · [⬅ Term Home](../README.md)

Web applications are the front door of most organisations, and the most attacked one. Before you can test a login page, spot a phishing site or understand cross-site scripting, you need to know how pages are built. This module teaches HTML5 structure, CSS3 styling and modern JavaScript, always with a security eye: why `textContent` beats `innerHTML`, why client-side validation is not security, and why secrets never belong in the browser.

## 🎯 What You Will Learn

- Build valid, semantic HTML5 pages with text, lists, links, tables, forms and media
- Style pages with CSS3 selectors, Flexbox and media queries
- Write JavaScript with variables, operators, regular expressions, decisions, loops and arrays
- Use functions, objects, classes, the DOM, JSON and ES2022 features
- Draw with canvas and store data with Web Storage and IndexedDB
- Use Geolocation, maps and drag-and-drop, and understand service workers
- Apply secure front-end habits that prevent common web vulnerabilities

## 📋 Prerequisites

- Module 01 (Programming in C) or any basic programming knowledge
- Comfortable with files, folders and a web browser

## 🛠 Tools to Install

| Tool | Why you need it | Official link |
|---|---|---|
| Visual Studio Code | code editor | [https://code.visualstudio.com/](https://code.visualstudio.com/) |
| Live Server extension | runs pages on `localhost` (needed for `fetch`, Geolocation, modules) | [https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer) |
| Google Chrome / Microsoft Edge / Firefox | modern browser with DevTools | [https://www.google.com/chrome/](https://www.google.com/chrome/) |
| Node.js LTS (optional) | run plain `.js` examples from the terminal | [https://nodejs.org/](https://nodejs.org/) |
| CoffeeCup Free HTML Editor (optional) | alternative editor used in some labs | [https://www.coffeecup.com/free-editor/](https://www.coffeecup.com/free-editor/) |

## 📚 Session Index

| Session | Topic | Link |
|---|---|---|
| 01 | Introduction to the Web and HTML5 | [Open notes](./Session-01-Introduction-to-the-Web-and-HTML5/README.md) |
| 02 | Text Formatting, Lists and Hyperlinks | [Open notes](./Session-02-Text-Formatting-Lists-and-Hyperlinks/README.md) |
| 03 | CSS3, Semantic Layout and Forms | [Open notes](./Session-03-CSS3-Semantic-Layout-and-Forms/README.md) |
| 04 | Tables, Audio and Video | [Open notes](./Session-04-Tables-Audio-and-Video/README.md) |
| 05 | Practice Lab: HTML5 and CSS3 | [Open notes](./Session-05-Practice-Lab-HTML5-and-CSS3/README.md) |
| 06 | JavaScript Basics | [Open notes](./Session-06-JavaScript-Basics/README.md) |
| 07 | Functions, Objects, DOM and Modern JavaScript | [Open notes](./Session-07-Functions-Objects-DOM-and-Modern-JavaScript/README.md) |
| 08 | Canvas and Web Storage | [Open notes](./Session-08-Canvas-and-Web-Storage/README.md) |
| 09 | Geolocation, Drag and Drop and Web APIs | [Open notes](./Session-09-Geolocation-Drag-and-Drop-and-Web-APIs/README.md) |
| 10 | Practice Lab: JavaScript and Web APIs | [Open notes](./Session-10-Practice-Lab-JavaScript-and-Web-APIs/README.md) |

## 🚀 Module Mini-Project

**Cyber Awareness Portal** - a small static website that teaches online safety:

1. At least four pages with a shared semantic layout and one external stylesheet (responsive with a media query).
2. A **phishing-link trainer** page: links whose text and real `href` differ; JavaScript reveals the real destination on hover and explains the trick.
3. A **password strength meter** using regular expressions (nothing is sent anywhere).
4. A **quiz** that loads questions from JSON, shows results on a canvas chart and keeps history in `localStorage`.
5. An **incident report form** with HTML5 validation, plus a note explaining why the server must validate again.
6. All dynamic text written with `textContent`; validate every page with the W3C validator and submit the folder with screenshots.

## 🔗 Resources (official documentation)

- [MDN Web Docs: HTML](https://developer.mozilla.org/en-US/docs/Web/HTML)
- [MDN Web Docs: CSS](https://developer.mozilla.org/en-US/docs/Web/CSS)
- [MDN Web Docs: JavaScript](https://developer.mozilla.org/en-US/docs/Web/JavaScript)
- [HTML Living Standard (WHATWG)](https://html.spec.whatwg.org/)
- [jQuery API documentation](https://api.jquery.com/)
- [OWASP Cross Site Scripting Prevention Cheat Sheet](https://cheatsheetseries.owasp.org/cheatsheets/Cross_Site_Scripting_Prevention_Cheat_Sheet.html)

---

[⬅ Term Home](../README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
