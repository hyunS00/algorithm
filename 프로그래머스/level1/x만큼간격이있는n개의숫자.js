function solution(x, n) {
  var answer = [];
  for (i = 0; i < n; i++) {
    answer[i] = x * (i + 1);
  }
  return answer;
}

const data = [
  { x: 2, n: 5 },
  { x: 4, n: 3 },
  { x: -4, n: 2 },
];

data.forEach((e) => {
  console.log(solution(e.x, e.n));
});
