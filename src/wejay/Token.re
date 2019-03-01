/*
 open Bos.OS;

 let path = "/Users/ter/.wejay/.token" |> Fpath.v;

 let get_token = () => {
   switch (File.read(path)) {
   | Ok(t) => t
   | Error(_) => ""
   };
 };

 let write_token = token => {
   File.write(path, token) |> ignore;
 };
 */

open Bos.OS;

let get_user_dir = () =>
  switch (Dir.user()) {
  | Ok(d) => Dir.to_string(d)
  | Error(e) => Dir.to_string(e)
  };

let path = get_user_dir() ++ ".wejay/.token" |> Fpath.v;

let get_token = () => {
  switch (File.read(path)) {
  | Ok(t) => t
  | Error(_) => ""
  };
};

let write_token = token => {
  File.write(path, token) |> ignore;
};
