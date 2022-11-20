function solution(s) {
  var answer = true;
  if (s.length !== 4 && s.length !== 6) {
    answer = false;
    return answer;
  }
  for (let i = 0; i < s.length; i++) {
    if (s.charCodeAt([i]) >= 65) {
      answer = false;
      break;
    }
  }
  return answer;
}

const data = ["a234", "1234"];

data.forEach((e) => {
  console.log(solution(e));
});
