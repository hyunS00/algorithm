function solution(arr, divisor) {
  let count = 0;
  let answer = [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] % divisor === 0) {
      answer.push(arr[i]);
      count++;
    }
  }
  if (count === 0) {
    answer.push(-1);
  }
  answer.sort((a, b) => a - b);
  return answer;
}

const data = [
  { arr: [5, 9, 7, 10], divisor: 5 },
  { arr: [2, 36, 1, 3], divisor: 1 },
  { arr: [3, 2, 6], divisor: 10 },
];

data.forEach((e) => {
  console.log(solution(e.arr, e.divisor));
});
