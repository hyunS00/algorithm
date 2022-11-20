function solution(n) {
  var answer = 0;
  if (Number.isInteger(Math.sqrt(n))) {
    answer = (Math.sqrt(n) + 1) * (Math.sqrt(n) + 1);
  } else {
    answer = -1;
  }
  return answer;
}

const data = [121, 3];

data.forEach((e) => {
  console.log(solution(e));
});
