If you run `make asm`, the makefile will put Assembly files here. It will
attempt to pipe the Assembly through c++filt in order to demangle the C++
symbols, so if you want to run `make asm`, make sure you have c++filt
installed on your machine. The Assembly uses Intel syntax because that's
my personal preference; delete `-masm=intel` from the makefile if you for
whatever reason prefer GNU syntax. It will produce Assembly optimized with
the option -O3 so that it will reflect the actual binary that is executed
when you run `make run`. To delete the Assembly files run `make clean-asm`.
