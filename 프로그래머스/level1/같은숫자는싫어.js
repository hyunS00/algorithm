function solution(arr) {
  var answer = [];
  arr.forEach((e, i) => {
    if (e !== arr[i + 1]) {
      answer.push(e);
    }
  });

  return answer;
}

const data = [
  [1, 1, 3, 3, 0, 1, 1],
  [4, 4, 4, 3, 3],
];

data.forEach((e) => {
  console.log(solution(e));
});
