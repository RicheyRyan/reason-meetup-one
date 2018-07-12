let returnQuiz = () => Encoder.quiz(Questions.quiz);

let isAnswerCorrect = ((first, second)) => first == second;

let getCorrectAnswers = () =>
  Belt.List.map(Questions.quiz, (q: Shared.question) =>
    switch (q.correctAnswer) {
    | Some(answer) => answer
    | None => failwith("Answers are missing!")
    }
  );

let getNumCorrectAnswers =
    (correctAnswers: list(Shared.answer), answers: list(Shared.answer))
    : int =>
  Belt.List.zip(correctAnswers, answers)
  |> (
    combined =>
      Belt.List.reduce(combined, 0, (correct, answers) =>
        isAnswerCorrect(answers) ? correct + 1 : correct
      )
  );

let calculateScore = answers : Shared.result => {
  let correctAnswers = getCorrectAnswers();
  let numCorrect = getNumCorrectAnswers(correctAnswers, answers);
  {totalQuestions: List.length(Questions.quiz), numCorrect};
};