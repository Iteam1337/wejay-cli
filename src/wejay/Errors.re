let to_string = e => {
  switch (e) {
  | `Could_not_open_browser => Format.printf("Could not open browsser")
  | `Could_not_check_version(formatter, err) =>
    Format.printf("Could not check version:\n\n%a", formatter, err)
  | `Wejay_request(formatter, err) =>
    Format.printf(
      "Error while trying to request Wejay API:\n\n%a",
      formatter,
      err,
    )
  | `Could_not_write_token(err) =>
    Format.printf("Error while trying to add token: %s", err)
  | `Could_not_read_directory(err) =>
    Format.printf("Error while trying to read directory: %s", err)
  | `Not_implemented(name) => Format.printf("Not implemented yet: %s", name)
  | _ => Format.printf("Unknown error")
  };
};
