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
let _ = Mymod.my_hello "Blue Camel";
;;