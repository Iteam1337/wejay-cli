let run = (command, args) => {
  (command, args)
  |> Api.make_request
  |> Command.handle(command |> Command.parse);
};
