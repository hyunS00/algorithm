function solution(num) {
  var answer = 0;
  let count = 0;
  while (num != 1) {
    if (num % 2 === 0) {
      num /= 2;
    } else {
      num = num * 3 + 1;
    }
    count++;
    if (count >= 500) {
      answer = -1;
      return answer;
    }
  }
  answer = count;
  return answer;
}

const data = [6, 16, 626331];

data.forEach((e) => {
  console.log(solution(e));
});
