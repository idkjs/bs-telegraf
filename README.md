# bs-telegraf

## WIP Bindings to [Telegraf.js](https://telegraf.js.org/#/) Telegram Bot API

## Telegraf/Telegram Typings

Telegraph is using the typings seen here from [./telegram-types.d.ts](/Users/prisc_000/Documents/GitHub/bs-telegraf/telegram-types.d.ts) which are from its <https://github.com/sergeysova/telegram-typings/blob/6ab52ba83c17d53947ba8bd667db8f617b6dd32e/javascript/index.d.ts#L172>. I am noting this because there seems to be some telegram-types which dont have the `interface User` defined.

## Telegraf [Context](https://telegraf.js.org/#/?id=context)

```ocaml
module Context = {
  type t = {
    updateType: string,
    update: Update.t,
  };
  type middleware = t => unit;
};
```

## Telegraf [Update](https://telegraf.js.org/#/?id=update)

```ocaml
module Context = {
  type t = {
    updateType: string,
    update: Update.t,
  };
  type middleware = t => unit;
};
```

## Testing in Telegram

Open Telegram, got to your bot and enter `/start`. This will log the `context` object with `nodemon examples/index.js` running. Can't get it to run with reason version yet. Can't tell why. Probably need `isomorphic fetch` but don't understand yet why that is the case. I know reason needs some transport but where can i see the error or where its not being called?
