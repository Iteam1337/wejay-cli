type t =
  | Blame
  | GetQueue
  | FullQueue
  | Friday
  | NowPlaying
  | Login
  | Help
  | Search
  | Version
  | Volume
  | Queue
  | Unknown;

let parse = cmd => {
  switch (cmd) {
  | "blame" => Blame
  | "login" => Login
  | "search" => Search
  | "help" => Help
  | "fq"
  | "fullqueue" => FullQueue
  | "friday" => Friday
  | "gq"
  | "getqueue" => GetQueue
  | "queue" => Queue
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
  | (FullQueue, `Ok(d))
  | (Friday, `Ok(d))
  | (GetQueue, `Ok(d))
  | (Help, `Ok(d))
  | (NowPlaying, `Ok(d))
  | (Version, `Ok(d))
  | (Volume, `Ok(d))
  | (Queue, `Ok(d))
  | (Unknown, `Ok(d)) => d |> print_string

  /* Requires user-input */
  | (Login, `Ok(d)) => "Login: " ++ d |> print_string
  | (Search, `Ok(d)) => "Search: " ++ d |> print_string
  };
};
