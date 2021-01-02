# Quokka Engine

Quokka Engine is a early-stage cross-platform game engine for Windows and MacOS.

## Background information
The main objective of the project is to learn C++ and how a game engine works and it is part of my minor "Open Innovation".

## How to build your development environment
We use Premake as our development tool to generate our projects and workspaces. Generating the workspaces and projects can be done with following commandline from the root directory:

### Windows
```
src/vendor/Premake/bin/premake5 vs2019
```

### MacOS
```
src/vendor/Premake/bin/premake5 xcode4
```

If your using an older version or another IDE, you can always use __--help__ for alternatives.

> NOTE: The current version of premake is still in __alpha__ development, although the version we use is stable enough to use for our project. Furthermore, we can't use premake to clean our project, although premake says there is an commandline option.

## Contact
Ruben Falkenburg - [@thecodesurfer](https://twitter.com/thecodesurfer) - rubenfalkenburg@gmail.com