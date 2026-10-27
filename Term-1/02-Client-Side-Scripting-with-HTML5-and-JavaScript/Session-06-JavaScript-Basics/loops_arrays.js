// Run with Node.js:  node loops_arrays.js   (or paste into the browser Console)
const openPorts = [22, 80, 443, 3306];

for (let i = 0; i < openPorts.length; i++) {
  if (openPorts[i] === 3306) {
    console.log("3306 (MySQL) should not be public!");
    continue;                       // skip the normal message
  }
  console.log("Port", openPorts[i]);
}

for (const port of openPorts) console.log("of ->", port);   // values
for (const index in openPorts) console.log("in ->", index); // keys "0".."3"

// while and do...while
let attempts = 0;
while (attempts < 3) { attempts++; }
console.log("attempts:", attempts);

let n = 10;
do { n--; } while (n > 100);        // runs once even though condition is false
console.log("n:", n);

// two-dimensional array: rows of [name, status]
const lab = [["PC1", "on"], ["PC2", "off"]];
for (const row of lab) console.log(row[0], "is", row[1]);
