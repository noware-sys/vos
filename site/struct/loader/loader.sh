#! /bin/bash

set -e;

if test $# -lt 1
then
	echo "${0}"': usage: '"${0}"' <in:exe.elf>'
	exit 1;
fi

elf="${1}";
extractor='/root/Projects/NoWare/mach.noware.cxx/site/struct/loader/extractor.sh';
loader='/root/Projects/NoWare/mach.noware.cxx/site/struct/loader/main.elf';

#"${extractor}" "${elf}" "${elf}"'-store.txt' "${elf}"'-cpu-insn.txt';
#"$loader" "$elf"'-store.txt' "$elf"'-cpu-insn.txt';
"${extractor}" "${elf}"'-ram.txt' "${elf}";
"${loader}" "${elf}"'-ram.txt';
