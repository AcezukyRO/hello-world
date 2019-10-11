.data
nhap1: 		.asciiz "nhap so thu 1: "
nhap2:		.asciiz "nhap so thu 2: "
xuongdong:	.asciiz "\n"
so1lh:		.asciiz "so thu nhat lon hon \n"
so2lh:		.asciiz "so thu hai lon hon \n"
ketquacong:	.asciiz "ket qua phep cong: "
ketquatru:	.asciiz "ket qua phep tru: "
ketquanhan:	.asciiz "ket qua phep nhan: "
ketquachia:	.asciiz "ket qua phep chia: "

.text
main:
	#in ra man hinh thong bao nhap so thu nhat
	la $a0, nhap1
	li $v0, 4
	syscall
	
	#yeu cau nhap so thu nhat
	li $v0, 5
	syscall #nguoi dung se bat dau nhap, gia tri se duoc luu trong thanh ghi v0
	addi $t0, $v0, 0
	
	#in ra man hinh thong bao nhap so thu hai
	la $a0, nhap2
	li $v0, 4
	syscall
	
	#yeu cau nhap so thu hai
	li $v0, 5
	syscall #nguoi dung se bat dau nhap, gia tri se duoc luu trong thanh ghi v0
	addi $t1, $v0, 0
	#----------------------------------------------------------------------------------------------------------
	
	slt $s4, $t0, $t1 #so sanh so thu nhat be hon so thu hai, neu dung thi s4 = 1, sai thi s4 = 0
	beq $s4, $zero, printso1 #s4 = 0 (nghia la so thu 2 < so thu 1), in so thu 1 lon hon
	la $a0, so2lh #neu khong thi in so thu 2 lon hon
	li $v0, 4
	syscall
	j tieptuc
printso1:
	#in ra man hinh thong bao so thu 2 lon hon
	la $a0, so1lh
	li $v0, 4
	syscall
	
tieptuc:
	#----------------------------------------------------------------------------------------------------------
	#in ra man hinh cau kq cong
	la $a0, ketquacong
	li $v0, 4
	syscall
	
	#cong hai so va in ket qua phep cong
	add $s0, $t0, $t1
	li $v0, 1 #in so moi nhsp
	add $a0, $s0, $zero #co the viet duoi lenh "li" vi khi goi syscall, no se kiem tra trong thanh ghi a0
	syscall 
	
	#xuong dong
	la $a0, xuongdong
	li $v0, 4
	syscall
	
	#----------------------------------------------------------------------------------------------------------
	
	#in ra man hinh cau kq tru
	la $a0, ketquatru
	li $v0, 4
	syscall
	
	#tru  hai so va in ket qua phep tru
	sub $s1, $t0, $t1
	li $v0, 1 #in so moi nhsp
	add $a0, $s1, $zero #co the viet duoi lenh "li" vi khi goi syscall, no se kiem tra trong thanh ghi a0
	syscall 
	
	#xuong dong
	la $a0, xuongdong
	li $v0, 4
	syscall
	
	#----------------------------------------------------------------------------------------------------------
	#in ra man hinh cau kq nhan
	la $a0, ketquanhan
	li $v0, 4
	syscall
	addi $t3, $zero, 0 #khai bao i
	
loop:	#nhan co nghia la cong voi chinh no chung nay lan
	beq $t3,$t1,printnhan
	add $s2,$s2, $t0
	addi $t3, $t3, 1
	j loop
	
printnhan: #in ket qua phep nhan
	li $v0, 1 #in so moi nhsp
	add $a0, $s2, $zero #co the viet duoi lenh "li" vi khi goi syscall, no se kiem tra trong thanh ghi a0
	syscall 
	
	#xuong dong
	la $a0, xuongdong
	li $v0, 4
	syscall
	
	#----------------------------------------------------------------------------------------------------------
	#in ra man hinh cau kq nhan
	la $a0, ketquachia
	li $v0, 4
	syscall
	addi $s3, $zero,, 0 #khai bao ket qua phep chia
	addi $t5, $t0, 0 #cho so thu nhat = t5
	
loop2:	#ket qua phep chia la so lan so thu nhat tru cho so thu 2 cho toi khi so thu nhat bang 0
	beq $t5, $zero, printchia
	sub $t5, $t5, $t1
	addi $s3, $s3, 1
	j loop2
	
printchia: #in ket qua phep nhan
	li $v0, 1 #in so moi nhsp
	add $a0, $s3, $zero #co the viet duoi lenh "li" vi khi goi syscall, no se kiem tra trong thanh ghi a0
	syscall 
	
end:
	li $v0, 10 #ket thuc chuong trinh
	syscall
	