let component = ReasonReact.statelessComponent("Greeting");

let make = (~onClick, _children) => {
  ...component,
  render: _self =>
    <div className="greeting">
      <p>
        (ReasonReact.string("Welcome! Click begin to load the questions"))
      </p>
      <button onClick> (ReasonReact.string("Load questions!")) </button>
    </div>,
};