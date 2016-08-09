# Linux
1. Compile [safe_core](https://github.com/maidsafe/safe_core) to get `libsafe_core.so`.
2. Compile this C code as `gcc -O2 main.c -L/path/to/libsafe_core.so -lsafe_core -o test.out`
  - e.g. if you copied the shared object to pwd, then do `gcc -O2 main.c -L. -lsafe_core -o test.out`
3. Run the executable with `LD_LIBRARY_PATH=/path/to/libsafe_core.so ./test.out`
  - e.g. if you copied the shared object to pwd, then do `LD_LIBRARY_PATH=. ./test.out`
  - If the logging was initialised, you can also run as `RUST_LOG=trace LD_LIBRARY_PATH=. ./test.out` etc. for logs to show up from inside backend. This might however clobber the output of this C code. In that case comment out all the `printf's` here and re-build and run.
