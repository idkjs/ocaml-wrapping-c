external send_an_int: int => unit = "get_an_int";

let () = send_an_int(5);
let send_an_int = (int) = send_an_int(int);
