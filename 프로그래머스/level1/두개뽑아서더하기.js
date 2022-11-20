function solution(numbers) {
  let i, j;
  let combination = [];
  for (i = 0; i < numbers.length - 1; i++) {
    for (j = i + 1; j < numbers.length; j++) {
      if (!combination.includes(numbers[i] + numbers[j]))
        //안에 중복되는 값 없으면 푸시
        combination.push(numbers[i] + numbers[j]);
    }
  }
  combination.sort((a, b) => a - b); //오름차순 정렬
  var answer = combination;
  return answer;
}

const data = [
  [2, 1, 3, 4, 1],
  [5, 0, 2, 7],
];
data.forEach((e) => {
  console.log(solution(e));
});
