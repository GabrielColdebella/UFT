****

> [!FOPEN:]
> **w - Writes to a file**
> **a - Appends new data to a file**
> **r - Reads from a file** 


"**fopen**", "**fwrite**", "**fread**" e "**fclose**"

FILE `*`fptr;  
  
// Create a file  
fptr = fopen("filename.txt", "w");  

// Write some text to the file
fprintf(fptr, "Some text");

// Open a file in read mode  
fptr = fopen("filename.txt", "r");  
  
// Store the content of the file  
char myString[100];

// Read the content and store it inside myString
fgets(myString, 100, fptr);

// Print the file content  
printf("%s", myString);

// Close the file  
fclose(fptr);
