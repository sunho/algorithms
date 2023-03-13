def count_inversions(weights, labels):
    n = len(weights)
    # Base case for recursion
    if n <= 1:
        return 0, weights, labels
    # Split the array in half
    mid = n // 2
    left_weights = weights[:mid]
    right_weights = weights[mid:]
    left_labels = labels[:mid]
    right_labels = labels[mid:]
    # Recursively count the number of inversions in the left and right halves
    left_count, left_sorted, left_label_sorted = count_inversions(left_weights, left_labels)
    right_count, right_sorted, right_labels_sorted = count_inversions(right_weights, right_labels)
    # Count the number of inversions while merging
    merge_count = 0
    i, j = 0, 0
    merged_weights = []
    merged_labels = []
    for k in range(n):
        # If all elements in the left array have been added, add the remaining right elements
        if i == len(left_sorted):
            merged_weights += right_sorted[j:]
            merged_labels += right_labels_sorted[j:]
            break
        # If all elements in the right array have been added, add the remaining left elements
        if j == len(right_sorted):
            merged_weights += left_sorted[i:]
            merged_labels += left_label_sorted[i:]
            break
        # If the left element is smaller than the right element, add it
        if left_sorted[i] < right_sorted[j]:
            merged_weights.append(left_sorted[i])
            merged_labels.append(left_label_sorted[i])
            i += 1
        # If the right element is smaller than the left element, add it and count the inversion
        else:
            merged_weights.append(right_sorted[j])
            merged_labels.append(right_labels_sorted[j])
            j += 1
            merge_count += len(left_sorted) - i
    # Return the total number of inversions
    return left_count + right_count + merge_count, merged_weights, merged_labels

# Read the input
n = int(input())
labels = input()
weights = list(map(int, input().split()))

# Count the number of inversions
inversions, sorted_weights, sorted_labels = count_inversions(weights, labels)

# Find the maximum value of f(X) for all real values of X
max_correct = n - inversions

# Print the result
print(max_correct)