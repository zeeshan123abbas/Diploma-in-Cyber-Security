// Run with: node functions_objects.js
function isWellKnown(port) {                 // parameter
  return port >= 0 && port <= 1023;          // return value
}

// arrow function that uses another function
const toLabel = port => `${port}${isWellKnown(port) ? " (well-known)" : ""}`;

const host = {
  name: "lab-vm",
  ports: [22, 8080, 443],
  report() { return this.ports.map(toLabel).join(", "); }   // method
};

console.log(host.name, "->", host.report());
console.log("Last port:", host.ports.at(-1));                 // ES2022
console.log("Has name?", Object.hasOwn(host, "name"));        // ES2022
