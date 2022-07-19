; FizzBuzz written in 32-bit NASM assembly
; 
; To run, type "./fizzbuzz"
;
; To compile, type the following in order:
; nasm -f elf fizzbuzz.asm
; ld -m elf_i386 -s -o fizzbuzz fizzbuzz.o
; ./fizzbuzz
;
section .data
	; fizzbuzz and title/end messages
	fizz		db "Fizz", 0xa		
	fizz_L		equ $-fizz

	buzz		db "Buzz", 0xa
	buzz_L		equ $-buzz

	fizzBuzz	db "FizzBuzz", 0xa
	fizzBuzz_L	equ $-fizzBuzz
	
	title		db "First 100 numbers in fizzbuzz:", 0xa
	title_L 	equ $-title

	endMsg		db "Finished", 0xa
	endMsg_L	equ $-endMsg

	; message displaying number
	cntrMsg		db "   ", 0xa

	; counter variable
	cntr		db 0

section .text
	global _start

_start:
	; Print title message
	mov 	eax, 4		; sys_write (print)
	mov 	ebx, 1		; sdtout
	mov 	ecx, title	; string
	mov	edx, title_L	; length of string
	int	0x80		; call kernel

	mov [cntr], byte 1
next:
	; Divide by 3
	mov	al, [cntr]	; move counter into al (8-bit eax/rax)
	xor	ah, ah		; set ah to zero (ah is always equal to itself so the result of this is always 0)
	mov	bl, 3		; mov 3 into bl (8-bit rbx/ebx)
	div	bl		; divide al by bl and put quotient into al and remainder in ah
	cmp	ah, 0		; check remainder i.e mod 3
	jne	not_f		; if the remainder is not 0, jump to not_f

	; If remainder is 0, continue, performing division by 5
	mov	al, [cntr]
	xor	ah, ah
	mov	bl, 5
	div	bl
	cmp	ah, 0
	jne	not_fb		; if number is divisible by 3 but not 5, go to not_fb

	; If number is divisible by both 3 and 5, print fizzbuzz
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, fizzBuzz
	mov	edx, fizzBuzz_L
	int	0x80 
	jmp	finished_number	; move onto next number

not_f:
	; Divide by 5
	mov	al, [cntr]
	xor	ah, ah
	mov	bl, 5
	div	bl
	cmp	ah, 0
	jne	not_f_or_b 	; if number isn't divisible by 3 or 5, move to not_f_or_b

	; If the number is divisible by 5, print "buzz"
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, buzz
	mov	edx, buzz_L
	int	0x80
	jmp	finished_number

not_fb:
	; Print "fizz", because number is divisible by 3 but not 5
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, fizz
	mov	edx, fizz_L
	int	0x80
	jmp	finished_number

not_f_or_b:
	mov	al, [cntr]
	xor	ah, ah
	mov	bl, 10		
	div	bl		; divide al by 10
	cmp 	al, 0		; check remainder to see if we have double-digit decimal number
	
	add	al, 48		
	mov	[cntrMsg], al
	add	ah, 48
	mov 	[cntrMsg+1], ah
	
	; Print number
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, cntrMsg
	mov	edx, 4	
	int	0x80

finished_number:
	add	[cntr], byte 1
	cmp	[cntr], byte 100
	jne	next		; If number isn't 100, continue looping

	; If loop has reached 100, finish program
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, endMsg
	mov	edx, endMsg_L
	int	0x80	

exit:
	; exit program
	mov	eax, 1		; sys_exit
	int	0x80		
