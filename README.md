# Hello World

The two files "hello.ml" and "hello_stubs.c":
external print_hello: unit -> unit = "caml_print_hello"

```ml
let () =
  print_hello ()
#include <stdio.h>
#include <caml/mlvalues.h>
```

```c
CAMLprim value
caml_print_hello(value unit)
{
    printf("Hello\n");
    return Val_unit;
}
```

Compile and run:

```sh
$ ocamlopt -o hello.opt hello.ml hello_stubs.c
$ ./hello.opt 
Hello
```
Compile and run:

```sh
$ ocamlopt -o hello.opt -pp "refmt -p ml" -impl hello.re hello_stubs.c
$ ./hello.opt 
Hello
```
# Quick Start

The two files "hello.ml" and "hello_stubs.c":
external print_hello: unit -> unit = "caml_print_hello"

```re
external send_an_int: int => unit = "get_an_int";
```

```c
CAMLprim value
caml_print_hello(value unit)
{
    printf("Hello\n");
    return Val_unit;
}
```

Compile and run:

```sh
$ ocamlopt -o hello.opt hello.ml hello_stubs.c
$ ./hello.opt 
Hello
```
Compile and run:

```sh
$ ocamlopt -o main.opt -pp "refmt -p ml" -impl main.re main_stubs.c
$ ./main.opt 
Hello
```


You also have the option, if you just want to build a C-OCaml mixed application without to build an intermediate .cma / .cmxa binding, to directly compile the objects together:
```
make wrap.o
make funs.cmx
ocamlopt wrap.o funs.cmx -o myapp
./myapp
```