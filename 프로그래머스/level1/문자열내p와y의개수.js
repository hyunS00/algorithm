function solution(s) {
  var answer = true;
  let pCount = 0;
  let yCount = 0;
  for (let i = 0; i < s.length; i++) {
    if (s.charCodeAt([i]) === 80 || s.charCodeAt([i]) === 112) {
      pCount++;
    } else if (s.charCodeAt([i]) === 89 || s.charCodeAt([i]) === 121) {
      yCount++;
    }
  }
  if (pCount !== yCount) answer = false;
  return answer;
}

const data = ["pPoooyY", "Pyy"];

data.forEach((e) => {
  console.log(solution(e));
});
