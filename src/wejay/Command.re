type t =
  | Blame
  | GetQueue
  | FullQueue
  | Friday
  | NowPlaying
  | Login
  | Help
  | Search
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
  | "volume" => Volume
  | _cmd => Unknown
  };
};

let handle = (command, payload) => {
  switch (command, payload) {
  /* Just print the error-message from Wejay */
  | (_, `Failed(e)) => "Failed: " ++ e |> print_string

  /* Just print the response */
  | (Blame, `Ok(d))
  | (FullQueue, `Ok(d))
  | (Friday, `Ok(d))
  | (GetQueue, `Ok(d))
  | (Help, `Ok(d))
  | (NowPlaying, `Ok(d))
  | (Volume, `Ok(d))
  | (Queue, `Ok(d))
  | (Unknown, `Ok(d)) => d |> print_string

  /* These need to be handled separately */
  | (Login, `Ok(d)) => "Login: " ++ d |> print_string
  | (Search, `Ok(d)) => "Search: " ++ d |> print_string
  };
};
