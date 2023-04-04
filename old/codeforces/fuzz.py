import subprocess
import random

# Generate random input

while True:
    n = random.randint(1, 7)
    input_data = str(n+5) + " 5 "
    for i in range(5):
        input_data += str(5-i) + " "
    for i in range(n):
        input_data += str(random.randint(1, 5)) + " "
    input_data += "\n"
    # Run program 1 with the input and capture output
    p1 = subprocess.run(["./perfect_flush.bin"], input=input_data, capture_output=True, text=True)
    stdout1 = p1.stdout.strip()

    # Run program 2 with the input and capture output
    p2 = subprocess.run(["./perfect_flush_ans2.bin"], input=input_data, capture_output=True, text=True)
    stdout2 = p2.stdout.strip()

    # Compare output
    if stdout1 != stdout2:
        print("Programs produced different output.")
        print(input_data)
        print("Program 1 output:")
        print(stdout1)
        print("Program 2 output:")
        print(stdout2)
        exit()