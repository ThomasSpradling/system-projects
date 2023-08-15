Fib:
  # base case
  beq $a0, $zero, L0  # if a0 = 0, go to L0

  add $t1, 1, $zero   # let t1 = 1
  beq $a0, $t1, L1    # if a0 = t1, got to L1


  add $t0, $a0, $a1   # get address of n-th index of cache
  lw $t1, 0($t0)      # t1 = cache[n]
  bne $t1, $zero, L2

  # fill stack
  sub $sp, $sp, 12
  sw $a0, 0($sp)
  sw $a1, 4($sp)
  sw $ra, 8($sp)
  
  # let first argument be n - 1
  sub $a0, $a0, 1
  jal Fib
  add $s0, $v0, $zero   # s = fib(n - 1, cache)

  sub $a0, $a0, 1
  jal Fib
  add $s0, $s0, $v0     # s += fib(n - 2, cache)

  addi $a0, $a0, 2       # reset n back to itself via n <- n + 2

  add $t0, $a0, $a1     # get address of n-th index of cache 
  sw $s0, 0($t0)        # cache[n] = s

  add $v0, $zero, $s0

  # pop stack
  lw $ra, 8($sp)
  lw $a1, 4($sp)
  lw $a0, 0($sp)
  add $sp, $sp, 12
  jr $ra

L0:
  addi $v0, $zero, 0
  jr $ra

L1:
  addi $v0, $zero, 1
  jr $ra

L2:
  addi $v0, $t1, 0
  jr $ra
