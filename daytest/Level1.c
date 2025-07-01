#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "Level3.h"

#define CLEARSCREEN()   printf("\033[2J")
#define MOVEUP(x)       printf("\033[%dA", (x))
#define MOVEDOWN(x)     printf("\033[%dB", (x))
#define MOVELEFT(x)     printf("\033[%dD", (x))
#define MOVERIGHT(x)    printf("\033[%dC", (x))

int enableRawMode(FILE *fp) 
{
    struct termios orig_termios;
    int ch;

    while(1){
	    /* save current terminal settings */
	    tcgetattr(STDIN_FILENO, &orig_termios);
	
	    /* get new terminal settings */
	    struct termios new_termios = orig_termios;
	    new_termios.c_lflag &= ~(ICANON | ECHO);    // disable ICANON -> immediate response ; disable ECHO -> not show what you entered
	    new_termios.c_cc[VTIME] = 0;
	    new_termios.c_cc[VMIN] = 1;     // input overtime ?
	    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);     // apply the new settings

        ReadRow(fp);

        /* process the input*/
        ch = getchar();
        if(ch == 'q')   // quit
        {
            printf("\n");
            break;
        }
        switch (ch)
        {
            case '\033':
            {
                getchar();
                switch(getchar())
                {
                    case 'A':   
                        MOVEUP(1);
                        break;
                    case 'B':
                        MOVEDOWN(1);
                        break;
                    case 'D':
                        MOVELEFT(1);
                        break;
                    case 'C':
                        MOVERIGHT(1);
                        break;
                    // case 'F':   // end
                        
                    //     break;
                    default:
                        break;
                    }
                break;                
            }
            case 127:       // backspace
                CLEARSCREEN();
                break;
            case 10:        // enter
            {
                printf("\n");
                break;
            }
            default:
            {
                printf("%d", ch);
                break;
            }
        }

        // back to original settings
	    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
	}
    return 0;
}

