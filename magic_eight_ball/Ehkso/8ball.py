# Submission for the Magic 8-ball challenge, July 6th 2022
# - Ehkso


import random # Random Responses
import time # Waiting
import os # Clearing screen
# Neither the time nor the os libraries are acutally necessary, however I use them to make my program pretty

#https://magic-8ball.com/magic-8-ball-answers/
# List of 8 ball answers for reference, I just took all the possible responses and wrote them into a list
# I alternated Affirmative/Noncommital/Negative, but due to the 8-ball having 20 responses in a 2:1:1 (10-5-5)
# split, the list has 5 consecutive affirmative answers at the end.

response = ["It is certain", "Reply hazy, try again", "Don't count on it", "It is decidedly so", "Ask again later",
			"My reply is no", "Without a doubt", "Better not tell you now", "My sources say no", "Yes definitely",
			"Cannot predict now", "Outlook not so good", "You may rely on it", "Concentrate and ask again",
			"Very doubtful", "As I see it, yes", "Most likely", "Outlook good", "Yes", "Signs point to yes"]

def eb(num): # My 8-ball function, just makes the triangle flip to simulate the ball shaking and "thinking"
	if (num == 0):
		print("::::::::::::::::::::::::::::::::::::::::")# 40 (counting just for myself)
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::oo   %   oo:::::::::::::::")
		print("::::::::::::oo    %%%    oo:::::::::::::")
		print(":::::::::::o     %%%%%     o::::::::::::")
		print(":::::::::::o    %%%%%%%    o::::::::::::")
		print(":::::::::::o   %%%%%%%%%   o::::::::::::")
		print("::::::::::::o%%%%%%%%%%%%%o:::::::::::::")
		print("::::::::::::::oo       oo:::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
	elif (num == 1) or (num == 3):
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::oo       oo:::::::::::::::")
		print("::::::::::::oo           oo:::::::::::::")
		print(":::::::::::o               o::::::::::::")
		print(":::::::::::o               o::::::::::::")
		print(":::::::::::o               o::::::::::::")
		print("::::::::::::o             o:::::::::::::")
		print("::::::::::::::oo       oo:::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
	elif (num == 2):
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::oo       oo:::::::::::::::")
		print("::::::::::::oo%%%%%%%%%%%oo:::::::::::::")
		print(":::::::::::o   %%%%%%%%%   o::::::::::::")
		print(":::::::::::o    %%%%%%%    o::::::::::::")
		print(":::::::::::o     %%%%%     o::::::::::::")
		print("::::::::::::o     %%%     o:::::::::::::")
		print("::::::::::::::oo   %   oo:::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
	elif (num == 4): # Magic 8-ball is watching you
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::oo   %   oo:::::::::::::::")
		print("::::::::::::oo    %%%    oo:::::::::::::")
		print(":::::::::::o     %% %%     o::::::::::::")
		print(":::::::::::o    %% o %%    o::::::::::::") # pranked
		print(":::::::::::o     %% %%     o::::::::::::")
		print("::::::::::::o     %%%     o:::::::::::::")
		print("::::::::::::::oo   %   oo:::::::::::::::")
		print("::::::::::::::::ooooooo:::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")
		print("::::::::::::::::::::::::::::::::::::::::")

fin = 0 # Checks if the while loop should 'finish', basically an empty variable though since I just 
first = 1 # Just checks if it's the first question, not really important but once again just a nicety.
while fin != 1:
	os.system("cls") # Clears screen
	eb(0)
	print("") # I do these instead of beginning a sentence with a newline because I want to.
	if (first == 1): # Yeah that's all I used it for lol, I could've done fin and first as one variable but for clarity
		inp = input("Ask your question: ")
	else: # Because I'd be looking at something else while the ball spins and then miss the prediction
		print("Previous question: " + inp)
		print("Previous answer: " + response[rnum-1] + "\n")
		inp = input("Ask your question, or say 'Thank you 8' to exit.\n\n")
	
	if (inp == "Thank you 8"): # Exit clause
		fin = 1
	else: # Do the stuff
		rnum = random.randint(1, 21)
		for i in range(1, (rnum * 5)): # Cycles 8-ball, range can be whatever but I like the idea of it possibly taking longer for a different answer
			for j in range(0,4): # Counts 0-3 inclusive
				os.system("cls")
				eb(j)
				print("\n" + inp)
				print("\nPondering...")
				#print(rnum) # Troubleshooting, to cross reference with list to make sure
				time.sleep(0.1) # Adjustable, I feel like this is fast enough but you can always shorten it
		
		os.system("cls")
		eb(2)
		print("\n" + inp + "\n\n" + response[rnum-1])
		time.sleep(5)
		first = 0 # No longer the first question after this

os.system("cls")
eb(4) # spoopy prenk
print("\nEnd.")