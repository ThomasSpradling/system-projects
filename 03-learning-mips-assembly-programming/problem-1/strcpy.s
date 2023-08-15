# $s1 -> s1, $s2 -> s2
addiu $t0, $zero, 0 # i = 0

Loop:
  # address representation of i + s1 and i + s2
  addu $t1, $t0, $s1
  addu $t2, $t0, $s2

  # s2[i] = s1[i]
  lb $t3, 0($t1)
  sb $t3, 0($t2)

  beq $t3, $zero, Exit
  addiu $t0, $t0, 1
  j Loop
Exit: