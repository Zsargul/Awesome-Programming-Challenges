while True: # Continues until program is ended
	arab = int(input("Please enter a number from 1-3999 (inclusive), or 0 to end: ")) # Arabic numerals aka what we usually use
	while (arab > 3999) or (arab < 0): # There are symbols for bigger numbers but they require a line above the character
		print("Invalid input.");
		arab = int(input("Please enter a number between 1 and 3999, or 0 to end: "))
	if (arab == 0):
		break
	else:
		while (arab > 0):
			if (arab >= 1000):
				print("M", end="")
				arab -= 1000
			elif (arab >= 900):
				print("CM", end="")
				arab -= 900
			elif (arab >= 500):
				print("D", end="")
				arab -= 500
			elif (arab >= 400):
				print("CD", end="")
				arab -= 400
			elif (arab >= 100):
				print("C", end="")
				arab -= 100
			elif (arab >= 90):
				print("XC", end="")
				arab -= 90
			elif (arab >= 50):
				print("L", end="")
				arab -= 50
			elif (arab >= 40):
				print("XL", end="")
				arab -= 40
			elif (arab >= 10):
				print("X", end="")
				arab -= 10
			elif (arab == 9):
				print("IX", end="")# For 9 and 4 you finish immediately so technically you don't need the 'end=""'
				arab -= 9
			elif (arab >= 5):
				print("V", end="")
				arab -= 5
			elif (arab == 4):
				print("IV", end = "")# but I do it anyway for continuity
				arab -= 4
			else:
				print("I", end="")
				arab -= 1
		print("\n")
		#print(arab) Should be 0 at end, just making sure I didn't leave anything out
print("End.")
# M - 1000 | D - 500 | C - 100 | L - 50 | X - 10 | V - 5 | I - 1
