function solution(s) {
  var answer = "";
  let even = true;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === " ") {
      answer += " ";
      even = true;
    } else if (even) {
      if (s.charCodeAt([i]) > 96) {
        answer += `${String.fromCharCode(s.charCodeAt([i]) - 32)}`;
      } else {
        answer += `${s[i]}`;
      }
      even = false;
    } else {
      if (s.charCodeAt([i]) < 91) {
        answer += `${String.fromCharCode(s.charCodeAt([i]) + 32)}`;
      } else {
        answer += `${s[i]}`;
      }
      even = true;
    }
  }
  return answer;
}

const data = "try hello world";

console.log(solution(data));
