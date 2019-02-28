open Cmdliner;

module Args = {
  let command = {
    let doc = "Commands";

    Arg.(value & pos(0, string, "") & info([], ~docv="COMMAND", ~doc));
  };
  let args = {
    let doc = "Args";

    Arg.(value & pos(1, string, "") & info([], ~docv="ARGS", ~doc));
  };
};

let cmd = Term.(const(Wejay.run) $ Args.command $ Args.args);

Term.eval((cmd, Term.info("wejay"))) |> Term.exit;
