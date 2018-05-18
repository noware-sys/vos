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

# oprn #args ($ref #terms (*factor $ref val)*3)*3
# mov 2 (0 1 (1 1 edx) (0 0 null) (0 0 null)), (0 1 (1 0 0xd) (0 0 null) (0 0 null)), (0 0 (0 0 null) (0 0 null) (0 0 null))
#sed -E -e 's/[[:blank:]]+/ /g' -e 's/[^[:blank:]]*[[:blank:]][^[:blank:]]*[[:blank:]]//' "${1}" 1> "${2}";
#cut --fields=1 --delimiter=' ' "${1}" 1> "${2}";
#cat <( cut --fields=1 --delimiter=' ' instr.2.test.txt ) <( cut --fields=2 --delimiter=' ' instr.2.test.txt | cut --fields=1 --delimiter=',' - )

> "${2}";

while IFS='' read -r line
do
	operation=$(echo "${line}" | cut --fields=1 --delimiter=' ' -);
	echo -n -e "${operation}" >> "${2}";
	
	echo -n -e "\n" >> "${2}";
done < "${1}"
