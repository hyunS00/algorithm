function solution(numbers, target) {
  var answer = 0;
  let tree = [, 0];
  let i, j;
  let branch = 0;
  let pow = Math.pow(2, numbers.length + 1); //Math.pow() 2를 numbers.length+1만큼제곱
  let cnt = 0;
  //2진트리를 배열 형식으로 만들어줌
  //tree     0
  //       1  -1
  //      1-1 1 -1
  for (i = 2; i < pow; i *= 2) {
    for (j = 0; j < i; j += 2) {
      tree[i + j] = numbers[branch];
      tree[i + j + 1] = -numbers[branch];
    }
    branch++;
  }
  pow = Math.pow(2, numbers.length);
  //dfs
  function sumNumbers(hear, tree, sum) {
    sum += tree[hear];
    if (hear >= pow) {
      if (sum === target) {
        cnt++;
      }
      return;
    }

    if (tree[hear * 2]) sumNumbers(hear * 2, tree, sum);
    if (tree[hear * 2 + 1]) sumNumbers(hear * 2 + 1, tree, sum);
  }

  sumNumbers(1, tree, 0);
  answer = cnt;
  return answer;
}

const data = [{ numbers: [1, 1, 1, 1, 1], target: 3 }];

data.forEach((e) => {
  console.log(solution(e.numbers, e.target));
});
