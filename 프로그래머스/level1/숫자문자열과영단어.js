function solution(s) {
  let stringNum = [];
  let resultNum = [];
  for (let i = 0; i < s.length; i++) {
    if (s[i].charCodeAt([0]) < 97) {
      resultNum.push(parseInt(s[i]));
    } else {
      stringNum.push(s[i]);
      stringNum = [stringNum.join("")];
      switch (stringNum[0]) {
        case "zero":
          resultNum.push(0);
          stringNum = [];
          break;
        case "one":
          resultNum.push(1);
          stringNum = [];
          break;
        case "two":
          resultNum.push(2);
          stringNum = [];
          break;
        case "three":
          resultNum.push(3);
          stringNum = [];
          break;
        case "four":
          resultNum.push(4);
          stringNum = [];
          break;
        case "five":
          resultNum.push(5);
          stringNum = [];
          break;
        case "six":
          resultNum.push(6);
          stringNum = [];
          break;
        case "seven":
          resultNum.push(7);
          stringNum = [];
          break;
        case "eight":
          resultNum.push(8);
          stringNum = [];
          break;
        case "nine":
          resultNum.push(9);
          stringNum = [];
          break;
      }
    }
  }

  var answer = resultNum.join("");
  return answer;
}

const data = ["one4seveneight", "23four5six7", "2three45sixseven", "123"];

for (let i = 0; i < data.length; i++) {
  console.log(solution(data[i]));
}
