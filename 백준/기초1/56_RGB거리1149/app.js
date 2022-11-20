const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let answer = 0;

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = input.splice(0, 1);
  let testCase = [];
  input.forEach((e, i) => {
    input[i] = e.split(" ");
  });
  input.forEach((element) => {
    testCase.push(element.map((e) => Number(e)));
  });
  for (let i = 1; i < N; i++) {
    testCase[i][0] = Math.min(
      testCase[i][0] + testCase[i - 1][1],
      testCase[i][0] + testCase[i - 1][2]
    );
    testCase[i][1] = Math.min(
      testCase[i][1] + testCase[i - 1][0],
      testCase[i][1] + testCase[i - 1][2]
    );
    testCase[i][2] = Math.min(
      testCase[i][2] + testCase[i - 1][0],
      testCase[i][2] + testCase[i - 1][1]
    );
  }
  console.log(
    Math.min(testCase[N - 1][0], testCase[N - 1][1], testCase[N - 1][2])
  );
});
