# C-plusplus-Implementation-of-Central-Limit-Theorem
C++ code implementing the Central Limit Theorem for calculating mean, standard deviation, and sample mean, generating random samples, and calculating Z-values.

## Central Limit Theorem C++ Implementation

This C++ program demonstrates the Central Limit Theorem by calculating mean, standard deviation, sample mean, and Z-values. It also generates random samples from a dataset and saves the calculated values in output files.

### Instructions:

1. **Data File**: Make sure you have a data file named "EmployeeData.csv" in the same directory as the program. The file should contain the dataset from which random samples will be extracted.

2. **Libraries**: The program requires the following libraries: `<iostream>`, `<fstream>`, `<vector>`, `<string>`, `<cmath>`, `<cstdlib>`, and `<time.h>`. Ensure that these libraries are available in your C++ environment.

3. **Compile**: Compile the program using a C++ compiler. For example, using g++ in the command line:

   ```
   g++ central_limit_theorem.cpp -o central_limit_theorem
   ```

4. **Run**: Execute the compiled program:

   ```
   ./central_limit_theorem
   ```

5. **Output Files**: The program will generate two output files:
   - "Output10.txt": Contains the Z-values calculated for sample size 10. Each value is listed on a separate line.
   - "test.txt": Contains the Z-values calculated for sample size 300. Each value is listed on a separate line.

6. **Review Results**: Open the output files to review the calculated Z-values.

Note: The program assumes that the data file is in the correct format and the dataset contains at least 1000 entries.

### Additional Notes:

- The program uses random number generation to extract samples from the dataset.
- The Central Limit Theorem states that as the sample size increases, the distribution of sample means approaches a normal distribution, regardless of the shape of the original population.
- The calculated Z-values represent the standardized deviation of the sample mean from the population mean, taking into account the sample size and standard deviation.

**Important**: Ensure that you have a proper understanding of the Central Limit Theorem and the code before using it or making any modifications.
