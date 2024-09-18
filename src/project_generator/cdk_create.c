///===============PROJECT GENERATOR==================
/// This is one of the file responsible for Generating Projects structure for end users
/// ```bash
///  cdk New_Project example
///  cd example
///  ls 
///  main.cpp makefile cmake 
/// ```
/// the above program generates a program environment with build system as specified by the users


/// EXAMPLE USAGE (prototype)
///``` cdk_create list``` - list all the available templates
///
/// ``` cdk_create [template]	-[file] [directory_name]``` :
/// where [template] is the project type like console_app, web_app, Graphics_app(SDL2, OpenGL, ..)
/// where [file] is the file type like -c for a C project or -cc for C++ projects 
/// where [directory_name] is the directory name specified by the user
/// practical example:
/// ```bash
/// cdk_create console_app -c my_project
/// cd my_project
/// ls
/// main.c makefile 
/// ```

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For system() to execute shell commands
#include <string.h>

// Function declarations for different project templates
void console_app(const char *file_type, const char *directory_name);
void SDL_app(const char *file_type, const char *directory_name);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: cdk_create [template] [file_type] [directory_name]\n");
        return 1;
    }

    // Variables for file type and directory name
    char file_type[20];
    const char *template_type = argv[1];
    const char *file_type_flag = argv[2];
    const char *directory_name = argv[3];

    // Determine the file type (C or C++)
    if (strcmp(file_type_flag, "-c") == 0) {
        strcpy(file_type, "main.c");
    } else if (strcmp(file_type_flag, "-cc") == 0) {
        strcpy(file_type, "main.cpp");
    } else {
        printf("File type not recognized. Use -c for C or -cc for C++.\n");
        return 1;
    }

    // Call appropriate function based on the template type
    if (strcmp(template_type, "console_app") == 0) {
        console_app(file_type, directory_name);
    } else if (strcmp(template_type, "SDL_app") == 0) {
        SDL_app(file_type, directory_name);
    } else {
        printf("Template type '%s' not found.\n", template_type);
        return 1;
    }

    return 0;
}

// Function to create a Console Application project
void console_app(const char *file_type, const char *directory_name) {
    char command[256];

    // Create the directory
    sprintf(command, "mkdir %s", directory_name);
    system(command);

    // Create the file (main.c or main.cpp) in the directory
    sprintf(command, "touch %s/%s", directory_name, file_type);
    system(command);

    // Optionally create a Makefile (placeholder example)
    sprintf(command, "echo 'all:\n\tgcc %s/%s -o %s/program' > %s/Makefile",
            directory_name, file_type, directory_name, directory_name);
    system(command);

    printf("Console app created in directory: %s\n", directory_name);
}

// Function to create an SDL App project (placeholder example)
void SDL_app(const char *file_type, const char *directory_name) {
    char command[256];

    // Create the directory
    sprintf(command, "mkdir %s", directory_name);
    system(command);

    // Create the file (main.c or main.cpp) in the directory
    sprintf(command, "touch %s/%s", directory_name, file_type);
    system(command);

    // Add SDL-related Makefile (placeholder)
    sprintf(command, "echo 'all:\n\tgcc %s/%s -lSDL2 -o %s/program' > %s/Makefile",
            directory_name, file_type, directory_name, directory_name);
    system(command);

    printf("SDL app created in directory: %s\n", directory_name);
}