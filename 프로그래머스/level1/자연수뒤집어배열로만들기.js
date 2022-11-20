function solution(n) {
  var answer = [];
  for (; n; ) {
    answer.push(n % 10 | 0);
    n = Math.floor(n / 10);
  }
  return answer;
}

const data = 12345;

console.log(solution(data));
