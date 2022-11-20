function solution(arr1, arr2) {
  var answer = Array(arr1.length)
    .fill(null)
    .map(() => Array());
  let i, j;
  for (i = 0; i < arr1.length; i++) {
    for (j = 0; j < arr1[i].length; j++) {
      answer[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  return answer;
}

const data = [
  {
    arr1: [
      [1, 2],
      [2, 3],
    ],
    arr2: [
      [3, 4],
      [5, 6],
    ],
  },
  // { arr1: [[1], [2]], arr2: [[3], [4]] },
];

data.forEach((e) => {
  console.log(solution(e.arr1, e.arr2));
});
