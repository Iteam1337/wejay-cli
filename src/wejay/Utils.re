open Bos.OS;

let get_wejay_dir = () =>
  switch (Dir.user()) {
  | Ok(d) => Fpath.to_string(d) ++ "/.wejay"
  | _ => ""
  };

let path = get_wejay_dir() ++ "/.token" |> Fpath.v;

let read_token = () => {
  switch (File.read(path)) {
  | Ok(t) => t
  | Error(_) => ""
  };
};

let write_token = token => {
  switch (get_wejay_dir() |> Fpath.v |> Dir.exists) {
  | Ok(exists) =>
    exists ? () : Dir.create(get_wejay_dir() |> Fpath.v) |> ignore
  | Error(`Msg(msg)) => `Failed(`Could_not_read_directory(msg)) |> ignore
  };

  switch (File.write(path, token)) {
  | Ok(_) => `Ok("Successfully wrote token to file.")
  | Error(`Msg(msg)) => `Failed(`Could_not_write_token(msg))
  };
};

let get_local_md5 = () => {
  get_wejay_dir() ++ "/wejay" |> Digest.file |> Digest.to_hex;
};
