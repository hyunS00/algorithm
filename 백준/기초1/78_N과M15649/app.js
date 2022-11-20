const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let answer = "";
let visited = Array(9).fill(false);
let arr = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  input = input[0].split(" ");
  const N = input[0] * 1;
  const M = input[1] * 1;

  recursive(0, N, M);
  console.log(answer);
});

function recursive(count, N, M) {
  if (count === M) {
    answer += `${arr.join(" ")}\n`;
    return;
  }
  for (let i = 1; i <= N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      arr[count] = i;
      recursive(count + 1, N, M);
      visited[i] = false;
    }
  }
}
