function solution(arr) {
  var answer = [];
  let min = arr[0];
  if (arr.length === 1) {
    answer.push(-1);
    return answer;
  }
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  arr.splice(arr.indexOf(min), 1);
  return (answer = arr);
}

let data = [[4, 3, 2, 1], [10]];

data.forEach((e) => {
  console.log(solution(e));
});
