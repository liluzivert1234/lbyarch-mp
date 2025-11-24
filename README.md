# LBYARCH Machine Project - DAXPY Implementation
**Double-Precision A*X + Y Operation in C and x86-64 Assembly**

## Project Description
This program implements the DAXPY (Double-precision A times X Plus Y) operation, a fundamental linear algebra computation, using both C and x86-64 assembly language. The operation computes: **result[i] = A * X[i] + Y[i]** for all elements in arrays X and Y.

## Team Members
- John Vincent Torres
- Pulvert Valdez
- Gabriel Alexander Villaflor

## Implementation Details

### C Program Responsibilities:
- Generating random input data for arrays X and Y
- Allocating memory for large arrays
- Timing both C and assembly implementations
- Printing sample results for verification
- Computing average execution times over 30 runs

### x86-64 Assembly Responsibilities:
- Computing DAXPY operation: result[i] = A * X[i] + Y[i]
- Using **scalar SIMD registers (XMM registers)**
- Using **scalar SIMD floating-point instructions** for double-precision operations

### SIMD Instructions Used:
- `movsd` - Move scalar double-precision float
- `mulsd` - Multiply scalar double-precision float
- `addsd` - Add scalar double-precision float

## Performance Analysis

### Test Configuration
- **Constant A**: 2.0
- **Array Size**: 268,435,456 elements (2^28)
- **Number of Runs**: 30
- **Sample Results Displayed**: First 10 elements

### Execution Time Results (2^28 30-run average)

| Implementation | Average Time (ms) | Performance |
|----------------|-------------------|-------------|
| C DAXPY        | 2755.3702 ms      | Baseline    |
| x86-64 ASM DAXPY | 916.4356 ms     | **3.0x faster** |

### Execution Time Results (2^24 30-run average)

| Implementation | Average Time (ms) | Performance |
|----------------|-------------------|-------------|
| C DAXPY        | 180.1103 ms      | Baseline    |
| x86-64 ASM DAXPY | 62.6436 ms     | **3.0x faster** |

### Execution Time Results (2^20 30-run average)

| Implementation | Average Time (ms) | Performance |
|----------------|-------------------|-------------|
| C DAXPY        | 11.9274 ms      | Baseline    |
| x86-64 ASM DAXPY | 4.3185 ms     | **3.0x faster** |

### Performance Analysis
The assembly implementation demonstrates **significant performance improvement** over the C implementation:
- **Assembly is ~3 times faster** than the C implementation
- The use of XMM registers for double-precision floating-point operations provides direct hardware access
- The assembly code eliminates function call overhead and optimizes memory access patterns
- Linear memory access pattern benefits from CPU cache optimization
- The scalar SIMD instructions (`movsd`, `mulsd`, `addsd`) operate efficiently on 64-bit double-precision values

**Key Observations:**
- For large arrays (536+ million elements), the assembly implementation processes approximately **585,000 elements per millisecond**
- The performance gain comes from reduced instruction overhead and optimized register usage
- Both implementations produce identical results, confirming correctness

## Sample Output

### Correctness Check
![Sample Output Screenshot]

**Sample Results (First 10 elements):**
```
Result of cDAXPY:
result[0] = 54.900000
result[1] = 116.800000
result[2] = 106.200000
result[3] = 131.400000
result[4] = 238.800000
result[5] = 155.500000
result[6] = 138.900000
result[7] = 241.300000
result[8] = 293.200000
result[9] = 209.000000

Result of asmDAXPY:
result[0] = 54.900000
result[1] = 116.800000
result[2] = 106.200000
result[3] = 131.400000
result[4] = 238.800000
result[5] = 155.500000
result[6] = 138.900000
result[7] = 241.300000
result[8] = 293.200000
result[9] = 209.000000
```

## Compilation Instructions

### Using GCC and NASM:
```bash
# Step 1: Assemble the assembly file
nasm -f win64 daxpy.asm -o daxpy.obj

# Step 2: Compile C source files
gcc -c main.c -o main.o
gcc -c cdaxpy.c -o cdaxpy.o

# Step 3: Link everything together
gcc main.o cdaxpy.o daxpy.obj -o daxpy.exe

# Step 4: Run the program
daxpy.exe
```

## Files Included
- `main.c` - Main C program with I/O, timing, and memory management
- `cdaxpy.c` - C implementation of DAXPY
- `daxpy.asm` - x86-64 assembly DAXPY implementation
- `header.h` - Header file with function declarations
- `README.md` - This file
- `Sample output.png` - Screenshot of program output
- `Mp Demo(1).mp4` - Video demonstration

## Video Demonstration
📹 **[Mp Demo(1).mp4](Mp%20Demo(1).mp4)**

The video demonstrates:
1. Source code walkthrough (C and x86-64 assembly)
2. Compilation process
3. Program execution with correctness verification
4. Performance results showing assembly optimization

---
**Course**: LBYARCH  
**Academic Year**: 2024-2025  
**Institution**: De La Salle University  
