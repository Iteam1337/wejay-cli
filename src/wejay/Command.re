type t =
  | Blame
  | GetQueue
  | FullQueue
  | Login
  | Friday
  | NowPlaying
  | Help
  | Search
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
  | "q"
  | "queue" => Queue
  | "search" => Search
  | "version" => Version
  | "volume" => Volume
  | _cmd => Unknown
  };
};

let handle_response = (command, result) => {
  switch (command |> parse, result) {
  /* Error-message from Wejay, just print it  */
  | (_, `Failed(e)) => e |> Errors.to_string

  /* Standard response */
  | (Blame, `Ok(d))
  | (Friday, `Ok(d))
  | (FullQueue, `Ok(d))
  | (GetQueue, `Ok(d))
  | (Help, `Ok(d))
  | (NowPlaying, `Ok(d))
  | (Queue, `Ok(d))
  | (Version, `Ok(d))
  | (Volume, `Ok(d))
  | (Unknown, `Ok(d)) => d |> print_string

  /* Special cases  */
  | (Login, `Ok(d)) =>
    print_string(d);

    let res = read_line() |> Utils.write_token;

    switch (res) {
    | `Ok(d) => d |> print_string
    | `Failed(e) => e |> Errors.to_string
    };
  | (Search, `Ok(d)) => "Search: " ++ d |> print_string
  };
};
