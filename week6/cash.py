
while True:
    while True:
        try:
            num = input("Change: ")
            num_check = float(num)
            break
        except ValueError:
            continue

    if (num_check >= 0):
        try:
            float(num)
            break
        except ValueError:
            continue
    else:
        continue

num = round(float(num), 2)
count = 0

while num > 0.00:
    if num >= 0.25:
        num = round(num - 0.25, 2)
        count += 1
        # print(f"num is: {num} and count is: {count}")
    elif num >= 0.10:
        num = round(num - 0.10, 2)
        count += 1
        # print(f"num is: {num} and count is: {count}")
    elif num >= 0.05:
        num = round(num - 0.05, 2)
        count += 1
        # print(f"num is: {num} and count is: {count}")
    elif num >= 0.01:
        num = round(num - 0.01, 2)
        count += 1
        # print(f"num is: {num} and count is: {count}")

print(count)
