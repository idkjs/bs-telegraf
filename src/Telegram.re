/* https://core.telegram.org/bots/api#user
   https://github.com/sergeysova/telegram-typings/blob/6ab52ba83c17d53947ba8bd667db8f617b6dd32e/javascript/index.d.ts#L172
   */
module User = {
  type t = {
    /**
   * Unique identifier for this user or bot
   */
    id: int,
    /**
   * True, if this user is a bot
   */
    is_bot: bool,
    /**
   * User‘s or bot’s first name
   */
    first_name: string,
    /**
   * User‘s or bot’s last name
   */
    last_name: option(string),
    /**
   * User‘s or bot’s username
   */
    username: option(string),
    /**
   * IETF language tag of the user's language
   * @see https://en.wikipedia.org/wiki/IETF_language_tag
   */
    language_code: option(string),
  };
};
/* https://core.telegram.org/bots/api#message */
module Message = {
  type t = {
    message_id: int,
    date: string,
    from: User.t,
    text: string,
  };
  /* this function takes a message of type t and returns a string
     `m.from.first_name;` note: `from` is of type `User.t` so when we access the `m.from` key, we have access to all of the properties of User.t from which we are selecting the `first_name` key
      */
  let format = (m): string =>
    "[" ++ m.date ++ "] <" ++ m.from.first_name ++ "> " ++ m.text;
};