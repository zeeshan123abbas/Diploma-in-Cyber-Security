// Run with: node es2022_class.js
class Account {
  static maxAttempts;               // static field
  static {                          // static initialisation block (ES2022)
    Account.maxAttempts = 3;
  }

  #password;                        // private field
  #failed = 0;

  constructor(user, password) {
    this.user = user;
    this.#password = password;
  }

  #matches(attempt) {               // private method (ES2022)
    return attempt === this.#password;
  }

  login(attempt) {
    if (this.#failed >= Account.maxAttempts) return "Locked";
    if (this.#matches(attempt)) { this.#failed = 0; return "Welcome"; }
    this.#failed++;
    return `Wrong password (${this.#failed}/${Account.maxAttempts})`;
  }
}

const acc = new Account("ali", "S3cure!pass");
console.log(acc.login("guess1"));
console.log(acc.login("S3cure!pass"));
// console.log(acc.#password);     // SyntaxError: private field
