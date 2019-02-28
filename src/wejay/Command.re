type t =
  | Blame
  | Login
  | Search
  | Unknown;

let parse = cmd => {
  switch (cmd) {
  | "blame" => Blame
  | "login" => Login
  | "search" => Search
  | _ => Unknown
  };
};

let to_string = cmd =>
  switch (cmd) {
  | Blame => "blame"
  | Login => "login"
  | Search => "search"
  | _ => ""
  };

/**
  TODO: Implement this
  */
let handle = payload => {
  switch (payload) {
  | `Ok(d) => d |> print_string
  | `Failed(e) => e |> print_string
  };
};
