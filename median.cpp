// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>

#include<image.h>
#include<median.h>
#include<tlm.h>

void do_medianfilter(const unsigned char input[][HEIGHT], unsigned char output[][HEIGHT], unsigned int width, unsigned int height)
{

    //TODO: put your implementation here
    unsigned char window[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned char sorted_window[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    int x;
    int counter=0;
    for(unsigned int i=1 ; i<height-1 ; ++i)
    {
        for(unsigned int j=1 ; j<width-1 ; ++j)
        {
            window[0] = input[i-1][j-1];
            window[1] = input[i-1][j];
            window[2] = input[i-1][j+1];
            window[3] = input[i][j-1];
            window[4] = input[i][j+1];
            window[5] = input[i+1][j-1];
            window[6] = input[i+1][j];
            window[7] = input[i+1][j+1];

/*sorting*/for(int sort=0 ; sort<8 ; ++sort)
            {
//                x=window[sort];
                for(int y=0 ; y<8 ; ++y)
                {
                    if((window[sort]>window[y])/*&&(y>sort)*/)
                    {
                        ++counter;
                    }
                }
                sorted_window[counter]=window[sort];
                counter=0;
            }
            output[i][j]=(sorted_window[4]+sorted_window[3])/2;//evalution of the median value
        }
    }
    return;
}

