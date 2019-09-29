import os
import re

def parse(filepath):


	raw_data = ''
	parsed_data = ''

	parsed_file_path = os.path.splitext(filepath)[0] + '_parsed.txt'


	with open(filepath, 'r', encoding="utf8") as start_file:

		raw_data = start_file.read()
	

	raw_data = ' '.join(raw_data.split())			# Substitute whitespace characters with spaces

	for symbol in raw_data:

		symbol = symbol.lower()
		matched = re.match(r'^[а-я0-9 ]$', symbol) 	# Only keep russian symbols and numbers

		if matched:

			parsed_data += matched.group(0)

	parsed_data = ' '.join(parsed_data.split())		# Substitute whitespace characters after filtering


	with open(parsed_file_path, 'w', encoding="utf8") as parsed_file:

		parsed_file.write(parsed_data)


	print('Text parsed to \'' + parsed_file_path + '\'')	



parse('text.txt')