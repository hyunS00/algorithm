const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
//위에 무시하셈

let input = [];
//한줄한줄 입력받아 input배열에 push
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  //여기서 실행
  const N = Number(input[0]);
  //split으로input[1] 공백을 기준으로 잘라 A문자 배열을 만듦
  let A = input[1].split(" ");
  let answer = "";
  //map mapping하는 함수 문자열"1"을 숫자 1로 매핑하여 B배열을 만듬ㄹ
  let B = A.map((v) => Number(v));
  //이게 스택
  let stackArr = [];
  //루프를 돌지 말지
  let roopAble = true;
  for (let i = N - 1; i >= 0; i--) {
    // 스택이비교하려는 값보다 크면 팝 무한반복
    while (roopAble) {
      //스택보다 비교하려는 값이 크면 팝
      if (B[i] >= stackArr[stackArr.length - 1]) {
        stackArr.pop();
        //스택이 크면 출력하고 더이상 루프 돌지 않기
      } else if (B[i] < stackArr[stackArr.length - 1]) {
        answer = `${stackArr[stackArr.length - 1]} ${answer}`;
        roopAble = false;
        //스택이 비어있으면 -1을 출력하고 루프돌지 않기
      } else if (stackArr[0] === undefined) {
        answer = `${-1} ${answer}`;
        roopAble = false;
      }
    }
    //다시 루프 초기화
    roopAble = true;
    //출력하고 푸시
    stackArr.push(B[i]);
  }

  console.log(answer);
});
