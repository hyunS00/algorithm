function solution(s, n) {
  var answer = "";
  let askiNum;
  for (let i = 0; i < s.length; i++) {
    askiNum = s.charCodeAt([i]);
    if (askiNum === 32) {
      answer += "";
    } else if (askiNum <= 90) {
      if (askiNum + n > 90) {
        askiNum = askiNum + n - 26;
      } else {
        askiNum = askiNum + n;
      }
    } else {
      if (askiNum + n > 122) {
        askiNum = askiNum + n - 26;
      } else {
        askiNum = askiNum + n;
      }
    }
    answer += String.fromCharCode(askiNum);
  }
  return answer;
}

const data = [
  { s: "AB", n: 1 },
  { s: "z", n: 1 },
  { s: "a B z", n: 4 },
  { s: "     ", n: 10 },
];

data.forEach((e) => {
  console.log(solution(e.s, e.n));
});
