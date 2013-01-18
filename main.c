//
//  main.c
//  Flame_Fractal
//
//  Created by Bunny on 1/2/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/malloc.h>
#include <pthread.h>
#include "tiffio.h"
#include <string.h>
#include <time.h>
#include "fractal.h"
int
main (int argc, char **argv)
{
    
    flame fractal;
    int i;
    pthread_t *threads;
    
    /* initialize our Flame Fractal */
    printf ("Initializing...\n");
    fractal_init (&fractal);
    printf ("Initialized!\n");
    /* parse arguments from the command line */
    printf ("Parsing user arguments...\n");
    parse_args (argc, argv, &fractal);
    printf ("Done!\n");
    /* seed the randomizer */
    srandom (fractal.seed);
    srand48 (random ());
    /* initalize the random coefficients */
    printf ("Initialzing Coefficients and Colors...\n");
    coeff_init (&fractal);
    printf ("Done!\n");
    /* allocate our memory buffer */
    printf ("Allocating memory...\n");
    buffer_init (&fractal);
    printf ("Done!\n");
    /* correct for threads */
    if (fractal.num_threads <= 0)
    {
        fractal.num_threads = 1;
    }
    threads = (pthread_t *) malloc (fractal.num_threads * sizeof (pthread_t));
    if (threads == NULL)
    {
        printf ("Error: malloc() failed in main.\n");
        exit (EXIT_FAILURE);
    }
    fractal.samples /= fractal.num_threads;
    /* render the image */
    for (i = 0; i < fractal.num_threads; i++)
    {
        printf ("Spawing thread %d\n", i);
        if (0 != pthread_create (&threads[i], NULL, render, (void *) &fractal))
            exit (EXIT_FAILURE);
    }
    
    for (i = 0; i < fractal.num_threads; i++)
    {
        printf ("Joining thread %d\n", i);
        if (0 != pthread_join (threads[i], NULL))
            exit (EXIT_FAILURE);
    }
    /* gamma and log correct */
    printf ("Finializing and writing out...\n");
    gamma_log (&fractal);
    if (fractal.sup > 1)
    {
        reduce (&fractal);
    }
    /* write out the file */
    /*gamma_log (&fractal); */
    write_to_tiff (&fractal);
    /* clean up */
    free (threads);
    free (fractal.lock);
    free (fractal.coarray);
    free (fractal.choice);
    free (fractal.pixels);
    printf ("Done!\n");
    return 0;
}
