*This project has been created as part of the 42 curriculum by gelgasim, fcholakk.*

# Push_swap

## Description

**Push_swap** is a 42 School algorithm project focused on sorting a collection of integers using two stacks and a limited set of operations.

The goal is to sort stack A in ascending order using the smallest reasonable number of operations. Stack B is used as temporary storage.

The project explores different sorting strategies and introduces an adaptive approach that selects an algorithm based on the initial disorder of the input.

### Main Features

- Sorting integers using two stacks.
- Implementation of all required stack operations.
- Four sorting strategies: Simple, Medium, Complex, and Adaptive.
- Rank-based sorting for the Medium and Complex strategies.
- Disorder calculation to evaluate the initial arrangement.
- Benchmark mode to display sorting statistics.

## Instructions

### Compilation

Clone the repository and enter the project directory:

```bash
git clone git@vogsphere.42abudhabi.ae:vogsphere/intra-uuid-d7e8b522-431a-48db-a934-125293b537f8-7782393-gelgasim
cd push_swap
```

Compile the project:

```bash
make
```

This generates the `push_swap` executable.

Other Makefile commands:

```bash
make clean
make fclean
make re
```

### Execution

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

The program prints the operations required to sort the stack.

### Available Strategies

The project provides four strategies:

**1. Simple**

```bash
./push_swap --simple 4 67 3 87 23
```

Uses minimum extraction. It repeatedly finds the smallest value in stack A, moves it to stack B, and then transfers the values back to A.

Complexity: O(n²).

**2. Medium**

```bash
./push_swap --medium 4 67 3 87 23
```

Uses block-based partitioning. Values are converted into ranks and divided into blocks. Each block is transferred from stack A to stack B, and the values are then extracted in descending order to produce an ascending stack A.

Complexity: O(n√n).

**3. Complex**

```bash
./push_swap --complex 4 67 3 87 23
```

Uses binary Radix Sort on ranked values. It processes the binary representation of each rank, moving values between stacks according to individual bits.

Complexity: O(n log n).

**4. Adaptive**

```bash
./push_swap --adaptive 4 67 3 87 23
```

Automatically selects a sorting strategy based on the initial disorder:

| Disorder | Selected strategy | Complexity |
|---|---|---|
| Below 20% | Simple | O(n²) |
| 20% to below 50% | Medium | O(n√n) |
| 50% or higher | Complex | O(n log n) |

Adaptive sorting aims to select a suitable strategy for the initial arrangement instead of always using the same algorithm.

### Benchmark Mode

Use `--bench` to display sorting statistics:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

The benchmark reports information such as:

- Selected strategy.
- Initial disorder percentage.
- Algorithm complexity.
- Number of operations for each instruction.
- Total operation count.

### Testing with Checker

To verify the sorting result, pipe the output into the checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Expected output:

```text
OK
```

The checker should return `OK` when stack A is sorted and stack B is empty.

## Algorithm Explanation and Justification

### 1. Disorder Calculation

Before selecting an algorithm, the program calculates the disorder of the input.

Disorder measures how far the input is from being sorted.

It is calculated using the number of inversions:

- An inversion occurs when an element is greater than an element appearing after it.
- The number of inversions is divided by the total number of possible pairs.

Formula:

`Disorder = Inversions / Total Pairs`

The result ranges from 0 to 1:

- 0 means the input is already sorted.
- 1 means the input is in reverse order.

This measurement allows the Adaptive strategy to select an algorithm based on the input arrangement.

### 2. Simple Strategy — Minimum Extraction

The Simple strategy repeatedly finds the smallest value in stack A and moves it to stack B.

Once stack A is empty, the values are pushed back from B to A.

This produces an ascending sequence.

**Why this algorithm?**

It is straightforward to implement and works well for small or nearly sorted inputs.

Its main disadvantage is that finding the minimum repeatedly requires scanning the stack, resulting in O(n²) complexity.

### 3. Medium Strategy — Block-Based Partitioning

The Medium strategy first converts input values into ranks.

Instead of working with potentially large or negative integers, each value receives a rank based on its position in sorted order.

For example:

```text
Original:  40  10  30  20
Ranks:      3   0   2   1
```

The algorithm then:

1. Calculates a block size based on the square root of the input size.
2. Divides the ranked values into consecutive ranges.
3. Pushes values belonging to the current block from A to B.
4. Rotates values outside the current block in A.
5. Repeats until A is empty.
6. Extracts the maximum values from B and pushes them back to A.

**Why this algorithm?**

Block-based partitioning reduces the need to process the entire stack using repeated minimum extraction.

It provides a middle ground between the simple quadratic strategy and the more systematic Radix Sort approach.

Target complexity: O(n√n).

### 4. Complex Strategy — Binary Radix Sort

The Complex strategy also converts input values into ranks.

It then sorts the ranks using their binary representation.

For each bit position:

1. Examine the top value in stack A.
2. If the current bit is 0, push the value to B.
3. If the current bit is 1, rotate A.
4. Once all values have been processed, push everything from B back to A.
5. Move to the next bit.

This continues until all required bits have been processed.

**Why this algorithm?**

Radix Sort avoids repeatedly searching for minimum or maximum values.

It processes values systematically, making it suitable for larger inputs.

Its complexity is O(n log n), where n is the number of elements.

### 5. Adaptive Strategy — Automatic Selection

The Adaptive strategy combines the three previous approaches.

It calculates the initial disorder and selects an algorithm according to fixed thresholds:

- Low disorder: Simple.
- Medium disorder: Medium.
- High disorder: Complex.

**Why this approach?**

Different inputs have different characteristics. A nearly sorted input does not necessarily benefit from the same strategy as a highly disordered input.

The Adaptive strategy uses the initial disorder measurement to make this decision automatically.

## Resources

### AI Usage

AI (ChatGPT) was used as a learning assistant throughout this project.

It helped with:

- Understanding sorting algorithms and their complexity.
- Learning block-based partitioning and Radix Sort.
- Understanding disorder calculation and adaptive algorithm selection.
- Reviewing code logic and debugging implementation issues.
- Improving code structure and meeting Norminette requirements.
- Preparing test cases and understanding test results.

AI was used for explanations, guidance, and code review. The implementation was developed and tested by the project members.
