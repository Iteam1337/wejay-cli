let run = (command, args) =>
  /* Special cases */
  if (command |> Command.is_login_request) {
    Token.write_token(args);
  } else {
    let token = Token.get_token();

    (command, args, token)
    |> Api.make_request
    |> Command.handle(command |> Command.parse);
  };
