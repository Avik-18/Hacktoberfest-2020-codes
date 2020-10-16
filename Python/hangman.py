import random 

HANGMANPICS = ['''

     00---+++
     |     00
           ||
           ++
           00
           ||
    ==========''', '''

     00---+++
     |     00
     O     ||
           ++
           00
           ||
    ==========''', '''
    
     00---+++
     |     00
     O     ||
     |     ++
           00
           ||
    =========''', '''
    
     00---+++
     |     00
     O     ||
    /|     ++
           00
           ||
    =========''', '''
    
     00---+++
     |     00
     O     ||
    /|\    ++
           00
           ||
    ==========''', '''

     00---+++
     |     00
     O     ||
    /|\    ++
    /      00
           ||
    ==========''', '''

     00---+++
     |     00
     O     ||
    /|\    ++
    / \    00
           ||
    ==========''']
    
words = 'computer cpu monitor mouse laptop keyboard printer scanner pendrive drive floopy'.split()

def getRandomWord(wordList):
    wordIndex = random.randint(0, len(wordList) - 1)
    return wordList[wordIndex]

def displayBoard(HANGMANPICS, missedLetters, correctLetters, secretWord):
    print(HANGMANPICS[len(missedLetters)])
    print()

    print('Missed letters:', end=' ')
    for letter in missedLetters:
        print(letter, end=' ')
    print()

    blanks = '_' * len(secretWord)

    for i in range(len(secretWord)): 
        if secretWord[i] in correctLetters:
            blanks = blanks[:i] + secretWord[i] + blanks[i+1:]

    for letter in blanks: 
        print(letter, end=' ')
    print()

def getGuess(alreadyGuessed):
    while True:
        print('Guess a letter.')
        guess = input()
        guess = guess.lower()
        if len(guess) != 1:
            print('Please enter a single letter.')
        elif guess in alreadyGuessed:
            print('You have already guessed that letter. Choose again.')
        elif guess not in 'abcdefghijklmnopqrstuvwxyz':
            print('Please enter a LETTER.')
        else:
            return guess

def playAgain():
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')


print('H A N G M A N')
missedLetters = ''
correctLetters = ''
secretWord = getRandomWord(words)
gameIsDone = False

while True:
    displayBoard(HANGMANPICS, missedLetters, correctLetters, secretWord)

    guess = getGuess(missedLetters + correctLetters)

    if guess in secretWord:
        correctLetters = correctLetters + guess

        foundAllLetters = True
        for i in range(len(secretWord)):
            if secretWord[i] not in correctLetters:
                foundAllLetters = False
                break
        if foundAllLetters:
            print('Yes! The secret word is "' + secretWord + '"')
            print('''
            __   __                                  _ _
            \ \ / /__  _   _  __      _____  _ __   | | |
             \ V / _ \| | | | \ \ /\ / / _ \| '_ \  | | |
              | | (_) | |_| |  \ V  V / (_) | | | | |_|_|
              |_|\___/ \__,_|   \_/\_/ \___/|_| |_| (_|_)
            
            ''')
	 
            gameIsDone = True
    else:
        missedLetters = missedLetters + guess

        if len(missedLetters) == len(HANGMANPICS) - 1:
            displayBoard(HANGMANPICS, missedLetters, correctLetters, secretWord)
    
            print('''
                __   __            _           _     _ _
                \ \ / /__  _   _  | | ___  ___| |_  | | |
                 \ V / _ \| | | | | |/ _ \/ __| __| | | |
                  | | (_) | |_| | | | (_) \__ \ |_  |_|_|
                  |_|\___/ \__,_| |_|\___/|___/\__| (_|_)
            
            ''')
            print('You have run out of guesses!\nAfter ' + str(len(missedLetters)) + ' missed guesses and ' + str(len(correctLetters)) + ' correct guesses, the word was "' + secretWord + '"')
            gameIsDone = True

    if gameIsDone:
       if playAgain():
           missedLetters = ''
           correctLetters = ''
           gameIsDone = False
           secretWord = getRandomWord(words)
       else:
           break

