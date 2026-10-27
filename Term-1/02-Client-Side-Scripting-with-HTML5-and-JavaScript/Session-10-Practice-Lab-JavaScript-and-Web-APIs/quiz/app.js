// ----- state -----
let questions = [];
let current = 0;
let score = 0;

// ----- load data -----
async function loadQuestions() {
  try {
    const response = await fetch("questions.json");
    questions = await response.json();
    showBest();
    renderQuestion();
  } catch (err) {
    document.querySelector("#question").textContent = "Could not load questions (use Live Server).";
    console.error(err);
  }
}

// ----- view: one question -----
function renderQuestion() {
  const q = questions[current];
  document.querySelector("#question").textContent = `${current + 1}. ${q.text}`;
  const box = document.querySelector("#options");
  box.replaceChildren();                       // remove old buttons
  q.options.forEach((option, index) => {
    const btn = document.createElement("button");
    btn.textContent = option;                  // safe text, never innerHTML
    btn.addEventListener("click", () => checkAnswer(index));
    box.append(btn);
  });
}

// ----- logic -----
function checkAnswer(index) {
  if (index === questions[current].answer) score++;
  current++;
  if (current < questions.length) renderQuestion();
  else showResult();
}

function showResult() {
  document.querySelector("#question").textContent = "Finished!";
  document.querySelector("#options").replaceChildren();
  document.querySelector("#result").hidden = false;
  document.querySelector("#scoreText").textContent = `Score: ${score} / ${questions.length}`;

  const best = Number(localStorage.getItem("bestScore") ?? 0);
  if (score > best) localStorage.setItem("bestScore", score);   // keep best score
  showBest();
  drawChart(score, questions.length - score);
}

function showBest() {
  const best = localStorage.getItem("bestScore");
  document.querySelector("#best").textContent = best ? `Best score so far: ${best}` : "";
}

// ----- canvas bar chart -----
function drawChart(correct, wrong) {
  const ctx = document.querySelector("#chart").getContext("2d");
  const max = Math.max(correct, wrong, 1);
  ctx.clearRect(0, 0, 300, 180);

  ctx.fillStyle = "#27ae60";                                  // correct bar
  ctx.fillRect(50, 150 - (correct / max) * 120, 70, (correct / max) * 120);
  ctx.fillStyle = "#c0392b";                                  // wrong bar
  ctx.fillRect(180, 150 - (wrong / max) * 120, 70, (wrong / max) * 120);

  ctx.fillStyle = "#000";
  ctx.font = "14px Arial";
  ctx.fillText(`Correct (${correct})`, 40, 170);
  ctx.fillText(`Wrong (${wrong})`, 175, 170);
}

document.querySelector("#restart").addEventListener("click", () => {
  current = 0;
  score = 0;
  document.querySelector("#result").hidden = true;
  renderQuestion();
});

loadQuestions();
