module Command = {
  type t =
    | Blame
    | Search
    | Unknown;

  let parse = cmd =>
    switch (cmd) {
    | "blame" => Blame
    | "search" => Search
    | _ => Unknown
    };
};

module Api = {
  let blame = () => "blame";
  let search = args => "search: " ++ args;

  let request = (args, command: Command.t) =>
    switch (command) {
    | Blame => blame()
    | Search => search(args)
    | _ => ""
    };
};

let run = (command, args) => {
  print_string("Command: " ++ command ++ "\n" ++ "Args: " ++ args ++ "\n\n");

  command |> Command.parse |> Api.request(args) |> print_string;
};

/*
   switch (
     Curly.(run(Request.make(~url="https://opam.ocaml.org", ~meth=`GET, ())))
   ) {
   | Ok(x) =>
     Format.printf("status: %d\n", x.Curly.Response.code);
     Format.printf("headers: %a\n", Curly.Header.pp, x.Curly.Response.headers);
     Format.printf("body: %s\n", x.Curly.Response.body);
   | Error(e) => Format.printf("Failed: %a", Curly.Error.pp, e)
   };
 */