function solution(d, budget) {
  let count = 0;
  d.sort((a, b) => a - b);

  for (let i = 0; budget >= d[i]; i++) {
    budget -= d[i];
    count++;
  }
  var answer = count;
  return answer;
}

const data = [
  { d: [1, 3, 2, 5, 4], budget: 9 },
  { d: [2, 2, 3, 3], budget: 10 },
];

data.forEach((e) => {
  console.log(solution(e.d, e.budget));
});
