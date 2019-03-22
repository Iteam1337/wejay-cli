# Sonos Wejay - CLI

## Get started

### Install

```
bash <(curl -s https://raw.githubusercontent.com/Iteam1337/wejay-cli/master/install/install.sh)
```

To log in via Slack, run the command: `wejay login` and follow the instructions.


### Develop

**Build**

`dune build`

or

`dune build --watch`

**Run**

`./_build/default/src/bin/Main.exe CMD ARGS`

e.g. `./_build/default/src/bin/Main.exe search "Rage Against the Machine - People of the Sun"`
