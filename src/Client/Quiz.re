type actions =
  | AddAnswer(Shared.answer)
  | SubmitAnswers(list(Shared.answer));

type state = {
  answers: list(Shared.answer),
  currentQuestion: int,
};
let component = ReasonReact.reducerComponent("Quiz");

let make = (~quiz: Shared.quiz, ~onSelectAnswers, _children) => {
  ...component,
  initialState: _self => {answers: [], currentQuestion: 0},
  reducer: (action: actions, state: state) =>
    switch (action) {
    | AddAnswer(answer) =>
      let {answers, currentQuestion} = state;
      let nextAnswers = List.append(answers, [answer]);
      if (currentQuestion == List.length(quiz) - 1) {
        ReasonReact.UpdateWithSideEffects(
          {answers: nextAnswers, currentQuestion},
          (self => self.send(SubmitAnswers(nextAnswers))),
        );
      } else {
        ReasonReact.Update({
          answers: nextAnswers,
          currentQuestion: currentQuestion + 1,
        });
      };
    | SubmitAnswers(answers) =>
      ReasonReact.SideEffects((_self => onSelectAnswers(answers)))
    },
  render: ({state: {currentQuestion}, send}) =>
    List.nth(quiz, currentQuestion)
    |> (
      q =>
        <div className="quiz">
          <QuestionPosition quiz currentQuestion />
          <p> (ReasonReact.string(q.text)) </p>
          <OptionList
            options=q.options
            onOptionSelect=(option => send(AddAnswer(option)))
          />
        </div>
    ),
};
