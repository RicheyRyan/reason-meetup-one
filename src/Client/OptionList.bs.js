// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("OptionList");

function makeOptionItem(answer, onOptionSelect) {
  return React.createElement("li", {
              key: answer[/* text */0],
              className: "option-item",
              onClick: (function () {
                  return Curry._1(onOptionSelect, answer);
                })
            }, answer[/* text */0]);
}

function make(options, onOptionSelect, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("ul", {
                          className: "option-list"
                        }, $$Array.of_list(List.map((function (opt) {
                                    return makeOptionItem(opt, onOptionSelect);
                                  }), options)));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.makeOptionItem = makeOptionItem;
exports.make = make;
/* component Not a pure module */
