let run = (command, args) => {
  let response =
    switch (command |> Command.parse) {
    | Login => Api.login()
    | Version => Api.check_version()
    | _ => (command, args, Token.retrieve()) |> Api.make_request
    };

  response |> Command.handle_response(command);
};
