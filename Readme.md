#Compilation Time

This directory contains examples of how to obtain compilation time in UNIX integer format in a C++ program. Two methods are shown:

- Using a compilation flag, in *CompilationTime_BuildFlag*
- Using only macros of *__TIME__* and *__DATE__*, in *CompilationTime_PureMacro*.

The examples for both methods are projects written using the Platformio IDE with Visual Studio Code. The source code is available in the *src* folder of each project.

For the method relying on a compilation build flag, the build flag is set in the *platformio.ini* configuration file. If you use a different IDE / compilation tool, you will need to set the compilation flag accordingly.
