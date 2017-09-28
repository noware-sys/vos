#include <fstream>
#include <iostream> 
//#include <string>

#include "interpreter.hpp"
//#include "B:\Documents\Visual Studio Projects\NoWare (2013)\lexical_analyzer.cpp"
#include "lexical_analyzer.cpp"
//#include <lexical_analyzer.cpp>
//#include ""
//#include <>

#ifndef ENCODING_NAME
# define ENCODING_NAME (0x0)
#endif

LIB::cluster::interpreter::interpreter (void)
{

}

LIB::cluster::interpreter::~interpreter (void)
{

}

unsigned short int LIB::cluster::interpreter::enqueue (const std::string & file_name, std::queue <LIB::cluster::processor::instructions> & instructions_queue, std::string & error)
{
	/*
		0 success
		1 syntax error
	*/

	LIB::cluster::processor::instruction instruction_internal;
	LIB::cluster::processor::instructions instructions_internal;
	std::queue <LIB::cluster::processor::instructions> instructions_local;
	std::string error_internal;
	bool correct = true;
	bool serializing = false;
	bool valid_instruction;
	unsigned short int visits;
	std::string identifier, output;

	quex::Token * token_p = 0x0;
	// (*) create the lexical analyser
	//     1st arg: input file, default = 'example.txt'
	//     2nd arg: input character encoding name, 0x0 --> no codec conversion
	//quex::lexical_analyzer qlex (file_name, ENCODING_NAME);
	quex::lexical_analyzer qlex (file_name);

	//unsigned short int number_of_tokens = 0;

	do
	{
		// (*) get next token from the token stream
		qlex.receive (& token_p);

		//std::cout << "Current Token: " << token_p -> get_string () << ";" << std::endl;

		// (*) print out token information
		//std::cout << token_p -> type_id_name () << ": " << token_p -> pretty_char_text () << ": " << token_p -> get_number () << std::endl;

		//cout << "String: " << token_p -> get_string () << endl;

		switch (token_p -> type_id ())
		{
			case QUEX_TKN_SERIALIZE:
				// Get the next token.
				qlex.receive (& token_p);

				// ...it should be a left brace ({).
				if (token_p -> type_id () != QUEX_TKN_LEFT_BRACE)
				{
					error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Expected {, received " + token_p -> pretty_char_text ();

					return 1;
				}

				serializing = true;

				break;

			case QUEX_TKN_RIGHT_BRACE:
				if (serializing)
					serializing = false;
				else
				{
					error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unexpected character: }";

					return 1;
				}

				break;

			case QUEX_TKN_INCLUDE:
				// Now, parse the input file.

				// Get the next token.
				qlex.receive (& token_p);

				// ...it should be a double quote.
				if (token_p -> type_id () == QUEX_TKN_STRING_START)
				{
					std::string file_name_internal = "";

					qlex.receive (& token_p);

					while (token_p -> type_id () != QUEX_TKN_TERMINATION && token_p -> type_id () != QUEX_TKN_FAILURE && token_p -> type_id () != QUEX_TKN_STRING_END)
					{
						//if (token_p -> type_id () == QUEX_TKN_CHAR)
							file_name_internal += token_p -> pretty_char_text ();

						qlex.receive (& token_p);
					}
				/*
					do
					{
						qlex.receive (& token_p);

						if (token_p -> type_id () == QUEX_TKN_CHAR)
							file_name_internal += token_p -> pretty_char_text ();
					}
					while (token_p -> type_id () != QUEX_TKN_TERMINATION && token_p -> type_id () != QUEX_TKN_FAILURE && token_p -> type_id () != QUEX_TKN_STRING_END);
				*/	

					if (token_p -> type_id () == QUEX_TKN_STRING_END)
					{
						unsigned short int ret = enqueue (file_name_internal, instructions_local, error_internal);

						if (ret != 0)
						{
							error = error_internal;

							return ret;
						}
					}
					else if (token_p -> type_id () == QUEX_TKN_TERMINATION)
					{
						error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unexpected end of file";

						return 1;
					}
					else if (token_p -> type_id () == QUEX_TKN_FAILURE)
					{
						error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Expected \", received " + token_p -> pretty_char_text ();

						return 1;
					}
					else
					{
						error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unknown error";

						return 1;
					}
				}
				else
				{
					error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Expected \", received " + token_p -> pretty_char_text ();

					return 1;
				}

				break;

			case QUEX_TKN_OUTPUT:
				instruction_internal._operation = LIB::cluster::processor::operation::output;

				do
				{
					qlex.receive (& token_p);

					//std::cout << "Current Token O/P: " << token_p -> get_string () << ";" << std::endl;	// Temporary.

					valid_instruction = true;

					switch (token_p -> type_id ())
					{
						case QUEX_TKN_IDENTIFIER:
							instruction_internal.inputs [0] = token_p -> pretty_char_text ();

							break;
						case QUEX_TKN_ENDL:
							instruction_internal.inputs [0] = (std::string) "endl";

							break;
						case QUEX_TKN_STRING_START:
							output = "";

							qlex.receive (& token_p);

							while (token_p -> type_id () != QUEX_TKN_TERMINATION && token_p -> type_id () != QUEX_TKN_FAILURE && token_p -> type_id () != QUEX_TKN_STRING_END)
							{
								//if (token_p -> type_id () == QUEX_TKN_CHAR)
									output += token_p -> pretty_char_text ();

								qlex.receive (& token_p);
							}
							/*
							if (token_p -> type_id () == QUEX_TKN_STRING_END)
							{
								qlex.receive (& token_p);

								if (! token_p -> type_id () != QUEX_TKN_STATEMENT_END)
								{
									error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Expected ;, received " + token_p -> pretty_char_text ();

									return 1;
								}
							}
							else if (token_p -> type_id () == QUEX_TKN_TERMINATION)
							{
								error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unexpected end of file";

								return 1;
							}
							else if (token_p -> type_id () == QUEX_TKN_FAILURE)
							{
								error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Expected \", received " + token_p -> pretty_char_text ();

								return 1;
							}
							else
							{
								error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unknown error";

								return 1;
							}
							*/

							instruction_internal.inputs [0] = output;

							break;
						default:
							valid_instruction = false;
					}

					if (valid_instruction)
					{
						/*
							If we are parallizing,
							before we enqueue our local instruction to the instructions serialized set,
							we should take care of the current instruction serialized set,
							meaning that we should enqueue them, and we should clear them
						*/
						if (! serializing)
						{
							instructions_local.push (instructions_internal);
						
							//instructions_internal._instructions.
							while (! instructions_internal._instructions.empty ())
								instructions_internal._instructions.pop ();
						}

						instructions_internal._instructions.push (instruction_internal);
					}
				}
				while (token_p -> type_id () != QUEX_TKN_STATEMENT_END && token_p -> type_id () != QUEX_TKN_TERMINATION && token_p -> type_id () != QUEX_TKN_FAILURE);

				break;

			case QUEX_TKN_IDENTIFIER:
				identifier = token_p -> pretty_char_text ();
				visits = 0;

				do
				{
					//qlex.receive (& token_p);

					switch (token_p -> type_id ())
					{
						case QUEX_TKN_IDENTIFIER:
						case QUEX_TKN_NUMBER:
							if (visits > 0)
							{
								//std::cout << token_p -> pretty_char_text () << std::endl;
								instruction_internal.inputs [visits > 1 ? 1 : 0] = token_p -> pretty_char_text ();

								/*
								if (visits > 1)
								{
									instruction_internal.inputs [1] = identifier;
								}
								else
								{
									instruction_internal.inputs [0] = token_p -> pretty_char_text ();
								}
								*/
							}
							else
							{
								//instruction_internal.output = token_p -> pretty_char_text ();
								instruction_internal.output = identifier;
							}

							visits ++;

							break;
						
						case QUEX_TKN_ASSIGNMENT:
							//instruction_internal.output = token_p -> pretty_char_text ();
							instruction_internal._operation = LIB::cluster::processor::operation::assignment;

							break;

						case QUEX_TKN_ADDITION:
							instruction_internal._operation = LIB::cluster::processor::operation::addition;

							break;

						case QUEX_TKN_SUBSTRACTION:
							instruction_internal._operation = LIB::cluster::processor::operation::substraction;

							break;

						case QUEX_TKN_MULTIPLICATION:
							instruction_internal._operation = LIB::cluster::processor::operation::multiplication;

							break;

						case QUEX_TKN_DIVISION:
							instruction_internal._operation = LIB::cluster::processor::operation::division;

							break;

						case QUEX_TKN_MODULO:
							instruction_internal._operation = LIB::cluster::processor::operation::modulo;

							break;

						//case QUEX_TKN_STATEMENT_END:
						//	break;

						default:
							error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unexpected token: " + token_p -> pretty_char_text ();

							return 1;
					}

					qlex.receive (& token_p);
				}
				while (token_p -> type_id () != QUEX_TKN_STATEMENT_END && token_p -> type_id () != QUEX_TKN_TERMINATION && token_p -> type_id () != QUEX_TKN_FAILURE);

				if (! serializing)
				{
					instructions_local.push (instructions_internal);
						
					//instructions_internal._instructions.
					while (! instructions_internal._instructions.empty ())
						instructions_internal._instructions.pop ();
				}

				instructions_internal._instructions.push (instruction_internal);
				
				break;

			default:
				//error = file_name + ": " + std::to_string ((long long int) token_p -> line_number ()) + ": " + std::to_string ((long long int) token_p -> column_number ()) + ": Unexpected character: " + token_p -> pretty_char_text ();

				//return 1;
				break;
		}

		if (token_p -> type_id () == QUEX_TKN_FAILURE)
		{
			correct = false;
			
			break;
		}

		//++number_of_tokens;
	}
	// (*) check against 'termination'
	while (token_p -> type_id () != QUEX_TKN_TERMINATION /*&& token_p -> type_id () != QUEX_TKN_FAILURE*/);

	if (correct)
	{
		instructions_local.push (instructions_internal);	// Add the last set of instruction.

		while (! instructions_local.empty ())
		{
			instructions_queue.push (instructions_local.front ());
			instructions_local.pop ();
		}
	}

	return correct ? 0 : 1;
}
