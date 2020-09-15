# Written for the Python Challenge
# Gets a string from the user, asks for a letter shift 
# (i.e. a = c would be +2), and decodes the string.

new_str = ""

cypher = input("Enter string: ")
shift = int(input("Enter integer value for shift: "))

# convert negative shift
if shift < 0:
	shift += 26

for letter in cypher:

	# check capitalized letters
	if 65 <= ord(letter) + shift <= 90:
		new_str += chr(ord(letter) + shift)
	# check lowercase letters
	elif 97 <= ord(letter) + shift <= 122:
		new_str += chr(ord(letter) + shift)
	# check if we need to loop
	elif 90 < ord(letter) + shift < 97 or 122 < ord(letter) + shift:
		new_str += chr(ord(letter) + shift - 26)
	# else, do nothing
	else:
		new_str += chr(ord(letter))

print(new_str)