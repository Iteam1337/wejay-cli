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

  let to_string = cmd =>
    switch (cmd) {
    | Blame => "blame"
    | Search => "search"
    | _ => ""
    };
};

module Api = {
  let blame = () => "blame";
  let search = args => "search: " ++ args;

  let sendBody = (command, args) => {
    let replace_command = Str.(replace_first(regexp("{| command |}")));
    let replace_args = Str.(replace_first(regexp("{| args |}")));

    "{ \"command\": \"{| command |}\", \"args\": \"{| args |}\" }"
    |> replace_command(command |> Command.to_string)
    |> replace_args(args);
  };

  let makeRequest = (command, args) => {
    switch (
      Curly.(
        run(
          Request.make(
            ~url="http://localhost:3000/cli",
            ~meth=`POST,
            ~body=sendBody(command, args),
            ~headers=[("Content-Type", "application/json")],
            (),
          ),
        )
      )
    ) {
    | Ok(x) => "Body: \n" ++ x.Curly.Response.body
    | Error(_e) => "Failed"
    };
  };

  let request = (args, command: Command.t) =>
    switch (command) {
    | Blame
    | Search => makeRequest(command, args)
    | _ => "Not a valid command."
    };
};

let run = (command, args) => {
  Logs.app(m => m("Hello World!"));
  command |> Command.parse |> Api.request(args) |> print_string;
};