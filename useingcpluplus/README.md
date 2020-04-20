# Mixing with C++

##Contents of file `mymod_stubs.cc`:

```c
#include <iostream>
#include <string>
extern "C" {
#include <caml/memory.h> #include <caml/mlvalues.h> 
}
extern "C" value my_hello_cc (value v_str) { CAMLparam1 (v_str);
std::cout << "Hello " << String_val(v_str) << "!\n";
CAMLreturn (Val_unit); }
Contents of file mymod.ml:
external my_hello: string -> unit = "my_hello_cc"
Contents of file caller.ml:
let _ =
Mymod.my_hello "Blue Camel";
;;
```

compile to native code with:

```sh
g++ -o mymod_stubs.o -I`ocamlc -where` -c mymod_stubs.cc ocamlopt -c mymod.ml
ocamlmklib -o mymod mymod_stubs.o
ocamlmklib -o mymod mymod.cmx
ocamlopt -I . -cclib -lstdc++ mymod.cmxa caller.ml -o caller.opt
```
then call it:

```sh
% ./caller.opt Hello Blue Camel!
now the compilation for bytecode:
g++ -o mymod_stubs.o -I`ocamlc -where` -c mymod_stubs.cc ocamlc -c mymod.ml
ocamlmklib -o mymod -lstdc++ mymod_stubs.o
ocamlmklib -o mymod mymod.cmo
ocamlc -I . mymod.cma caller.ml -o caller.byte
```

then call it:

```sh
% ocaml mymod.cma caller.ml Hello Blue Camel!
% ocamlrun -I . caller.byte Hello Blue Camel!
```

This section about C++ was greatly inspired by the tutorial by Anne Pacalet (in French) which you can find on one of these web page:
http://anne-pacalet.developpez.com/tutoriels/ocaml/interface-c-ou-cpp-et-ocaml/ http://www-sop.inria.fr/everest/personnel/Anne.Pacalet/camltop.php