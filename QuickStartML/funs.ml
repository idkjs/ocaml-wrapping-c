
external _send_an_int: int -> unit = "get_an_int"

let () = _send_an_int 5
let send_an_int int = _send_an_int int