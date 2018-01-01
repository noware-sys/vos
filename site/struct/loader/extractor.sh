#! /bin/bash

if test $# -lt 4
then
	echo "${0}"': usage: '"${0}"' <exe.elf> <store.txt> <cpu-instr.txt>'
	exit 1;
fi

elf="${1}";
store="${2}";
cpu="${3}";
extractor_store='/root/Projects/NoWare/mach.noware.cxx/site/struct/extractor.store/main.elf';
extractor_cpu_1='/root/Projects/NoWare/mach.noware.cxx/site/struct/extractor.cpu/main.elf';
extractor_cpu_2='/root/Projects/NoWare/mach.noware.cxx/src/vmach/cpu/extractor.2.sh';
extractor_cpu_3='/root/Projects/NoWare/mach.noware.cxx/src/vmach/cpu/extractor.3.sh';

$extractor_store "$elf" 						"${store}";
$extractor_cpu_1 "$elf" 						"$elf"'-cpu.1.txt';
$extractor_cpu_2 "$elf"'-cpu.1.txt' "$elf"'-cpu.2.txt';
$extractor_cpu_3 "$elf"'-cpu.2.txt' "$cpu";
