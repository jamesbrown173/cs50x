levels = 0

while levels < 1 or levels > 8 or type(levels) != int:
    user_input = input("Height: ")

    if user_input == "foo":
        print("Invalid input. Please enter a number between 1 and 8.")
        continue

    try:
        levels = int(user_input)
    except ValueError:
        print("Invalid input. Please enter a number between 1 and 8.")
        levels = 0

block = "#"

# Print the height of the input
for i in range(levels):
    spaces = " " * (levels - i - 1)
    blocks = block * (i + 1)
    print(f"{spaces}{blocks}  {blocks}")
