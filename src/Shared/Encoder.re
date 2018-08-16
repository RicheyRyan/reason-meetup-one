open Shared;

let answer = ({text}: answer) =>
  Json.Encode.(object_([("text", string(text))]));

let answerList = (answers: list(answer)) =>
  Json.Encode.(list(answer, answers));

let question = ({options, text}: question) =>
  Json.Encode.(
    object_([
      ("text", string(text)),
      ("options", answerList(options)),
      ("correctAnswer", null),
    ])
  );

let quiz = (quiz: quiz) => Json.Encode.(list(question, quiz));

let result = ({numCorrect, totalQuestions}: result) =>
  Json.Encode.(
    object_([
      ("numCorrect", int(numCorrect)),
      ("totalQuestions", int(totalQuestions)),
    ])
  );
