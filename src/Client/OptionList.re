let component = ReasonReact.statelessComponent("OptionList");

let makeOptionItem = (answer: Shared.answer, onOptionSelect) =>
  <li
    key=answer.text
    className="option-item"
    onClick=(_event => onOptionSelect(answer))>
    (ReasonReact.string(answer.text))
  </li>;
let make = (~options: list(Shared.answer), ~onOptionSelect, _children) => {
  ...component,
  render: _self =>
    <ul className="option-list">
      (
        List.map(opt => makeOptionItem(opt, onOptionSelect), options)
        |> Array.of_list
        |> ReasonReact.array
      )
    </ul>,
};