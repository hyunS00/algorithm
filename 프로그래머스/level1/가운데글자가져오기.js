function solution(s) {
  var answer = "";
  if (s.length % 2 === 0) {
    answer = `${s[s.length / 2 - 1]}${s[s.length / 2]}`;
  } else {
    answer = `${s[Math.round(s.length / 2) - 1]}`;
  }

  return answer;
}

const data = ["abcde", "qwer"];

data.forEach((e) => {
  console.log(solution(e));
});
