type actions =
  | Initial
  | QuizLoading
  | ResultLoading(list(Shared.answer))
  | Failed(Js.Promise.error)
  | QuizLoaded(Shared.quiz)
  | ResultLoaded(Shared.result);

type state = {
  currentState: actions,
  answers: list(Shared.answer),
};

let component = ReasonReact.reducerComponent("App");

let requestQuestions = (cb: actions => unit) =>
  Js.Promise.(
    Fetch.fetch(Routes.resolveRoute(Quiz))
    |> then_(Fetch.Response.json)
    |> then_(json =>
         Decoder.quiz(json) |> (quiz => QuizLoaded(quiz) |> cb |> resolve)
       )
    |> catch(err => Failed(err) |> cb |> resolve)
  )
  |> ignore;

let submitAnswers = (answers: list(Shared.answer), cb) =>
  Js.Promise.(
    Fetch.(
      fetchWithInit(
        Routes.resolveRoute(Quiz),
        RequestInit.make(
          ~method_=Post,
          ~body=
            Encoder.answerList(answers)
            |> Js.Json.stringify
            |> Fetch.BodyInit.make,
          ~headers=
            Fetch.HeadersInit.make({"Content-Type": "application/json"}),
          (),
        ),
      )
      |> then_(Fetch.Response.json)
      |> then_(json =>
           Decoder.result(json)
           |> (result => ResultLoaded(result) |> cb |> resolve)
         )
      |> catch(err => Failed(err) |> cb |> resolve)
    )
  )
  |> ignore;

let showQuiz = (quiz: Shared.quiz, onSelectAnswers) =>
  <Quiz quiz onSelectAnswers />;

let make = _children => {
  ...component,
  initialState: () => {currentState: Initial, answers: []},
  reducer: (action: actions, state) =>
    switch (action) {
    | Initial => ReasonReact.Update({currentState: Initial, answers: []})
    | QuizLoading =>
      ReasonReact.UpdateWithSideEffects(
        {...state, currentState: QuizLoading},
        (self => requestQuestions(self.send)),
      )
    | ResultLoading(answers) =>
      ReasonReact.UpdateWithSideEffects(
        {...state, currentState: ResultLoading(answers)},
        (self => submitAnswers(answers, self.send)),
      )
    | Failed(_err) => ReasonReact.Update({...state, currentState: action})
    | QuizLoaded(_quiz) =>
      ReasonReact.Update({...state, currentState: action})
    | ResultLoaded(_result) =>
      ReasonReact.Update({...state, currentState: action})
    },
  render: self =>
    switch (self.state.currentState) {
    | Initial => <Greeting onClick=(_event => self.send(QuizLoading)) />
    | QuizLoading => <Loading text="We're just loading the quiz..." />
    | Failed(_err) => <Error />
    | QuizLoaded(quiz) =>
      showQuiz(quiz, answers => self.send(ResultLoading(answers)))
    | ResultLoading(_answers) =>
      <Loading text="We're just loading your results..." />
    | ResultLoaded(result) => <Result result />
    },
};