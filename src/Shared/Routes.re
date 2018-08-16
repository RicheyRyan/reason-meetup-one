type routes =
  | Index
  | Quiz;

let resolveRoute = route =>
  switch route {
  | Index => "/"
  | Quiz => "/quiz"
  };
