import random
import subprocess

# function for generating random input
def generate_input():
    n = random.randint(1, 20)
    costs = [random.randint(1, n) for _ in range(9)]
    return (n, costs)

# function for running the first executable
def run_executable1(n, costs):
    input_str = str(n) + '\n' + ' '.join(map(str, costs)) + '\n'
    result = subprocess.run(['./E_-_Addition_and_Multiplication_2.bin'], input=input_str, stdout=subprocess.PIPE, universal_newlines=True)
    return int(result.stdout)

# function for running the second executable
def run_executable2(n, costs):
    input_str = str(n) + '\n' + ' '.join(map(str, costs)) + '\n'
    result = subprocess.run(['./E_-_Addition_and_Multiplication_2_ans.bin'], input=input_str, stdout=subprocess.PIPE, universal_newlines=True)
    return int(result.stdout)

# function for comparing the output of the two executables
def compare_output(output1, output2):
    if output1 == output2:
        return True
    else:
        return False

while True:
    # generate random input
    n, costs = generate_input()

    # run the two executables
    output1 = run_executable1(n, costs)
    output2 = run_executable2(n, costs)

    # compare the outputs
    if not compare_output(output1, output2):
        print("Different output generated:")
        print("Input: n =", n, "costs =", costs)
        print("Executable 1 output:", output1)
        print("Executable 2 output:", output2)
        break
