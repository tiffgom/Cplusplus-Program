# Cplusplus-Program

## Airgead Banking Application
### Summary
This program uses an interactive system to teach high school students the concept of fiscal responsibility by focusing on investing and the power of compound interests. The program uses the user's choices of the initial investment amount, length of the investment, interest rate percentage, and monthly deposits to calculate two reports that compare the span of the account's earnings with additional monthly deposits made into the account versus the earnings including only the initial investment. The user has the option to continue to alter the data input to study various results and end the program when they are ready.

### Highlights
This program does a great job of handling exceptions. Try, catch, and throw statements are well placed throughout and are used to assure the program is able to handle negative number input and user input that is not of numeric value. The program goes a step further by offering the user the option to continue interacting with the program or to exit, and the program successfully validates the user input and guides the user to input the appropriate answers. The program practices great maintainability by producing proper error messages and the continuation of program execution.

### Room for Improvement
Further modulization of the code would help make the program more maintainable, readable, adaptable, and secure. I would break up MyInvest.cpp into smaller classes, specifically ensuring the mutators and accessors have their own class. I would further separate the code that computes the calculations from the code that formats the display the users interact with. 

### Overcoming Challenges
The most challenging code to write was the incorporation of user input validation in the exception handling for when non-numeric data was entered. Within my research I found the numeric limits function as a viable solution that would allow the program to ignore erroneous non-numeric input and allow the user to retry their input without the program crashing. Further research was needed to solve problems encountered with the numeric limits function as Microsoft defines is as a non-standard "max" macro in Windows. H header and it conflicts with the max function of numeric limits; therefore, it was necessary to undefine “max”.

### Maintainability, Readability, and Adaptability
Exception handling is transferable and vital to use in all coursework or projects. Properly handling exceptions was useful in ensuring the program did not abruptly terminate for users and will help ensure future programs do not crash due to unusual events. Furthermore, exception handling can aid programmers in tracing problems to their root case. By continuing to employ exception handling in future projects, I can work towards certifying my programs perform the correct actions.

The program exhibits proper naming conventions and includes clear and concise inline comments to provide for easy readability. As mentioned, exception handling is properly executed to ensure maintainability. The code includes functions to execute different aspects of the project so that if a situation arrives where new features need to be aggregated or updated, it can be done so without breaking the program. Lastly, my main function includes minimal code to ensure portability.




