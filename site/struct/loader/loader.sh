#! /bin/bash

if test $# -lt 2
then
	echo "${0}"': usage: '"${0}"' <exe.elf>'
	exit 1;
fi

elf="${1}";
extractor='/root/Projects/NoWare/mach.noware.cxx/site/struct/loader/extractor.sh';
loader='/root/Projects/NoWare/mach.noware.cxx/site/struct/loader/main.elf';

"$extractor" "$elf" "$elf"'-store.txt' "$elf"'-cpu-instr.txt';
"$loader" "$elf"'-store.txt' "$elf"'-cpu-instr.txt';
