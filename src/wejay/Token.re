open Bos.OS;

let get_wejay_dir = () =>
  switch (Dir.user()) {
  | Ok(d) => Fpath.to_string(d) ++ "/.wejay"
  | _ => ""
  };

let path = get_wejay_dir() ++ "/.token" |> Fpath.v;

let get_token = () => {
  switch (File.read(path)) {
  | Ok(t) => t
  | Error(_) => ""
  };
};

let write_token = token => {
  print_string(get_wejay_dir());
  switch (get_wejay_dir() |> Fpath.v |> Dir.exists) {
  | Ok(_) => Dir.create(get_wejay_dir() |> Fpath.v) |> ignore
  | Error(_) => ()
  };

  File.write(path, token) |> ignore;
};
