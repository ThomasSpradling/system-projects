# let $s0 -> a, $s1 -> b, $a0 -> c
main:
  addi $s0, $zero, 6  # a = 6
  addi $s1, $zero, 7  # b = 7
  add $a0, $s0, $s1   # c = a + b

  li   $v0, 1         # system call code for print_int
  syscall
  
  # Exit the program
  li   $v0, 10        # system call code for exit
  syscall
