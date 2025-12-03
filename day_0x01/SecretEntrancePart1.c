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
        if('R' == dir)
            currecnt = (currecnt + dis) % 100;
        else 
            currecnt = (1000 + currecnt - dis) % 100;

        if(0 == currecnt)
            ans++;
    }
    printf("\033[0;32m%d\n\033[0m", ans);

    //! end
    fclose(file);
    return 0;
}