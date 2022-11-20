function solution(a, b) {
  var answer = 0;
  let max, min;
  if (a >= b) {
    max = a;
    min = b;
  } else {
    max = b;
    min = a;
  }
  for (let i = min; i <= max; i++) {
    answer += i;
  }
  return answer;
}

const data = [
  { a: 3, b: 5 },
  { a: 3, b: 3 },
  { a: 5, b: 3 },
];

data.forEach((e) => {
  console.log(solution(e.a, e.b));
});
