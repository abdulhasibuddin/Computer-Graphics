#include<stdio.h>

char mat[1000][1000];
int array_coordinates[100];

void printRaster(int numOfRows, int numOfColumns);
void createRaster(int numOfRows, int numOfColumns);
void plotPoints(int numOfInput, int numOfRows, int numOfColumns);

int main()
{
    for(int i=0; i<sizeof(array_coordinates); i++)
    {
        array_coordinates[i] = -1;
    }

    int m,n, x_coordinates = 0, num_rows = 0;

    printf("Raster size (max 100X54) = ");
    scanf("%d%d", &m,&n);
    printf("\n");

    //Creating initial raster::
    createRaster(m, n);
    //Printing raster::
    printRaster(m, n);

    //input points:
    int num_points=0, x,y, x_init,y_init, x_end,y_end, p,dx,dy;
    printf("\n\nEnter starting coordinates (x1,y1): ");
    scanf("%d%d", &x_init, &y_init);
    printf("Enter ending coordinates (x2,y2): ");
    scanf("%d%d", &x_end, &y_end);

    if(x_end<x_init)
    {
        int temp = x_end;
        x_end = x_init;
        x_init = temp;
    }
    if(y_end<y_init)
    {
        int temp = y_end;
        y_end = y_init;
        y_init = temp;
    }

//# BRESENHAM LINE ALGORITHM:: #######################
    dx = x_end-x_init; //abs(x_end-x_init)
    dy = y_end-y_init;

    if(dy>=dx)
    {
        printf("Invalid input!");
        return 0;
    }

    for(int i=0; ;i++)
    {
        if(i==0)
        {
            x = x_init;
            y = y_init;
            p = 2*dy - dx;
            continue;
        }

        //printf("x%d,y%d=%d,%d; ", i,i,x,y);
        array_coordinates[num_points] = x;
        array_coordinates[num_points+1] = y;
        num_points += 2;

        if(x==x_end){ break; }

        if(p<0)
        {
            x = x+1;
            p = p + 2*dy;
        }
        else
        {
            x = x+1;
            y = y+1;
            p = p + 2*dy - 2*dx;
        }
    }
//## End of 'BRESENHAM LINE ALGORITHM' #################

    /*printf("\nArray coordinates: ");
    for(int i=0; i<100 ;i++)
    {
        printf("%d ", array_coordinates[i]);
    }*/

    //Plotting points::
    printf("\nPoints:\n");
    plotPoints(num_points, m, n);

    //Printing updated raster::
    printf("\n");
    printRaster(m, n);
}
//#####################################################

//Printing Raster::
void printRaster(int numOfRows, int numOfColumns)
{
    int num_rows=numOfRows-1, m=numOfRows, n=numOfColumns;

    for(int i=0; i<m*2; i++)
    {
        if((i==0 || i%2==0) && num_rows<10)
        {
            printf(" %d ", num_rows);
            num_rows--;
        }
        else if((i==0 || i%2==0) && num_rows>=10)
        {
            printf("%d ", num_rows);
            num_rows--;
        }
        else
        {
            printf("   ");
        }

        for(int j=0; j<n*3; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    //Printing x-coordinates::
    printf("   ");
    for(int i=0; i<n*3; i++)
    {
        if(i==0 || i%3==0)
        {
            printf("%d", i/3);
        }
        else if(i/30==0)
        {
            printf(" ");
        }
        else
        {
            printf(" ");
            i++;
        }
    }
}
//######################################################

//Plotting points on Raster::
void plotPoints(int numOfInput, int numOfRows, int numOfColumns)
{
    int x,y,x_prev,y_prev, num_points=numOfInput, m=numOfRows, n=numOfColumns;

    for(int points=0; points<num_points; points++)
    {
        if(points>0) //If not the first point
        {
            x_prev = x; //Getting x of previous point
            y_prev = y; //Getting y of previous point
        }
        x = array_coordinates[points]; //Getting x of current point
        y = array_coordinates[points+1]; //Getting y of current point
        points++;
        printf("(x%d,y%d) = (%d,%d)\n", points/2,points/2,x,y); //Printing points

        for(int i=0; i<m*2; i++)
        {
            if((i==0 || i%2==0) && i==(m-1)*2-y*2)
            {
                for(int j=0; j<n*3; j++)
                {
                    if((j == 0 || j%3 == 0) && j==x*3)
                    {
                        mat[i][j] = 'O'; //Identifying points

                        if(x-x_prev==1 && y-y_prev==0)
                        {
                            mat[i][j-1] = '-';
                            mat[i][j-2] = '-';
                        }
                        else if(y-y_prev==1 && x-x_prev==0)
                        {
                            mat[i+1][j] = '|'; //visually low numbered row is internally high numbered row,...
                            //so the previous row in graph is (i+1), not (i-1)!
                        }
                    }
                }
            }
        }
    }
}
//################################################

//Initializing Raster::
void createRaster(int numOfRows, int numOfColumns)
{
    int m=numOfRows, n=numOfColumns;

    for(int i=0; i<m*2; i++)
    {
        if(i==0 || i%2==0)
        {
            for(int j=0; j<n*3; j++)
            {
                if(j == 0 || j%3 == 0)
                {
                    mat[i][j] = '.';
                }
                else
                {
                    mat[i][j] = ' '; //'-'
                }
            }
        }
        else
        {
            for(int j=0; j<n*3; j++)
            {
                mat[i][j] = ' '; //'|'
            }
        }
    }
}
