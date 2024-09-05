/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>

int main(void)
{
    double width = 3.77; // input width
    double height = 4.88; // input height
    double perimeter = 0.0; // output perimeter
    double area = 0.0; // output area
    
    /*
     * Perimeter of a rectangle
     */
    perimeter = 2.0*(width+height);
    
    /*
     * Area of a rectangle
     */
    area = width*height;
    
    /*
     * Display inputs and outputs
     */
    printf("\tWidth : %.2lf, Height : %.2lf\n", width, height);
    printf(" Perimeter : %.5lf\n Area : %.5lf\n ", perimeter, area);
    
	return 0;
}
