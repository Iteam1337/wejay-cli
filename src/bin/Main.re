open Cmdliner;

module Args = {
  let command = {
    let doc = "Commands";

    Arg.(value & pos(0, string, "blame") & info([], ~docv="COMMAND", ~doc));
  };

  let args = {
    let doc = "Arguments";
    Arg.(
      value & opt(string, "") & info(["a", "args"], ~docv="ARGUMENTS", ~doc)
    );
  };
};

let cmd = Term.(const(Wejay.run) $ Args.command $ Args.args);

Term.eval((cmd, Term.info("wejay"))) |> Term.exit;