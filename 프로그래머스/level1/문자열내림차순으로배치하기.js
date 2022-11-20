function solution(s) {
  var answer = "";
  let askiArr = [];
  let i;
  for (i = 0; i < s.length; i++) {
    askiArr.push(s.charCodeAt([i]));
  }
  askiArr.sort((a, b) => b - a);
  for (i = 0; i < s.length; i++) {
    answer += `${String.fromCharCode(askiArr[i])}`;
  }
  return answer;
}

const data = "Zbcdefg";

console.log(solution(data));
