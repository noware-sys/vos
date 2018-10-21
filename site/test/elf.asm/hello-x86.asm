; Hello World Program - asmtutor.com
; Compile with: nasm -f elf -o helloworld.o helloworld.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 -o helloworld.elf helloworld.o
; To link as 64 bit, use elf_i386: ld -m elf_i386 -o helloworld.elf helloworld.o
; Run with: ./helloworld.elf

SECTION .data
msg     db      'Hello World!', 0Ah

SECTION .text
global  _start

_start:
	mov     edx, 13			; number of bytes to write - one for each letter plus 0Ah (line feed character)
	mov     ecx, msg		; move the memory address of our message string into ecx
	mov     ebx, 1			; write to the STDOUT file
	mov     eax, 4			; set invokation to SYS_WRITE (kernel opcode 4)
	int     80h					; perform invokation to SYS_WRITE (kernel opcode 4)

	mov     ebx, 0			; return 0 status on exit - 'No Errors'
	mov     eax, 1			; set invokation to SYS_EXIT (kernel opcode 1)
	int     80h					; perform invokation to SYS_EXIT (kernel opcode 1)
