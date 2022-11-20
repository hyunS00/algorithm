function solution(nums) {
  let poncketmon = [];
  nums.forEach((element) => {
    if (!poncketmon.includes(element)) {
      poncketmon.push(element);
    }
  });
  console.log(poncketmon);
  var answer;
  if (nums.length / 2 > poncketmon.length) {
    answer = poncketmon.length;
  } else {
    answer = nums.length / 2;
  }

  return answer;
}

data = [
  [3, 1, 2, 3],
  [3, 3, 3, 2, 2, 4],
  [3, 3, 3, 2, 2, 2],
];

for (let i = 0; i < data.length; i++) {
  console.log(solution(data[i]));
}
