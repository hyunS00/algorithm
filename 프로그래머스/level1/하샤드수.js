function solution(x) {
  var answer = true;
  let sum = 0;
  let num = x;
  while (num > 0) {
    sum += num % 10;
    num = Math.floor(num / 10);
    console.log(sum, num);
  }
  if (x % sum != 0) {
    answer = false;
  }
  return answer;
}

const data = [10, 12, 11, 13, 456];

data.forEach((e) => {
  console.log(solution(e));
});
