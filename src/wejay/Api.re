let send_body = (command, args, user) => {
  let replace_text = (replacer, text) =>
    Str.(replace_first(regexp(text), replacer));

  "{ \"command\": \"{| command |}\", \"args\": \"{| args |}\",  \"user\": \"{| user |}\"}"
  |> replace_text(command, "{| command |}")
  |> replace_text(args, "{| args |}")
  |> replace_text(user, "{| user |}");
};

let check_version = () => {
  switch (
    Curly.(run(Request.make(~url=Config.repository_url, ~meth=`GET, ())))
  ) {
  | Ok(data) => `Ok(data.Curly.Response.body)
  | Error(_) => `Failed("Error")
  };
};

let make_request = ((command, args, token)) => {
  switch (
    Curly.(
      run(
        Request.make(
          ~url=Config.server_url,
          ~meth=`POST,
          ~body=send_body(command, args, token),
          ~headers=[
            ("Content-Type", "application/json"),
            ("access_token", token),
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
