const keyPad = {
  1: [0, 0],
  2: [0, 1],
  3: [0, 2],
  4: [1, 0],
  5: [1, 1],
  6: [1, 2],
  7: [2, 0],
  8: [2, 1],
  9: [2, 2],
  "*": [3, 0],
  0: [3, 1],
  "#": [3, 2],
};

const getDistance = (numPosition, handposition) => {
  return (
    Math.abs(numPosition[0] - handposition[0]) +
    Math.abs(numPosition[1] - handposition[1])
  );
};

function solution(numbers, hand) {
  let result = [];
  let leftHand = "*";
  let rightHand = "#";
  let num;
  for (let i = 0; i < numbers.length; i++) {
    num = numbers[i];
    keyPad[num];
    if (keyPad[num][1] === 0) {
      leftHand = num;
      result.push("L");
    } else if (keyPad[num][1] === 2) {
      rightHand = num;
      result.push("R");
    } else if (
      getDistance(keyPad[num], keyPad[leftHand]) <
      getDistance(keyPad[num], keyPad[rightHand])
    ) {
      leftHand = num;
      result.push("L");
    } else if (
      getDistance(keyPad[num], keyPad[leftHand]) >
      getDistance(keyPad[num], keyPad[rightHand])
    ) {
      rightHand = num;
      result.push("R");
    } else if (hand === "right") {
      rightHand = num;
      result.push("R");
    } else {
      leftHand = num;
      result.push("L");
    }
    console.log(num);
  }
  var answer = result.join("");
  return answer;
}

data = [
  { numbers: [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], hand: "right" },
  { numbers: [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], hand: "left" },
  { numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 0], hand: "right" },
];

for (let i = 0; i < data.length; i++) {
  console.log(solution(data[i].numbers, data[i].hand));
}
