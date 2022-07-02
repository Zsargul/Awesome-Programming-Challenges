# About

A list of simple programming challenges that are not only good for beginners, but fun for intermediate/experienced coders. Anyone is welcome to code their own solutions and submit them here! 

Anyone can:
- Take any approach and use any language you wish to solve the challenges. 
- Solve challenges that have already been solved by somebody else
- Submit ideas for new challenges or changes to the list

As mentioned above, each challenge can be solved multiple times by multiple people, as the goal of this list is not to solve every single challenge listed, but rather to have the people solving them learn something new and get better at coding. So if there's a challenge which you want to take a shot at, but someone else has already coded a solution for it, then you don't need to worry about it.

This repository is also a great way to make your first __pull requests__. If you do not know how to contribute to a Github reposity, see our steps [here](#How-to-contribute).

### Tips:

- If a problem is too easy, choose a language you are unfamiliar with to spice things up!
- If you get stuck or overwhelmed, don't become discouraged. Simplify your problem! Use pen and paper, help yourself understand and/or visualise your problem.
- Remember that [Stackoverflow](https://stackoverflow.com/) and Google are your best troubleshooting companions. If you are facing a programming-related issue now, chances are, someone in the past also has!
- Don't be afraid to write terrible code. If anything, *this* is the repository to do it!

## CHALLENGES:

Due to the fact that the difficulty of each task is VERY subjective, the challenges are not categorized by difficulty.

| Challenge                           | Folder name              | Description													    	       |
|-------------------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------------------------|
| Towers of Hanoi                     | towers_of_hanoi          | Simple towers of Hanoi puzzle using 3 rods and N disks.							    	       |
| Random sentence generator           | sentence_generator       | Simple random sentence generator. Can be pseudorandom, use a Markov Chain, and so on.			    	       |
| Simple Calculator                   | calculator               | Simple calculator that uses basic arithmetic functions such as +, -, /, etc.					       |
| Calculate first N digits of Pi      | pi_calculator            | Calculate and print the first N digits of pi, or  just print the Nth digit.					       |
| Image to ASCII art                  | image_to_ascii           | Algorithm for converting an image to ASCII art.									       |
| Temperature converter               | temperature_converter    | Convert temperature values to and from various units.								       |
| Fizzbuzz                            | fizzbuzz                 | Simple programming task often asked at job interviews.								       |
| Base converter     		      | base_converter           | Convert to and from binary/octal/decimal/hexadecimal etc.								       |
| Port scanner        		      | port_scanner             | Simple program that probes a host for open ports.									       |
| RPN Calculator      		      | rpn_calculator           | Like a regular calculator, but using RPN (Reverse polish Notation).							       |
| ASCII Digital Clock		      | ascii_clock              | Digital clock that displays the time in ASCII.									       |
| Snake              	 	      | snake                    | Simple snake game.													       |
| Rock Paper Scissors		      | rock_paper_scissors      | Basic Rock Paper Scissors game.											       |
| Eulerian Path			      | eulerian_path            | See [the following](https://www.geeksforgeeks.org/eulerian-path-and-circuit/)	  				       |
| Draw a spinning 3D cube             | spinning_cube            | Drawing spinning 3-Dimensional shapes                                                                                       |
| Highest prime factor calculator     | hpf_calculator           | Find the highest prime factor of a given number N                                                                           |
| Password Generator                  | password_generator       | Simple password generator. Bonus for allowing user customization options such as special or upper/lower-case characters. |
| Caesar Cipher encryption/decryption | ceasar_cipher            | Tool for encrypting & decrypting strings of text or other data using a Ceasar cipher.                                    |
| Benford's Law                       | benfords_law             | Given a list of numbers, find how closely the list follows [Benford's law](https://en.wikipedia.org/wiki/Benford%27s_law). The list of numbers can be any real-life set of numerical data.  |
| Youtube to MP3/MP4		      | youtube_downloader       | Tool for downloading MP3 and/or MP4 formats of Youtube videos 							       |
| Media downloader 		      | media_downloader         | Tool for downloading media (Images/Video/Audio) from the web, whether it be from Youtube, Instagram, Soundcloud etc.     |
| Text to Hex/Binary		      | text_converter	         | Convert text strings into numerical values represented in binary and/or hexadecimal.					       |
| Sierpiński Triangle 		      | sierpinski_triangle      | An algorithm which prints a [Sierpiński Triangle](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_triangle)		       |
| Basic Neural Network 		      | basic_neural_network     | A simple neural network with inputs and outputs. 									       |
| Count characters/word in a string   | word_char_counter        | Algorithm that counts the occurences of a word or single character in a given string.			      	       |
| Calculate Age in seconds	      | age_calculator	         | Convert a given age (in years) to seconds.										       |
| Non-Ceasar Cipher encryption/decryption | noncaesar_encryption | An encryption/decryption algorithm not using a caesar cipher shift technique.					       |
| Magic 8-Ball 			      | magic_eight_ball         | A simple magic 8-Ball that gives random responses when asked a question.						       |
| Sudoku Generator/Solver	      | sudoku		         | A simple program for generating sudoku boards and/or solving them.							       |
| Geekcode generator		      | geekcode_generator       | Generate a block of [geekcode](https://en.wikipedia.org/wiki/Geek_Code) based on various parameters.			       |
| Hangman			      | hangman		         | Simple hangman game.													       |
| Collatz_Conjecture		      | collatz_conjecture       | Given a number N, follow the steps of the [Collatz Conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture) and count the number of steps until 1 is reached. |
| Scientific Calculator		      | scientific_calculator    | Similiar to the previous, more basic calculator, although this time with many more functions and possible computations.  |
| Currency converter		      | currency_converter       | Convert to and from various currencies. Ideally you should grab the live exchange rates from the web.		       |
| Text to ASCII			      | text_to_ascii	         | Simple program which converts string input into larger ASCII text							       |
| Simple paint clone		      | paint_clone	         | A simple paint clone that allows you to draw lines on a canvas with your mouse and/or keyboard			       |
| Longest common substring	      | longest_common_substring | Take multiple strings and find the longest common sub-string among them.						       |
| Draw a circle with arbitrary radius | circle_drawer		 | Allow the user to specify a radius and use it to draw a corresponding circle.					       |
| Matrix rotator		      | matrix_rotator           | Given an *n x n* matrix as input, allow for rotating/flipping/reversing the  matrix (as if it were an image). Bonus for implementing *m x n* (non-square) rotation! |
| Integer to Roman numeral	      | integer_to_roman	 | Convert a given integer value to roman numerals.									       |

## How to contribute

__1.__ [Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repository from your web browser

__2.__ Clone your forked repository into a directory or your choice:
```
git clone https://github.com/{Your Username}/Awesome-Programming-Challenges
```


__3.__ Make a new branch and create a new remote upstream (i.e link with the original repository for syncing):
```
git checkout -b your_new_branch
git remote add upstream https://github.com/Zsargul/Awesome-Programming-Challenges
```

The name of ```your_new_branch``` does not matter much, so you can name it whatever you'd like.

__4.__  On your new branch, make a folder (if it does not exist already) named after the task you are attempting, for example:
```
mkdir temperature_converter
```

You can use ```git status``` to check which branch you are currently on.

The folder names for each challenge can be found in the [list above](#CHALLENGES).


__5.__ In that folder, create another folder named after your Github username. That folder will contain your file(s) for the solution you have created. In brief, your submission should look something like this in the file directory:
__Example:__
```
temperature_converter/your_username/your_solution.py
```

for a single file, or:

```
temperature_converter/
└── your_username/
    ├── solution_file1.py
    └── solution_file2.py
```

for a multi-file solution.


__6.__ Add, commit and push your solution to your fork using these commands:
```
git add .
git commit -m "description of changed files"
git push -u origin your_new_branch
```

__7.__ After successfully pushing, you can finally submit your solution by opening up a pull request through your fork on your web browser. If you do not know how to do this, see [the following](https://opensource.com/article/19/7/create-pull-request-github).

## Submitting new challenges or changes to the current list

You are also free to suggest new challenges to the list or changes to the current ones. You can do so with a regular pull-request or by opening an issue.
