# libHorizon
A C++ framework to create powerful Nintendo Switch homebrew with ease.

## FAQ/Troubleshooting
#### My application has no console output
libHorizon automatically forwards Stdio and Stderr to a connected nxlink-server. In order to see this output you have to netload your application with this command:
```
nxlink <your-app.nro> -s
```

If you want to disable nxlink-Stdio, just pass `false` to your `horizon::Applet`'s constructor.
