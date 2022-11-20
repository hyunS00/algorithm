function solution(n) {
  var answer = 0;
  let numArr = [];
  for (; n; ) {
    numArr.push(n % 10 | 0);
    n = (n / 10) | 0;
  }
  numArr.sort((a, b) => b - a);
  answer = parseInt(numArr.join(""));
  return answer;
}

const data = 118372;

console.log(solution(data));
