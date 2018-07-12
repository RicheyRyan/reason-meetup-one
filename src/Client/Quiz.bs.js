// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var OptionList$ReactTemplate = require("./OptionList.bs.js");
var QuestionPosition$ReactTemplate = require("./QuestionPosition.bs.js");

var component = ReasonReact.reducerComponent("Quiz");

function make(quiz, onSelectAnswers, _) {
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
          /* render */(function (param) {
              var send = param[/* send */3];
              var currentQuestion = param[/* state */1][/* currentQuestion */1];
              var q = List.nth(quiz, currentQuestion);
              return React.createElement("div", {
                          className: "quiz"
                        }, ReasonReact.element(/* None */0, /* None */0, QuestionPosition$ReactTemplate.make(quiz, currentQuestion, /* array */[])), React.createElement("p", undefined, q[/* text */0]), ReasonReact.element(/* None */0, /* None */0, OptionList$ReactTemplate.make(q[/* options */1], (function (option) {
                                    return Curry._1(send, /* AddAnswer */Block.__(0, [option]));
                                  }), /* array */[])));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* answers : [] */0,
                      /* currentQuestion */0
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                var answers = action[0];
                return /* SideEffects */Block.__(1, [(function () {
                              return Curry._1(onSelectAnswers, answers);
                            })]);
              } else {
                var currentQuestion = state[/* currentQuestion */1];
                var nextAnswers = List.append(state[/* answers */0], /* :: */[
                      action[0],
                      /* [] */0
                    ]);
                if (currentQuestion === (List.length(quiz) - 1 | 0)) {
                  return /* UpdateWithSideEffects */Block.__(2, [
                            /* record */[
                              /* answers */nextAnswers,
                              /* currentQuestion */currentQuestion
                            ],
                            (function (self) {
                                return Curry._1(self[/* send */3], /* SubmitAnswers */Block.__(1, [nextAnswers]));
                              })
                          ]);
                } else {
                  return /* Update */Block.__(0, [/* record */[
                              /* answers */nextAnswers,
                              /* currentQuestion */currentQuestion + 1 | 0
                            ]]);
                }
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
