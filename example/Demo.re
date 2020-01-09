Js.log("Hello, BuckleScript and Reason!");

/*
 // example of using bs.raw instead of the bs-dotenv bindings
 [%raw {| require('dotenv').config() |}];
 [@bs.val]
 external apiTokenVal: Telegraf.Bot.token = "process.env.TELEGRAM_TOKEN";
 Js.log2("apiTokenVal", apiTokenVal); */

external castToken: 'a => Telegraf.Bot.token = "%identity";
Dotenv.config();

let apiToken: Telegraf.Bot.token =
  Js.Dict.unsafeGet(Node.Process.process##env, "TELEGRAM_TOKEN")->castToken;
Js.log2("apiToken", apiToken);
let hashtag = [%re "/#[^ ,.]+/"];

// module MessageCollectionType = {
//   type t = Telegram.Message.t;
//   let key = "messages";
//   let toString = (data: t) =>
//     Js.Json.stringifyAny(data) |> Js.Option.getWithDefault("");
// };

let save = message => {
  Js.log2("message", message);
};
Telegraf.Bot.(
  make(apiToken)
  |> hears("messages", context => {
       Js.log2("messages", context);
       save(context.update.message);
       context
       |> reply @@
       "Heard: "
       ++ Telegram.Message.format(context.update.message);
     })
  |> startPolling
);