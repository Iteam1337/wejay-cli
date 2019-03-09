let run = (command, args) =>
  switch (command |> Command.parse) {
  | Login => Token.write_token(args)
  | Version => Api.check_version() |> ignore
  | _ =>
    (command, args, Token.retrieve())
    |> Api.make_request
    |> Command.handle_response(command)
  };
