00000000  BA0D000000        mov edx,0xd
00000005  B9A4900408        mov ecx,0x80490a4
0000000A  BB01000000        mov ebx,0x1
0000000F  B804000000        mov eax,0x4
00000014  CD80              int 0x80
00000016  BB00000000        mov ebx,0x0
0000001B  B801000000        mov eax,0x1
00000020  CD80              int 0x80

root@Portable:/root> readelf -a '/root/Projects/NoWare/vos/site/test/elf.cxx/asm/hello';
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x8048080
  Start of program headers:          52 (bytes into file)
  Start of section headers:          456 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         2
  Size of section headers:           40 (bytes)
  Number of section headers:         6
  Section header string table index: 5

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        08048080 000080 000022 00  AX  0   0 16
  [ 2] .data             PROGBITS        080490a4 0000a4 00000d 00  WA  0   0  4
  [ 3] .symtab           SYMTAB          00000000 0000b4 0000b0 10      4   7  4
  [ 4] .strtab           STRTAB          00000000 000164 00003d 00      0   0  1
  [ 5] .shstrtab         STRTAB          00000000 0001a1 000027 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x000000 0x08048000 0x08048000 0x000a2 0x000a2 R E 0x1000
  LOAD           0x0000a4 0x080490a4 0x080490a4 0x0000d 0x0000d RW  0x1000

 Section to Segment mapping:
  Segment Sections...
   00     .text 
   01     .data 

There is no dynamic section in this file.

There are no relocations in this file.

The decoding of unwind sections for machine type Intel 80386 is not currently supported.

Symbol table '.symtab' contains 11 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 08048080     0 SECTION LOCAL  DEFAULT    1 
     2: 080490a4     0 SECTION LOCAL  DEFAULT    2 
     3: 00000000     0 FILE    LOCAL  DEFAULT  ABS hello.asm
     4: 080490a4     0 NOTYPE  LOCAL  DEFAULT    2 msg
     5: 00000000     0 FILE    LOCAL  DEFAULT  ABS 
     6: 080490a4     0 OBJECT  LOCAL  DEFAULT    2 _GLOBAL_OFFSET_TABLE_
     7: 08048080     0 NOTYPE  GLOBAL DEFAULT    1 _start
     8: 080490b1     0 NOTYPE  GLOBAL DEFAULT    2 __bss_start
     9: 080490b1     0 NOTYPE  GLOBAL DEFAULT    2 _edata
    10: 080490b4     0 NOTYPE  GLOBAL DEFAULT    2 _end

No version information found in this file.


root@Portable:/root/Projects/NoWare/vos/site/test/elf.cxx/asm> objdump -d -M intel '/root/Projects/NoWare/vos/site/test/elf.cxx/asm/hello';

/root/Projects/NoWare/vos/site/test/elf.cxx/asm/hello:     file format elf32-i386


Disassembly of section .text:

08048080 <_start>:
 8048080:	ba 0d 00 00 00       	mov    edx,0xd
 8048085:	b9 a4 90 04 08       	mov    ecx,0x80490a4
 804808a:	bb 01 00 00 00       	mov    ebx,0x1
 804808f:	b8 04 00 00 00       	mov    eax,0x4
 8048094:	cd 80                	int    0x80
 8048096:	bb 00 00 00 00       	mov    ebx,0x0
 804809b:	b8 01 00 00 00       	mov    eax,0x1
 80480a0:	cd 80                	int    0x80


???:
mov [b...] (dest):
bf
be
bd
bc
bb ebx
ba edx
b9 ecx
b8 eax
b7 
b6
b5
b4
b3
b2
b1
b0
