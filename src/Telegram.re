/* https://core.telegram.org/bots/api#message */
module Message = {
  type t = {
    message_id: int,
    date: string,
    from: first_name,
    text: string,
  }
  and first_name = string;
  let format = (m): string =>
    "[" ++ m##date ++ "] <" ++ m##from##first_name ++ "> " ++ m##text;
};