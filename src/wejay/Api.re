let send_body = (command, args, user) => {
  let replace_text = (replacer, text) =>
    Str.(replace_first(regexp(text), replacer));

  "{ \"command\": \"{| command |}\", \"args\": \"{| args |}\",  \"user\": \"{| user |}\"}"
  |> replace_text(command, "{| command |}")
  |> replace_text(args, "{| args |}")
  |> replace_text(user, "{| user |}");
};

let make_request = ((command, args, token)) => {
  print_string(send_body(command, args, token));
  switch (
    Curly.(
      run(
        Request.make(
          ~url="https://eed68a86.ngrok.io/cli",
          ~meth=`POST,
          ~body=send_body(command, args, token),
          ~headers=[
            ("Content-Type", "application/json"),
            ("token", "placeholder"),
          ],
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
