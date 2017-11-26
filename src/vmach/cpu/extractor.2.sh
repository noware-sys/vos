#! /bin/bash

if test $# -lt 2
then
	echo "${0}::usage: ${0} <instructions.txt> <output.txt>";
	exit 1;
fi

#$entry=$(readelf "${1}" | grep "Entry point address:" - | cut --fields=20 --delimiter=' ' -);

# 0x8048080
# 80 80 04 08
# 08 04 80 80
# 08048080

sed -E -e 's/[[:blank:]]+/ /g' -e 's/[^[:blank:]]*[[:blank:]][^[:blank:]]*[[:blank:]]//' "${1}" 1> "${2}";
