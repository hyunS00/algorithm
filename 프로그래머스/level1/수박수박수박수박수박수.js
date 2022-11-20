function solution(n) {
  var answer = "";
  let isSoo = true;
  for (let i = 0; i < n; i++) {
    if (isSoo) {
      answer += "수";
      isSoo = false;
    } else {
      answer += "박";
      isSoo = true;
    }
  }
  return answer;
}

const data = [3, 4];

data.forEach((e) => {
  console.log(solution(e));
});
