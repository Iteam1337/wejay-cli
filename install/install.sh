#!/bin/bash

install_wejay() {
  INSTALL_DIR="$HOME/.wejay"
  mkdir -p $INSTALL_DIR &> /dev/null

  curl -o $HOME/.wejay/wejay https://raw.githubusercontent.com/Iteam1337/wejay-cli/master/_build/default/src/bin/Main.exe

  chmod u+x $INSTALL_DIR/wejay
}

setup_shell() {
  CONF_FILE=$HOME/.YOUR_SHELL_CONFIG

  echo "Add the following to your shell config-file:"
  echo ""
  echo '  # wejay'
  echo '  export PATH=$HOME/.wejay:$PATH'

  echo ""
  echo "In order to apply the changes, open a new terminal or run the following command:"
  echo ""
  echo "  source $CONF_FILE"
}

install_wejay
setup_shell
