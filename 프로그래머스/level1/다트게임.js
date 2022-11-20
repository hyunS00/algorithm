function solution(dartResult) {
  let stageScore = 0;
  let scoreData = [];
  let sumScore = 0;
  for (let i = 0; i < dartResult.length; i++) {
    //아스키코드 영역 확인
    if (dartResult.charCodeAt([i]) >= 65) {
      if (dartResult[i] === "D") {
        stageScore = Math.pow(stageScore, 2);
      } else if (dartResult[i] === "T") {
        stageScore = Math.pow(stageScore, 3);
      }
      if (dartResult.charCodeAt([i + 1]) > 42) {
        scoreData.push(stageScore);
      }
      //아스키코드 점수확인
    } else if (dartResult.charCodeAt([i]) >= 48) {
      if (dartResult[i + 1] === "0") {
        stageScore = parseInt(`${dartResult[i]}${dartResult[i + 1]}`);
        i++;
      } else {
        stageScore = parseInt(dartResult[i]);
      }
      //옵션확인
    } else {
      //-1 확인
      if (dartResult[i] === "#") {
        stageScore *= -1;
        scoreData.push(stageScore);
        //별인데 첫번째이면
      } else if (i === 2) {
        stageScore *= 2;
        scoreData.push(stageScore);
        //별이면
      } else {
        stageScore *= 2;
        scoreData[scoreData.length - 1] *= 2;
        scoreData.push(stageScore);
      }
      if (i === dartResult.length - 1) {
        scoreData.pop();
      }
    }
    console.log(i, stageScore, scoreData);
  }
  scoreData.push(stageScore);
  scoreData.forEach((e) => {
    sumScore += e;
  });
  var answer = sumScore;
  return answer;
}

const data = [
  // "1S2D*3T",
  // "1D2S#10S",
  // "1D2S0T",
  // "1S*2T*3S",
  // "1D#2S*3S",
  "1T2D3D#",
  "1D2S3T*",
];

data.forEach((e) => {
  console.log(solution(e));
});
