# Session 02: Text Formatting, Lists and Hyperlinks

> Module: Client-Side Scripting with HTML5 and JavaScript · Diploma in Cybersecurity and Digital Forensics · Term 1 · ⏱ ~2 hours

Text is most of what a web page shows. In this session you will format text with headings and formatting tags, organise content with lists, set backgrounds, and connect pages with hyperlinks. You will also learn why links are a favourite tool of phishing attackers, and how to spot a misleading one.

## 🎯 Learning Objectives

- Use heading tags `<h1>`-`<h6>` correctly
- Apply formatting tags such as `<strong>`, `<em>`, `<mark>`, `<sub>`, `<sup>`
- Show monospaced, preformatted and quoted text
- Build ordered, unordered and description lists
- Set background colours and images with CSS
- Create links with absolute and relative paths, to e-mail addresses and to anchors in a page

## 📖 Concepts Explained

### 1. Headings

`<h1>` is the main title (one per page), `<h2>` sections, `<h3>` sub-sections, down to `<h6>`. Do not choose a heading for its size; choose it for its level. Size can be changed with CSS.

### 2. Formatting tags

| Tag | Meaning | Looks like |
|---|---|---|
| `<strong>` | important | **bold** |
| `<em>` | emphasis | *italic* |
| `<b>` / `<i>` | bold / italic without extra meaning | |
| `<mark>` | highlighted | yellow background |
| `<small>` | fine print | smaller text |
| `<del>` / `<ins>` | deleted / inserted | ~~struck~~ / underlined |
| `<sub>` / `<sup>` | subscript / superscript | H₂O, 2¹⁰ |

### 3. Monospaced, preformatted and quoted text

| Tag | Use |
|---|---|
| `<code>` | inline code, e.g. `ping` |
| `<kbd>` | keys to press, e.g. Ctrl + C |
| `<pre>` | keeps spaces and line breaks exactly (command output, ASCII art) |
| `<blockquote>` | a long quotation, indented |
| `<q>` | a short inline quotation with quote marks |

### 4. Lists

| List | Tag | Item | Use |
|---|---|---|---|
| Unordered | `<ul>` | `<li>` | bullet points |
| Ordered | `<ol>` | `<li>` | numbered steps (`type="A"`, `start="5"`, `reversed`) |
| Description | `<dl>` | `<dt>` term, `<dd>` description | glossaries |

Lists can be nested: put a `<ul>` inside an `<li>`.

### 5. Background colour and image

Old HTML used `bgcolor`; HTML5 uses CSS:

```html
<body style="background-color: #f4f8fb;">
<div style="background-image: url('grid.png');">
```

Keep enough contrast between text and background for readability.

### 6. Hyperlinks and paths

```html
<a href="URL">link text</a>
```

| Path type | Example | When |
|---|---|---|
| Absolute | `https://owasp.org/` | another website |
| Relative (same folder) | `page2.html` | your own pages |
| Relative (sub-folder) | `notes/osi.html` | |
| Relative (parent folder) | `../index.html` | |

`target="_blank"` opens a new tab. Add `rel="noopener noreferrer"` with it so the new page cannot control your page.

### 7. E-mail, phone and anchor links

- E-mail: `<a href="mailto:info@example.com?subject=Hello">Email us</a>`
- Phone: `<a href="tel:+922100000000">Call</a>`
- Anchor (same page): give a target an `id`, then link with `#`:

```html
<a href="#lab">Go to lab</a>
...
<h2 id="lab">Lab Practice</h2>
```

- Anchor on another page: `href="notes.html#lab"`. Links can also point to files: `href="report.pdf" download`.

### 8. Links and phishing

The text of a link and its real destination can be different:

```html
<a href="http://evil.example">https://mybank.com</a>
```

Always hover to see the real URL in the status bar before clicking. Phishing e-mails use this trick every day.

## 💻 Code Examples

### Example 1: Formatting and lists (`formatting.html`)

```html
<h1>Network Security Notes</h1>
<h2>Key terms</h2>
<p><strong>Firewall:</strong> filters traffic. <em>Never</em> disable it.</p>
<p>Water is H<sub>2</sub>O and 2<sup>10</sup> = 1024.</p>
<p>Run <code>ipconfig</code> and press <kbd>Enter</kbd>.</p>
<pre>
C:\> ping 127.0.0.1
Reply from 127.0.0.1: bytes=32 time<1ms
</pre>
<blockquote>Security is a process, not a product.</blockquote>
<ol>
  <li>Identify assets</li>
  <li>Find threats
    <ul><li>Malware</li><li>Phishing</li></ul>
  </li>
  <li>Apply controls</li>
</ol>
<dl>
  <dt>CIA</dt><dd>Confidentiality, Integrity, Availability</dd>
</dl>
```

**How it works:** headings give structure, formatting tags add meaning, `<pre>` keeps command output aligned, and lists organise steps and terms.

### Example 2: Links of every kind (`links.html`)

```html
<nav>
  <a href="#top">Top</a> |
  <a href="formatting.html">Formatting page</a> |
  <a href="https://owasp.org/" target="_blank" rel="noopener noreferrer">OWASP</a> |
  <a href="mailto:lab@example.com?subject=Lab%20help">Email the lab</a>
</nav>
<h2 id="phishing">Spot the trick</h2>
<p>Hover first: <a href="https://example.com/">https://mybank.com</a></p>
```

**How it works:** one relative link, one absolute link opening safely in a new tab, one e-mail link, and one deliberately misleading link to practise hovering.

## 🧪 Lab Practice

1. Build a page with all six heading levels and look at their default sizes.
2. Write a "Top 5 security tips" ordered list starting at number 1 and a reversed version.
3. Create two pages, `home.html` and `contact.html`, in the same folder and link them both ways with relative paths.
4. Make a long page with five sections and a table of contents at the top using anchor links.
5. Add a background colour to the body and a background image to one section.

## 📝 Assignment

Create a two-page mini site **"Cyber Glossary"**: `index.html` with a description list of 10 security terms and anchor links A-Z at the top, and `about.html` linked back and forth. Include one external link to an official source (opening in a new tab with `rel="noopener noreferrer"`) and one `mailto:` link.

## ❓ Quick Quiz

1. How many `<h1>` tags should a page normally have?
2. Which tag keeps spaces and line breaks exactly?
3. Write a relative link to `index.html` in the parent folder.
4. How do you link to a section with `id="faq"` on the same page?
5. Why add `rel="noopener noreferrer"` to `target="_blank"` links?

<details>
<summary>Show answers</summary>

1. One
2. `<pre>`
3. `<a href="../index.html">Home</a>`
4. `<a href="#faq">FAQ</a>`
5. So the opened page cannot access or redirect your page through `window.opener` and does not receive the referrer.

</details>

## 💼 Interview Questions

**1. Difference between `<strong>` and `<b>`?**

> Both look bold, but `<strong>` means "important" and screen readers can stress it; `<b>` is only visual.

**2. Absolute vs relative URL?**

> An absolute URL includes the protocol and domain and works from anywhere; a relative URL is based on the current page's location and is used inside your own site.

**3. How can a hyperlink be used in phishing?**

> The visible text can show a trusted address while `href` points to an attacker's site. Users should hover to check the real link, and organisations train staff to do this.

## ✅ Summary

- Use headings for structure and formatting tags for meaning.
- `<pre>`, `<code>`, `<kbd>` and `<blockquote>` handle technical and quoted text.
- Lists: `<ul>`, `<ol>`, `<dl>`, and they can be nested.
- Links use absolute or relative paths, `mailto:`, and `#id` anchors; always check where a link really goes.

---

[⬅ Previous](../Session-01-Introduction-to-the-Web-and-HTML5/README.md) · [🏠 Module Home](../README.md) · [Next ➡](../Session-03-CSS3-Semantic-Layout-and-Forms/README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
