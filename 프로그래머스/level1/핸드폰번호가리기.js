function solution(phone_number) {
  var answer = "";
  const number = phone_number;
  for (let i = 0; i < phone_number.length - 4; i++) {
    answer += "*";
  }
  answer += number.slice(number.length - 4, number.length);
  return answer;
}

const data = ["01033334444", "027778888", "01091027677"];

data.forEach((e) => {
  console.log(solution(e));
});
