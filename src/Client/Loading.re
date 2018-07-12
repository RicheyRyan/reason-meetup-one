let component = ReasonReact.statelessComponent("Loading");

let make = (~text: string, _children) => {
  ...component,
  render: _self => <div> <p> (ReasonReact.string(text)) </p> </div>,
};