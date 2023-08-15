# $a0 = head
# $a1 = f

Map:
  # loading args into stack
  addi $sp, $sp, -12
  sw $a0, 0($sp)
  sw $a1, 4($sp)
  sw $ra, 8($sp)

  beq $a0, $zero, Exit  # if head == NULL, exit
  
  add $s0, $a0, $zero
  lw $t1, 0($a0)  # head->value
  lw $s2, 4($a0)  # head->next
  # head->value = f(head->value)
  add $a0, $t1, $zero # a = head->value
  jalr $a1            # jump to f
  sw $v0, 0($s0)      # set head->value to be the return value of f
  
  add $a0, $s2, $zero # set a = head->next
  jal Map               # jump back to top new value of a

  # popping args from stack
  lw $ra, 8($sp)
  lw $a1, 4($sp)
  lw $a0, 0($sp)
  addi $sp, $sp, 12
  
Exit:
  jr $ra