
text = input("Text: ")
word_count = float(len(text.split()))
sent_count = float(text.count('.') + text.count('?') + text.count('!'))
letter_count = float(len(text) + 1) - text.count(' ') - sent_count - text.count("'") - text.count(",") - 1

L = float((letter_count / word_count) * 100)
S = float((sent_count / word_count) * 100)
coleman = round(0.0588 * L - 0.296 * S - 15.8)

# print(word_count)
# print(letter_count)
# print(sent_count)
# print(L)
# print(S)
# print(coleman)

if (coleman < 1):
    {
        print("Before Grade 1")
    }
elif (coleman > 15):
    {
        print("Grade 16+")
    }
else:
    {
        print(f"Grade {coleman}")
    }
