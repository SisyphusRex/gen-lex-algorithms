#include <program.h>
#include <stdio.h>

//
//
//  Bootstrap File
//
//

int main(int argc, char *argv[])
{

    // Remove program call from argv
    char *passedArgs[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        passedArgs[i] = argv[i + 1];
    }

    // run the program
    run(argc - 1, passedArgs);

    return 0;
}