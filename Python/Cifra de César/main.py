import os
import unicodedata


def remove_accent_marks(text):
    return ''.join(
        c for c in unicodedata.normalize('NFD', text)
        if unicodedata.category(c) != 'Mn'
    )


def main():
    option = int(input('Type 1 to ENCODE or 2 to DECODE: '))

    if option not in [1, 2]:
        print('Invalid option.')
        exit(1)

    cipher = int(input('Type the cipher number: '))
    current_dir = os.path.dirname(__file__)
    to_encode = 'to_encode.txt'
    to_decode = 'to_decode.txt'
    filename = to_encode
    ciphered = ""

    if option == 2:
        filename = to_decode
        cipher = -cipher

    with open(os.path.join(current_dir, filename), encoding='utf-8') as f:
        text = remove_accent_marks(f.read())

        for char in text:
            new_char = char

            if char.isalpha():
                start_index = 65 if char.isupper() else 97
                char_index = (ord(char) + cipher - start_index) % 26 + start_index
                new_char = chr(char_index)

            ciphered += new_char

    filename = to_decode if filename == to_encode else to_encode

    with open(os.path.join(current_dir, filename), 'w', encoding='utf-8') as f:
        f.write(ciphered)
    
    print(ciphered)


if __name__ == '__main__':
    main()