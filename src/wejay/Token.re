open Bos.OS;

let get_wejay_dir = () =>
  switch (Dir.user()) {
  | Ok(d) => Fpath.to_string(d) ++ "/.wejay"
  | _ => ""
  };

let path = get_wejay_dir() ++ "/.token" |> Fpath.v;

let retrieve = () => {
  switch (File.read(path)) {
  | Ok(t) => t
  | Error(_) => ""
  };
};

let write_token = token => {
  switch (get_wejay_dir() |> Fpath.v |> Dir.exists) {
  | Ok(exists) =>
    exists ? () : Dir.create(get_wejay_dir() |> Fpath.v) |> ignore
  | Error(`Msg(_msg)) =>
    print_string("Error while trying to read directory")
  };

  switch (File.write(path, token)) {
  | Ok(_) => print_string("Successfully wrote token to file.")
  | Error(`Msg(_msg)) => print_string("Error while trying to add token")
  };
};
