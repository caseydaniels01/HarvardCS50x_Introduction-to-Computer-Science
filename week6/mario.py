while True:
    try:
        number = input("Height: ")
        if number.isdigit():
            number = int(number)
        else:
            continue

        if 1 <= number <= 8:
            break
        else:
            continue
    except ValueError:
        continue

for i in range(1, number + 1):
    spaces = int(number - i)
    print((" " * spaces) + "#" * i)