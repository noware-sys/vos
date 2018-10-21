#include <string>
#include <iostream>

#include <gdabah/distorm/distorm.h>
#include <gdabah/distorm/mnemonics.h>

int main (int argc, char * argv [], char * envp [])
{
	//using boost::any_cast;
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	std::cout << "argc [" << argc << "]" << std::endl;
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	
	/*
	if (argc < 2)
	{
		std::cout << "'" << argv [0] << "': usage: '" << argv [0] <<"' <instructions.txt>" << std::endl;
		
		return EXIT_FAILURE;
	}
	*/
	
	std::cout << std::hex;
	std::cout << std::showbase;
	
	_DInst decodedInstructions [8];
	_DecodeType dt = Decode32Bits;
	_CodeInfo ci;
	unsigned int decodedInstructionsCount;
	unsigned char const buf [34] =
	{
	    0xba, 0x0d, 0x00, 0x00,
	    0x00, 0xb9, 0xa4, 0x90,
	    0x04, 0x08, 0xbb, 0x01,
	    0x00, 0x00, 0x00, 0xb8,
	    0x04, 0x00, 0x00, 0x00,
	    0xcd, 0x80, 0xbb, 0x00,
	    0x00, 0x00, 0x00, 0xb8,
	    0x01, 0x00, 0x00, 0x00,
	    0xcd, 0x80
	};
	
	ci.code = buf;
	ci.codeLen = sizeof (buf);
	ci.codeOffset = 0x80;
	ci.dt = dt;
	ci.features = DF_NONE;
	
	decodedInstructionsCount = 0;
	
	
	// perform the decomposition
	distorm_decompose (&ci, decodedInstructions, 8, &decodedInstructionsCount);
	
	
	// display result
	std::cout << "decodedInstructions [" << decodedInstructionsCount << ']' << std::endl;
	std::cout << '{' << std::endl;
	
	for (unsigned int i = 0; i < decodedInstructionsCount; ++i)
	{
		std::cout << "  " << '[' << i << ']' << std::endl;
		std::cout << "  {" << std::endl;
		
		//std::cout << std::hex;
		
		std::cout << "    addr [" << decodedInstructions [i].addr << ']' << std::endl;
		std::cout << "    size [" << decodedInstructions [i].size << ']' << std::endl;
		std::cout << "    flags [" << decodedInstructions [i].flags << ']' << std::endl;
		std::cout << "    segment [" << decodedInstructions [i].segment << ']' << std::endl;
		std::cout << "    base [" << decodedInstructions [i].base << ']' << std::endl;
		std::cout << "    scale [" << decodedInstructions [i].scale << ']' << std::endl;
		std::cout << "    dispSize [" << decodedInstructions [i].dispSize << ']' << std::endl;
		std::cout << "    opcode [I_" << GET_MNEMONIC_NAME (decodedInstructions [i].opcode) << ']' << std::endl;
		
		//std::cout << std::dec;
		std::cout << "    ops " << '[' << 4 << ']' << std::endl;
		std::cout << "    {" << std::endl;
		for (unsigned short int i2 = 0; i2 < 4; ++i2)
		{
			std::cout << "      [" << i2 << ']' << std::endl;
			std::cout << "      {" << std::endl;
			
			//std::cout << std::hex;
			std::cout << "        type  [" << decodedInstructions [i].ops [i2].type << ']' << std::endl;
			std::cout << "        index [" << decodedInstructions [i].ops [i2].index << ']' << std::endl;
			std::cout << "        size  [" << decodedInstructions [i].ops [i2].size << ']' << std::endl;
			std::cout << "      }" << std::endl;
		}
		std::cout << "    }" << std::endl;
		
		std::cout << "    disp [" << decodedInstructions [i].disp << ']'  << std::endl;
		//std::cout << "    imm [" << decodedInstructions [i].imm << ']';
		std::cout << "    unusedPrefixesMask [" << decodedInstructions [i].unusedPrefixesMask << ']'  << std::endl;
		std::cout << "    meta [" << decodedInstructions [i].meta << ']' << std::endl;
		std::cout << "    usedRegistersMask [" << decodedInstructions [i].usedRegistersMask << ']' << std::endl;
		
		std::cout << "  }" << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << '}' << std::endl;
	
	//return EXIT_SUCCESS;
}
