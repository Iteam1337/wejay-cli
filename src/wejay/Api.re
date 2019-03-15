let send_body = (command, args) => {
  let replace_text = (replacer, text) =>
    Str.(replace_first(regexp(text), replacer));

  "{ \"command\": \"COMMAND\", \"args\": \"ARGS\" }"
  |> replace_text(command, "COMMAND")
  |> replace_text(args, "ARGS");
};

let check_version = () => {
  /*
   * TODO(@lessp): Implement this, an idea would be to compare MD5 with
   *               file on disk and the binary on Github
   */
  switch (Curly.(run(Request.make(~url=Config.build_url, ~meth=`GET, ())))) {
  /*
   | Ok(data) => `Ok(data.Curly.Response.body)
   | Error(e) => `Failed(`Could_not_check_version((Curly.Error.pp, e)))
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
          ~body=send_body(command, args),
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
