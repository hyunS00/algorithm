function solution(progresses, speeds) {
  let progress;
  let day = 1;
  let count = 0;
  var answer = [];
  while (progresses[0]) {
    progress = progresses[0] + speeds[0] * day;
    if (progress >= 100) {
      progresses.shift();
      speeds.shift();
      count++;
    } else {
      if (count > 0) {
        answer.push(count);
      }
      day++;
      count = 0;
    }
  }
  answer.push(count);
  return answer;
}

const data = [
  { progresses: [93, 30, 55], speeds: [1, 30, 5] },
  { progresses: [95, 90, 99, 99, 80, 99], speeds: [1, 1, 1, 1, 1, 1] },
];

data.forEach((e) => {
  console.log(solution(e.progresses, e.speeds));
});
