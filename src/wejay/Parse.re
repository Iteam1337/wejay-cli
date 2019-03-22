let replace_text = (replacer, text) =>
  Str.(global_replace(regexp(text), replacer));

let make_bold = s =>
  <Pastel bold=true color=Cyan> {s |> replace_text("", "*")} </Pastel>;
let make_italic = s =>
  <Pastel italic=true> {s |> replace_text("", "`")} </Pastel>;

let handle_special_chars = (c, s) => {
  switch (c) {
  | '*' => s |> make_bold
  | '`' => s |> make_italic
  | _ => ""
  };
};

let matches = ['*', '`'];

let run = data => {
  data
  |> Str.split(Str.regexp("[\r\n]"))
  |> List.map(s => {
       let res = '*' |> String.contains(s) ? s |> make_bold : s;
       res;
       /*
         let contains = s |> String.contains;

        let ret = '`' |> String.contains(res) ? s |> make_italic : s;
          matches
          |> List.map(char =>
               contains(char) ? handle_special_chars(char, s) : s
             )
          |> String.concat("\n");
          */
     })
  |> String.concat("\n");
};
