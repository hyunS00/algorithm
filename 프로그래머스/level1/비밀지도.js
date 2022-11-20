function solution(n, arr1, arr2) {
  let binaryArr = [];
  let stringArr = [];
  let outputArr = [];
  var answer = [];
  let i, j, arrLength;
  for (i = 0; i < n; i++) {
    //논리연산자한걸2진수문자열로만듦
    binaryArr[i] = (arr1[i] | arr2[i]).toString(2);
    arrLength = binaryArr[i].length;
    if (arrLength < n) {
      for (j = 0; j < n - arrLength; j++) {
        binaryArr[i] = ` ${binaryArr[i]}`;
      }
    }
    for (j = 0; j < n; j++) {
      if (binaryArr[i][j] === "1") {
        stringArr.push("#");
      } else {
        stringArr.push(" ");
      }
    }
    //배열을 한배열로 만든것
    outputArr.push(stringArr.join(""));
    //제이슨인데 막 이해할필요는언
    answer = JSON.stringify(outputArr);
    answer = JSON.parse(answer);
    stringArr = [];
  }
  return answer;
}

const data = [
  { n: 5, arr1: [9, 20, 28, 18, 11], arr2: [30, 1, 21, 17, 28] },
  { n: 6, arr1: [46, 33, 33, 22, 31, 50], arr2: [27, 56, 19, 14, 14, 10] },
];

data.forEach((element) => {
  console.log(solution(element.n, element.arr1, element.arr2));
});
