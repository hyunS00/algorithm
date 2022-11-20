function solution(nums) {
  var answer = -1;
  nums.sort((a, b) => a - b);
  const sum =
    nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3];
  let i, j, k;
  let arrLength = nums.length;
  let count = 0;
  let primeNum = Array(parseInt(sum) + 2)
    .fill()
    .map((e, i) => 0);
  for (i = 2; i < sum; i++) {
    for (j = 2; j * i < sum + 2; j++) {
      primeNum[j * i]++;
    }
  }
  for (i = 0; i < arrLength - 2; i++) {
    for (j = i + 1; j < arrLength - 1; j++) {
      for (k = j + 1; k < arrLength; k++) {
        if (!primeNum[nums[i] + nums[j] + nums[k]]) count++;
      }
    }
  }
  answer = count;
  return answer;
}

const data = [
  [1, 2, 3, 4],
  [1, 2, 7, 6, 4],
];

data.forEach((e) => {
  console.log(solution(e));
});
