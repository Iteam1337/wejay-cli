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
  /*
    | Ok(data) => `Ok(data.Curly.Response.body)
   | Error(e) => `Failed(`Could_not_check_version(e))
   */
  | _ => `Failed(`Not_implemented("version"))
  };
};

let login = () => {
  let res = Sys.command("open " ++ Config.auth_url);

  switch (res) {
  | 0 => `Ok("Paste the token you received: \n")
  | _ => `Failed(`Could_not_open_browser)
  };
};

let wejay = ((command, args, token)) => {
  switch (
    Curly.(
      run(
        Request.make(
          ~url=Config.event_url,
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
  | Error(e) => `Failed(`Wejay_request((Curly.Error.pp, e)))
  };
};
