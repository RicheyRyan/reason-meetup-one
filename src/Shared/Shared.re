type answer = {text: string};

type question = {
  text: string,
  options: list(answer),
  correctAnswer: option(answer),
};

type quiz = list(question);

type result = {
  numCorrect: int,
  totalQuestions: int,
};
