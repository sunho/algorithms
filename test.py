import random
import subprocess

# Specify the path to the binary program
binary_program_path = "/path/to/binary/program.bin"

# Specify the number of test cases you want to generate and run
num_test_cases = 10

# Generate and run the test cases
for i in range(num_test_cases):
    # Generate random inputs for the test case
    # Modify this section according to your specific problem requirements
    input_data = random.randint(1, 100)  # Example: Generate a random integer between 1 and 100
    
    # Prepare the command to run the binary program with the generated input
    command = [binary_program_path]
    # Append the input data as arguments to the command list
    command.append(str(input_data))
    
    try:
        # Run the binary program with the generated input
        result = subprocess.run(command, capture_output=True, text=True, timeout=2)
        
        # Process the output of the binary program
        # Modify this section according to your specific problem requirements
        output = result.stdout.strip()
        
        # Print the test case and its corresponding output
        print(f"Test Case #{i + 1}: Input = {input_data}, Output = {output}")
    
    except subprocess.TimeoutExpired:
        print(f"Test Case #{i + 1}: Timeout occurred for input {input_data}")

    except subprocess.CalledProcessError as e:
        print(f"Test Case #{i + 1}: Error occurred for input {input_data}")
        print(f"Error message: {e.stderr}")