type t =
  | Blame
  | GetQueue
  | FullQueue
  | Login
  | Friday
  | NowPlaying
  | Help
  | Search
  | Token
  | Version
  | Volume
  | Queue
  | Unknown;

let parse = cmd => {
  switch (cmd) {
  | "blame" => Blame
  | "friday" => Friday
  | "fq"
  | "fullqueue" => FullQueue
  | "gq"
  | "getqueue" => GetQueue
  | "help" => Help
  | "login" => Login
  | "queue" => Queue
  | "search" => Search
  | "token" => Token
  | "version" => Version
  | "volume" => Volume
  | _cmd => Unknown
  };
};

let handle_response = (command, payload) => {
  switch (command |> parse, payload) {
  /* Error-message from Wejay, just print it  */
  | (_, `Failed(e)) => "Failed: " ++ e |> print_string

  /* Standard response */
  | (Blame, `Ok(d))
  | (Friday, `Ok(d))
  | (FullQueue, `Ok(d))
  | (GetQueue, `Ok(d))
  | (Help, `Ok(d))
  | (NowPlaying, `Ok(d))
  | (Queue, `Ok(d))
  | (Token, `Ok(d))
  | (Version, `Ok(d))
  | (Volume, `Ok(d))
  | (Unknown, `Ok(d)) => d |> print_string

  /* Special cases  */
  | (Login, `Ok(d)) => "Login: " ++ d |> print_string
  | (Search, `Ok(d)) => "Search: " ++ d |> print_string
  };
};
