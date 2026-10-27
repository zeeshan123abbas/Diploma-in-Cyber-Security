const course = "Cybersecurity";     // string
let sessions = 10;                  // number
const isActive = true;              // boolean

console.log(course, typeof course);
console.log(`Sessions: ${sessions}`);     // template literal
console.log("Active?", isActive);

sessions++;                               // increment
console.log("After ++ :", sessions);

console.log("5" == 5, "5" === 5);         // true false
console.log(parseInt("42px"), Number("42px"));   // 42 NaN
console.log("Line one\nLine two\tTabbed");      // escape sequences

// write into the page safely (text, not HTML)
document.querySelector("#out").textContent = `${course} has ${sessions} sessions`;
