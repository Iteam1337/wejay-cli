#!/bin/bash

install_wejay() {
  mkdir $HOME/.wejay

  curl -o $HOME/.wejay/wejay https://github.com/Iteam1337/wejay-cli/blob/master/_build/default/src/Main.exe
}

setup_shell() {
  CURRENT_SHELL=$(basename $SHELL)

  if [ "$CURRENT_SHELL" == "zsh" ]; then
    CONF_FILE=$HOME/.zshrc
    echo "Installing for Zsh. Appending the following to $CONF_FILE:"
    echo ""
    echo '  # wejay'
    echo '  export PATH=$HOME/.wejay:$PATH'

    echo '' >> $CONF_FILE
    echo '# wejay' >> $CONF_FILE
    echo 'export PATH=$HOME/.wejay:$PATH' >> $CONF_FILE

  elif [ "$CURRENT_SHELL" == "bash" ]; then
    if [ "$OS" == "Darwin" ]; then
      CONF_FILE=$HOME/.profile
    else
      CONF_FILE=$HOME/.bashrc
    fi
    echo "Installing for Bash. Appending the following to $CONF_FILE:"
    echo ""
    echo '  # wejay'
    echo '  export PATH=$HOME/.wejay:$PATH'

    echo '' >> $CONF_FILE
    echo '# wejay' >> $CONF_FILE
    echo 'export PATH=$HOME/.wejay:$PATH' >> $CONF_FILE

  else
    echo "Could not infer shell type. Please set up manually."
    exit 1
  fi

  echo ""
  echo "In order to apply the changes, open a new terminal or run the following command:"
  echo ""
  echo "  source $CONF_FILE"
}

install_wejay
setup_shell
