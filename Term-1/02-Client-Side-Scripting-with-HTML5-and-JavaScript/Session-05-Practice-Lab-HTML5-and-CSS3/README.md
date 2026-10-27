# Session 05: Practice Lab: HTML5 and CSS3

> Module: Client-Side Scripting with HTML5 and JavaScript · Diploma in Cybersecurity and Digital Forensics · Term 1 · ⏱ ~2 hours

A hands-on revision lab for Sessions 1-4. You will build a small, complete website for a fictional **CyberSafe Karachi** awareness campaign using HTML5 structure, text formatting, links, CSS3 selectors, a semantic layout, a form, a table and media. Work through the tasks in order; the finished starter files are provided for checking.

## 🎯 Learning Objectives

- Plan a small multi-page website and its folder structure
- Write valid, semantic HTML5 pages
- Style several pages with one external stylesheet
- Build a responsive navigation bar and layout with Flexbox and a media query
- Combine a form, a table and media on real pages
- Check pages with the W3C validator and browser DevTools

## 📖 Concepts Explained

### 1. Plan before you build

```
cybersafe-site/
├── index.html      (home: intro, tips list, video)
├── report.html     (incident report form)
├── stats.html      (table of awareness stats)
├── css/
│   └── site.css    (one stylesheet for all pages)
└── images/
```

Same header, nav and footer on every page gives users a consistent experience.

### 2. Responsive design with a media query

```css
@media (max-width: 700px) {
  .container { flex-direction: column; }   /* stack columns on phones */
}
```

A **media query** applies CSS only when a condition is true, such as a narrow screen. Test it in DevTools with the device toolbar (Ctrl + Shift + M).

### 3. A quality checklist

| Check | How |
|---|---|
| Valid HTML | [W3C Markup Validator](https://validator.w3.org/) |
| Valid CSS | [W3C CSS Validator](https://jigsaw.w3.org/css-validator/) |
| Links work | click every link; no 404 in DevTools Network tab |
| Images have `alt` | screen readers need it |
| Mobile view | DevTools device toolbar |
| Forms use labels | every input has a `<label>` |
| External links safe | `rel="noopener noreferrer"` with `target="_blank"` |

### 4. Common mistakes

| Mistake | Fix |
|---|---|
| Stylesheet not loading | check the `href` path (`css/site.css`) and spelling |
| Styles ignored | a more specific selector wins; check in DevTools → Styles |
| Image broken | wrong path or file name case (`Logo.png` vs `logo.png` matters on Linux servers) |
| Layout breaks on phone | missing viewport meta tag |

## 💻 Code Examples

### Starter page (`cybersafe-site/index.html`)

```html
<header>
  <h1>CyberSafe Karachi</h1>
  <nav>
    <a href="index.html" class="active">Home</a>
    <a href="report.html">Report</a>
    <a href="stats.html">Stats</a>
  </nav>
</header>
<div class="container">
  <main>
    <h2>Five habits that stop most attacks</h2>
    <ol>
      <li>Use a <strong>password manager</strong></li>
      <li>Turn on <mark>two-factor authentication</mark></li>
      <li>Update your phone and PC</li>
      <li>Hover before you click</li>
      <li>Back up important files</li>
    </ol>
  </main>
  <aside>
    <h3>Official help</h3>
    <a href="https://pkcert.gov.pk/" target="_blank" rel="noopener noreferrer">PKCERT</a>
  </aside>
</div>
```

**How it works:** a shared header with a nav, then a Flexbox container with main content and a sidebar. All styling comes from `css/site.css`.

### Shared stylesheet (`cybersafe-site/css/site.css`)

Uses a group selector for header/footer, a descendant selector for nav links, a class for the active link, striped table rows with `:nth-child`, form styling with `:focus` and `:invalid`, and a media query for phones. See the file.

The other pages (`report.html`, `stats.html`) are in the same folder.

## 🧪 Lab Practice

1. **Structure:** create the folder tree above and the three pages with identical header, nav and footer.
2. **Home page:** add an intro paragraph, the five-habits list, an anchor link to a "Learn more" section, and a short video or audio clip with a fallback.
3. **Report page:** build a form with name, email, phone (`tel` with a `pattern`), incident type (`select`), date, description (`textarea`) and a consent checkbox, all with labels.
4. **Stats page:** build a table "Reported incidents by type" with caption, `thead`, `tbody`, `tfoot` total row, and one merged cell.
5. **Polish:** make the layout stack on screens under 700 px, validate all pages, and fix every error.

## 📝 Assignment

Extend the site with a fourth page `glossary.html` containing a description list of 15 terms with A-Z anchor navigation. Add a "current page" style to the nav on every page. Submit the zipped folder and screenshots of the W3C validator results for all four pages.

## ❓ Quick Quiz

1. What does a media query do?
2. Which keyboard shortcut opens the DevTools device toolbar in Chrome/Edge?
3. Why should every image have an `alt` attribute?
4. A stylesheet is not applied. Name two things to check.
5. Why keep the same nav on every page?

<details>
<summary>Show answers</summary>

1. Applies CSS rules only when a condition, such as screen width, is true.
2. Ctrl + Shift + M (with DevTools open)
3. Screen readers read it to blind users and it shows if the image fails to load.
4. The `href` path and file name spelling/case; also selector specificity in DevTools.
5. Consistency: users always know where they are and how to move around.

</details>

## 💼 Interview Questions

**1. What is responsive web design?**

> Designing pages that adapt to any screen size using flexible layouts (Flexbox/Grid), relative units and media queries.

**2. How do you debug CSS that is not working?**

> Inspect the element in DevTools, look at which rules apply or are crossed out, check specificity and file loading in the Network tab.

**3. Why validate HTML?**

> Valid markup behaves consistently across browsers, is more accessible, and avoids hidden layout bugs.

## ✅ Summary

- Plan a folder structure and reuse one stylesheet across pages.
- Combine semantic layout, lists, links, forms, tables and media in a real site.
- Use Flexbox plus a media query for a responsive layout.
- Validate and test in DevTools before calling a page finished.

---

[⬅ Previous](../Session-04-Tables-Audio-and-Video/README.md) · [🏠 Module Home](../README.md) · [Next ➡](../Session-06-JavaScript-Basics/README.md)

Prepared by Zeeshan Abbas · Aptech Learning North Nazimabad
