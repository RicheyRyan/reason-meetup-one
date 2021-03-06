// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Express = require("bs-express/lib/js/src/Express.js");
var Process = require("process");
var Js_option = require("bs-platform/lib/js/js_option.js");
var Routes$ReactTemplate = require("../Shared/Routes.bs.js");
var Decoder$ReactTemplate = require("../Shared/Decoder.bs.js");
var Encoder$ReactTemplate = require("../Shared/Encoder.bs.js");
var QuizRules$ReactTemplate = require("./QuizRules.bs.js");

var app = Express.express(/* () */0);

Express.App[/* use */0](app, Express.Middleware[/* json */0](undefined, undefined, undefined, /* () */0));

var options = Express.Static[/* defaultOptions */0](/* () */0);

Express.App[/* useOnPath */2](app, Routes$ReactTemplate.resolveRoute(/* Index */0), Express.Static[/* asMiddleware */13](Express.Static[/* make */12]("src/Server/Public", options)));

Express.App[/* get */4](app, Routes$ReactTemplate.resolveRoute(/* Quiz */1), Express.Middleware[/* from */5]((function (_, _$1, res) {
            return Express.Response[/* sendJson */3](QuizRules$ReactTemplate.returnQuiz(/* () */0), res);
          })));

Express.App[/* post */7](app, Routes$ReactTemplate.resolveRoute(/* Quiz */1), Express.Middleware[/* from */5]((function (_, req, res) {
            var json = Encoder$ReactTemplate.result(QuizRules$ReactTemplate.calculateScore(Decoder$ReactTemplate.answerList(Js_option.getExn(Express.Request[/* bodyJSON */3](req)))));
            return Express.Response[/* sendJson */3](json, res);
          })));

function onListen(e) {
  var exit = 0;
  var val;
  try {
    val = e;
    exit = 1;
  }
  catch (raw_exn){
    var exn = Js_exn.internalToOCamlException(raw_exn);
    if (exn[0] === Js_exn.$$Error) {
      console.log(exn[1]);
      Process.exit(1);
      return /* () */0;
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    console.log("Listening at http://127.0.0.1:3000");
    return /* () */0;
  }
  
}

var server = Express.App[/* listen */19](app, 3000, onListen, /* () */0);

exports.app = app;
exports.onListen = onListen;
exports.server = server;
/* app Not a pure module */
