function solution(n) {
  let triad = "";
  let num = n;
  let answer = 0;
  while (num > 0) {
    triad += `${num % 3}`; //나머지 담고
    num = Math.floor(num / 3); //3나눠서 계산
  }
  let size = triad.length - 1;
  let tenNum = 0;
  let powerNum;
  for (let i = 0; i <= size; i++) {
    tenNum = parseInt(triad[size - i]);
    powerNum = Math.pow(3, i);
    answer += tenNum * powerNum;
  }

  return answer;
}

const data = [45, 125];

data.forEach((e) => {
  console.log(solution(e));
});
