secret_num = 7
guess_count = 0
guess_limit = 3
while guess_count < guess_limit:
    guess = int(input(f"Guess {guess_count + 1}: "))
    guess_count += 1
    if guess == secret_num:
        print("Congratulations! You Guessed the correct number")
        print("You'll have a great day ahead :)")
        break
else:
    print("Sorry you couldn't guess the number")
