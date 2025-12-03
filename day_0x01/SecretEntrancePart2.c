#include <stdio.h>
#include <stdlib.h>


int main() 
{
    FILE *file = fopen("input.txt", "r");
    //! start
    
    char dir;
    int dis;
    int currecnt = 50;
    int ans=0;
    while (fscanf(file, "%c%d\n", &dir, &dis) == 2) 
    {
        while(dis--)
        {
            if('R' == dir)
                currecnt++;
            else 
                currecnt--;

            if(-1 == currecnt)
                currecnt = 99;

            if(100 == currecnt)
                currecnt = 0;

            if(0 == currecnt)
                ans++;
        }
    }
    printf("\033[0;32m%d\n\033[0m", ans);

    //! end
    fclose(file);
    return 0;
}