/*
   Gordon's Text-Utilities Library
   Copyright (C) 2009 Assaf Gordon (gordon@cshl.edu)

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Affero General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include <istream>
#include <sstream>

#include "text_line_reader.h"

using namespace std;


TextLineReader::TextLineReader(istream& _input_stream) :
	input_stream(_input_stream), current_line_number(0)
{
}

bool TextLineReader::next_line() 
{
	current_line_number++;
	getline(input_stream, current_line_string ) ;

	current_line_stream.str( current_line_string ) ;
	current_line_stream.seekg(0, ios_base::beg );
	current_line_stream.clear();
	
	if (input_stream.eof())
		return false;

	return input_stream ;
}
