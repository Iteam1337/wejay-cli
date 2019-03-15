let run = (command, args) => {
  let response =
    switch (command |> Command.parse) {
    /* CLI-specific */
    | Login => Api.login()
    | Version => Api.check_version()

    /* Let Wejay handle anything else */
    | _ => (command, args, Utils.read_token()) |> Api.wejay
    };

  response |> Command.handle_response(command);
};
