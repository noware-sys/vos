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

# # mov 2 (0 1 (1 1 edx) (0 0 null) (0 0 null)), (0 1 (1 0 0xd) (0 0 null) (0 0 null)), (0 0 (0 0 null) (0 0 null) (0 0 null))
# mov   2  0 1  1 1 edx   0 0 null   0 0 null  ,  0 1  1 0  13   0 0 null   0 0 null  ,  0 0  0 0 null   0 0 null   0 0 null
# mov   2  0 1 1 1 edx 0 0 null 0 0 null 0 1 1 0 0xd 0 0 null 0 0 null 0 0 0 0 0 null 0 0 null 0 0 null

> "${2}";

while IFS= read -r line
do
	operation=$(echo "${line}" | cut --fields=1 --delimiter=' ' -);
	echo -n -e "${operation}" >> "${2}";
	
	arg_ndx=0;
	args=$(echo "${line}" | grep -o ',' - | wc --lines);
	#echo -n -e " args:${args}";
	#exit;
	#arg_1=$(cut --fields=2 --delimiter=' ' ${1} | cut --fields=1 --delimiter=',' -);
	arg_1=$(echo "${line} " | cut --fields=2 --delimiter=' ' -);
	if test -n "${arg_1}"
	then
		# at least 1 argument
		args=$(( args + 1 ));
	fi
	echo -n -e " ${args}" >> "${2}";
	while test ${arg_ndx} -lt ${args}
	do
		arg_ndx=$(( arg_ndx + 1 ));
		arg_orig=$(echo "${line} " | cut --fields=2 --delimiter=' ' - | cut --fields="${arg_ndx}" --delimiter=',' -);
		arg=$(echo "${arg_orig}" | sed -e 's/\[//g' -e 's/\]//g' -);
		if test "${arg_orig:0:1}" = '['
		then
			# memory reference
			echo -n -e " 1" >> "${2}";
		else
			# literal
			echo -n -e " 0" >> "${2}";
		fi
		
		echo -n -e "\n      arg:${arg}\n";
		echo -n -e "   arg_orig[0]:${arg_orig:0:1}\n";
		term_ndx=0;
		terms=$(echo "${arg}"| grep -o '+' - | wc --lines);
		terms=$(( terms + 1 ));
		echo -n -e " ${terms}" >> "${2}";
		echo -n -e "    terms:${terms}\n";
		while test ${term_ndx} -lt ${terms}
		do
			term_ndx=$(( term_ndx + 1 ));
			term=$(echo "${arg}" | cut --fields="${term_ndx}" --delimiter='+' -);
			
			factor=$(echo "${term}" | cut --fields=1 --delimiter='*' -);
			reg=$(echo "${term}*" | cut --fields=2 --delimiter='*' -);
			
			
			echo -n -e "  arg_ndx:${arg_ndx}\n";
			echo -n -e " term_ndx:${term_ndx}\n";
			echo -n -e "     term:${term}\n";
			#echo -n -e "   factor:${factor}\n";
			#echo -n -e "  reg-pre:${reg}\n";
			
			if test -z "${reg}"
			then
				reg="${factor}";
				factor=1;
			fi
			
			echo -n -e " ${factor}" >> "${2}";
			# a hex nr
			if [ "$(echo "${reg}" | cut --characters=2 -)" = 'x' ]
			then
				# literal
				echo -n -e " 0" >> "${2}";
			else
				# register reference
				echo -n -e " 1" >> "${2}";
			fi
			echo -n -e " ${reg}" >> "${2}";
		done
		
		# pad
		while test ${term_ndx} -lt 3
		do
			term_ndx=$(( term_ndx + 1 ));
			echo -n -e " 0 0 null" >> "${2}";
		done
	done
		
	# pad
	while test ${arg_ndx} -lt 3
	do
		arg_ndx=$(( arg_ndx + 1 ));
		
		# pad
		echo -n -e " 0 0" >> "${2}";
		term_ndx=0;
		while test ${term_ndx} -lt 3
		do
			term_ndx=$(( term_ndx + 1 ));
			echo -n -e " 0 0 null" >> "${2}";
		done
	done
	
	echo -n -e "\n" >> "${2}";
done < "${1}"
