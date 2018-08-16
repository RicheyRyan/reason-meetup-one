open Express;

let app = express();

Express.App.use(app, Middleware.json());

Express.App.useOnPath(
  app,
  ~path=Routes.(resolveRoute(Index)),
  {
    let options = Static.defaultOptions();
    Static.make("src/Server/Public", options) |> Static.asMiddleware;
  },
);

Express.App.get(app, ~path=Routes.(resolveRoute(Quiz))) @@
Middleware.from((_next, _req, res) =>
  Response.sendJson(QuizRules.returnQuiz(), res)
);

Express.App.post(app, ~path=Routes.(resolveRoute(Quiz))) @@
Middleware.from((_next, req, res) =>
  req
  |> Request.bodyJSON
  |> Js.Option.getExn
  |> Decoder.answerList
  |> QuizRules.calculateScore
  |> Encoder.result
  |> (json => Response.sendJson(json, res))
);

let onListen = (e: Js.null_undefined(Js.Exn.t)) =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log("Listening at http://127.0.0.1:3000")
  };

let server = Express.App.listen(app, ~port=3000, ~onListen, ());
