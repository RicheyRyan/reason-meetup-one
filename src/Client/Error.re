let component = ReasonReact.statelessComponent("Error");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <p>
        (ReasonReact.string("There has been an error loading the quiz..."))
      </p>
    </div>,
};
