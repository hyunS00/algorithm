function solution(board, moves) {
  var answer = 0;
  let buket = [];
  let index;
  let reBoard = [];
  let i, j;
  for (i = 0; i < board.length; i++) {
    for (j = 0; j < board[i].length; j++) {
      reBoard[j][i] = board[i][j];
    }
  }
  moves.forEach((e) => {
    buket.push(reBoard[e - 1].pop());
    index = buket.length - 1;
    console.log(buket);
    while (buket[index] === buket[index - 1]) {
      buket.pop();
      buket.pop();
      answer++;
      index--;
    }
  });
  return answer;
}

const data = [
  {
    board: [
      [0, 0, 0, 0, 0],
      [0, 0, 1, 0, 3],
      [0, 2, 5, 0, 1],
      [4, 2, 4, 4, 2],
      [3, 5, 1, 3, 1],
    ],
    moves: [1, 5, 3, 5, 1, 2, 1, 4],
  },
];

data.forEach((e) => {
  console.log(solution(e.board, e.moves));
});
