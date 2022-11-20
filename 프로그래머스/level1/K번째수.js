function solution(array, commands) {
  let spliceArr;
  const answer = [];
  commands.forEach((arr) => {
    spliceArr = array.slice(arr[0] - 1, arr[1]);
    spliceArr.sort((a, b) => a - b);
    answer.push(spliceArr[arr[2] - 1]);
  });

  return answer;
}

data = {
  array: [1, 5, 2, 6, 3, 7, 4],
  commands: [
    [2, 5, 3],
    [4, 4, 1],
    [1, 7, 3],
  ],
};

console.log(solution(data.array, data.commands));
