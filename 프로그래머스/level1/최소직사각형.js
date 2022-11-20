function solution(sizes) {
  let width = 0;
  let height = 0;
  let arrWidth, arrHeight;
  for (let i = 0; i < sizes.length; i++) {
    if (sizes[i][0] >= sizes[i][1]) {
      if (sizes[i][0] >= width) {
        width = sizes[i][0];
      }
      sizes[i][0] = 0;
    } else {
      if (sizes[i][1] >= width) {
        width = sizes[i][1];
      }
      sizes[i][1] = 0;
    }

    if (sizes[i][0] >= sizes[i][1]) {
      if (sizes[i][0] >= height) {
        height = sizes[i][0];
      }
      sizes[i][0] = 0;
    } else {
      if (sizes[i][1] >= height) {
        height = sizes[i][1];
      }
      sizes[i][1] = 0;
    }
  }
  let answer = height * width;
  return answer;
}

const data = [
  [
    [60, 50],
    [30, 70],
    [60, 30],
    [80, 40],
  ],
  [
    [10, 7],
    [12, 3],
    [8, 15],
    [14, 7],
    [5, 15],
  ],
  [
    [14, 4],
    [19, 6],
    [6, 16],
    [18, 7],
    [7, 11],
  ],
];

data.forEach((element) => {
  console.log(solution(element));
});
