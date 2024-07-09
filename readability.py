import math


def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for char in text:
        if char == " ":
            count += 1
    return count + 1


def count_sentences(text):
    count = 0
    for char in text:
        if char in ["!", ".", "?"]:
            count += 1
    return count


def main():
    # Prompt the user for some text
    user_text = input("Enter text: ")

    # Count the number of letters, words, and sentences in the text
    num_letters = count_letters(user_text)
    num_words = count_words(user_text)
    num_sentences = count_sentences(user_text)

    # Compute the Coleman-Liau index
    L = (num_letters / num_words) * 100
    S = (num_sentences / num_words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    index_r = round(index)
    f_s = int(index_r)

    if index_r < 1:
        print("Before Grade 1")
    elif index_r > 16:
        print("Grade 16+")
    else:
        print(f"Grade {f_s}")


if __name__ == "__main__":
    main()
