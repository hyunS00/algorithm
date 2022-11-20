function solution(n, m) {
  let min = 1;
  let tmp;
  let max;
  if (n > m) {
    tmp = n;
    n = m;
    m = tmp;
  }

  for (let i = n; i >= 1; i--) {
    if (n % i === 0 && m % i === 0) {
      if (!max) {
        max = i;
      }
      min *= i;
      n /= i;
      m /= i;
    }
  }
  min *= n * m;
  var answer = [max, min];
  return answer;
}

const data = [
  { n: 3, m: 12 },
  { n: 2, m: 5 },
  { n: 40, m: 16 },
];

data.forEach((e) => {
  console.log(solution(e.n, e.m));
});
