let component = ReasonReact.statelessComponent("QuestionPosition");

let getPositionInQuiz = (currentQuestion: int, quiz: Shared.quiz) =>
  (string_of_int(currentQuestion + 1), List.length(quiz))
  |> (((current, total)) => {j|$current/$total|j});

let make = (~quiz: Shared.quiz, ~currentQuestion: int, _children) => {
  ...component,
  render: _self =>
    <p> (getPositionInQuiz(currentQuestion, quiz) |> ReasonReact.string) </p>,
};