function solution(n) {
  var answer = 0;
  let i, j;
  let count = 0;
  let prime = Array(n + 1)
    .fill()
    .map((e, i) => 0);
  for (i = 2; i < Math.sqrt(n + 1); i++) {
    for (j = 2; j * i < n + 1; j++) {
      prime[i * j]++;
    }
  }
  for (i = 1; i < n; i++) {
    if (prime[i] == 0) {
      answer++;
    }
  }
  return answer;
}

const data = [10, 5];

data.forEach((e) => {
  console.log(solution(e));
});
