def check_sum(num):
    total = 0
    var = True
    while num > 0:
        if var:
            total += num % 10
            num //= 10
            var = False
        else:
            buffer = (num % 10) * 2
            if buffer >= 10:
                total += buffer % 10
                total += buffer // 10
            else:
                total += buffer
            var = True
            num //= 10
    if total % 10 == 0:
        return True
    print("INVALID")
    return False


def main():
    digits = 0
    single_digit = 0
    two_digit = 0
    user_input = int(input("Number: "))
    checksum = check_sum(user_input)
    if not checksum:
        return

    temp_input = user_input
    while temp_input > 0:
        if temp_input < 10:
            single_digit = temp_input
        if 10 < temp_input < 100:
            two_digit = temp_input
        temp_input //= 10
        digits += 1

    if (two_digit == 34 or two_digit == 37) and digits == 15:
        print("AMEX")
    elif two_digit in [51, 52, 53, 54, 55] and digits == 16:
        print("MASTERCARD")
    elif single_digit == 4 and (digits == 13 or digits == 16):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
