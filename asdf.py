from random import randrange


from subprocess import check_output

with open("/home/user/file.in", "rb") as file:
    output = check_output(["/home/user/executable"], stdin=file)
    