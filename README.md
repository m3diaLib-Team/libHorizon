# libHorizon [![Build Status](https://travis-ci.org/m3diaLib-Team/libHorizon.svg?branch=develop)](https://travis-ci.org/m3diaLib-Team/libHorizon)[![CodeFactor](https://www.codefactor.io/repository/github/m3dialib-team/libhorizon/badge)](https://www.codefactor.io/repository/github/m3dialib-team/libhorizon)
A C++ framework to create powerful Nintendo Switch homebrew with ease.

## FAQ/Troubleshooting
#### My application has no console output
libHorizon automatically forwards Stdio and Stderr to a connected nxlink-server. In order to see this output you have to netload your application with this command:
```
nxlink <your-app.nro> -s
```

If you want to disable nxlink-Stdio, just pass `false` to your `horizon::Applet`'s constructor.

#### Can you please implement X?
If a stable release of libhorizon doesn't have a specific feature you desire, you're free to create an issue to request it. Please note that not all features are planned to be implemented in libhorizon. If you implemented a feature yourself and want to add it to libhorizon, feel free to create a [pull request](https://github.com/m3diaLib-Team/libHorizon/pull/new/develop).

## Mirrors
 * [GitHub](https://github.com/m3diaLib-Team/libHorizon)
 * [GitLab](https://gitlab.com/StuntHacks/libhorizon)
