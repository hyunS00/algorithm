function solution(strings, n) {
  var answer = [];
  let askiArr = [];
  let i, j;
  let min;
  strings.forEach((e) => {
    askiArr.push(e.charCodeAt([n]));
  });
  for (i = 0; i < askiArr.length; i++) {
    min = 123;
    for (j = 0; j < askiArr.length; j++) {
      if (min > askiArr[j]) {
        min = askiArr[j];
      }
    }
    answer.push(strings[askiArr.indexOf(min)]);
    askiArr[askiArr.indexOf(min)] = 123;
  }
  return answer;
}

const data = [
  { strings: ["sun", "bed", "car"], n: 1 },
  { strings: ["abce", "abcd", "cdx"], n: 2 },
];

data.forEach((e) => {
  console.log(solution(e.strings, e.n));
});
