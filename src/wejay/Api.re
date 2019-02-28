let send_body = (command, args) => {
  let replace_command = Str.(replace_first(regexp("{| command |}")));
  let replace_args = Str.(replace_first(regexp("{| args |}")));

  "{ \"command\": \"{| command |}\", \"args\": \"{| args |}\" }"
  |> replace_command(command)
  |> replace_args(args);
};

let make_request = ((command, args)) => {
  switch (
    Curly.(
      run(
        Request.make(
          ~url="http://localhost:3000/cli",
          ~meth=`POST,
          ~body=send_body(command, args),
          ~headers=[("Content-Type", "application/json")],
          (),
        ),
      )
    )
  ) {
  | Ok(data) => `Ok(data.Curly.Response.body)
  | Error(e) =>
    Format.printf("Failed: %a", Curly.Error.pp, e);
    `Failed("Error");
  };
};
