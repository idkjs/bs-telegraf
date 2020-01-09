[%raw {| require('dotenv').config() |}];
[@bs.val]
external jsonStringify: ('a, Js.Nullable.t(unit), int) => string =
  "JSON.stringify";
[@bs.val] external apiToken: Telegraf.Bot.token = "process.env.TELEGRAM_TOKEN";
// Js.log2("apiToken", apiToken);
let stringify = str => jsonStringify(str, Js.Nullable.null, 2);
Telegraf.Bot.(
  make(apiToken)
  |> hears("hi", context => {
       Js.log(stringify(context.update.message));
       context
       |> reply @@
       "Welcome";
     })
  |> startPolling
);