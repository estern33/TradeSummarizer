# TradeSummarizer
Compiled Using The Following:<br>
CMake Version 3.15.3<br>
gcc version 7.4.0 (GCC) - filesystem header is included under experimental, 8.3 is still under test in Cygwin<br>
Project was build using CLion under the Cygwin64 environment version 3.1.2. <br>
The build process clones google test from git.  Internet access is required.  <br>

Build output should produce a google test unit test suite as an executable, UnitTests.exe.  The unit tests require read / write access to the build dir in order to test reading and writing the sample provided in instructions.txt.<br><br>
The main executable is TradeSummarizer.exe and takes one parameter, the path to the input file.  The output file will be written to output.csv in the working directory.

Many notes and assumptions can be found in main.cc.