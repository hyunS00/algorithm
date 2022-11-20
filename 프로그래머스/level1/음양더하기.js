function solution(absolutes, signs) {
  let answer = 0;
  let count = 0;
  absolutes.forEach((e) => {
    if (signs[count]) {
      answer += e;
    } else {
      answer -= e;
    }
    count++;
  });
  return answer;
}

const data = [
  { absolutes: [4, 7, 12], signs: [true, false, true] },
  { absolutes: [1, 2, 3], signs: [false, false, true] },
];

data.forEach((e) => {
  console.log(solution(e.absolutes, e.signs));
});
