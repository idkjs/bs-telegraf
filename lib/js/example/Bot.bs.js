// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Telegraf = require("telegraf");

function format(m) {
  return "[" + (m.date + ("] <" + (m.from + ("> " + m.text))));
}

var Message = {
  format: format
};

var Update = { };

var Context = { };

function make(token) {
  return new Telegraf.telegraf(token);
}

exports.Message = Message;
exports.Update = Update;
exports.Context = Context;
exports.make = make;
/* telegraf Not a pure module */