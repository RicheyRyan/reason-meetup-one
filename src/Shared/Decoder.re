open Shared;

let answer = (json: Js.Json.t) =>
  Json.Decode.{text: json |> field("text", string)};

let answerList = (json: Js.Json.t) => Json.Decode.(json |> list(answer));

let question = (json: Js.Json.t) : question =>
  Json.Decode.{
    text: json |> field("text", string),
    options: json |> field("options", answerList),
    correctAnswer: json |> optional(field("correctAnswer", answer)),
  };

let quiz = (json: Js.Json.t) => Json.Decode.(json |> list(question));

let result = (json: Js.Json.t) =>
  Json.Decode.{
    numCorrect: json |> field("numCorrect", int),
    totalQuestions: json |> field("totalQuestions", int),
  };
