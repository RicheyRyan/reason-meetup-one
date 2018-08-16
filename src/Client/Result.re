let component = ReasonReact.statelessComponent("Result");

let getResultString = ({numCorrect, totalQuestions}: Shared.result) => {j|You got $numCorrect out of $totalQuestions right!|j};

let make = (~result: Shared.result, _children) => {
  ...component,
  render: _self =>
    <div className="result">
      <p> (getResultString(result) |> ReasonReact.string) </p>
    </div>,
};
