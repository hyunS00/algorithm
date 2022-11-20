const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
//위에 무시

let answer = "";
let input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  let N = Number(input[0]);
  //Array함수로 배열을 만들어주고
  //fill함수로 0을 채워 넣음
  let freqArr = Array(1000001).fill(0);
  //input[1]번째 공백을 기준으로 자르고 숫자로매핑
  let A = input[1].split(" ").map((e) => {
    //매핑하는 와중에 freqArr배열에 빈도를 저장
    freqArr[Number(e)]++;
    return Number(e);
  });
  let stackArr = [];
  stackArr.push(A[N - 1]);
  let roopAble;
  for (let i = N - 1; i >= 0; i--) {
    roopAble = true;
    while (roopAble) {
      if (freqArr[A[i]] >= freqArr[stackArr[stackArr.length - 1]]) {
        stackArr.pop();
      } else if (stackArr[0] === undefined) {
        answer = `-1 ${answer}`;
        stackArr.push(A[i]);
        roopAble = false;
      } else if (freqArr[A[i]] < freqArr[stackArr[stackArr.length - 1]]) {
        answer = `${stackArr[stackArr.length - 1]} ${answer}`;
        stackArr.push(A[i]);
        roopAble = false;
      }
    }
  }
  console.log(answer);
});
