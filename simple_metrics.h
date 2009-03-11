/**
 * Copyright (c) 2009 Jeremy Hinegadner
 * All rights reserved.  See LICENSE and/or COPYING for details
 *
 * vim: shiftwidth=4
 */

#ifndef __SIMPLE_METRICS_H__
#define __SIMPLE_METRICS_H__
#include <stdlib.h>
#include <math.h>

typedef struct _simple_metrics{
    double min;
    double max;
    double sum;
    double sumsq;
    long   count;
} simple_metrics ;

simple_metrics* simple_metrics_new();
void            simple_metrics_update( simple_metrics* sm, double value );
double          simple_metrics_mean(   simple_metrics* sm );
double          simple_metrics_min(    simple_metrics* sm );
double          simple_metrics_max(    simple_metrics* sm );
double          simple_metrics_sum(    simple_metrics* sm );
long            simple_metrics_count(  simple_metrics* sm );
double          simple_metrics_stddev( simple_metrics* sm );
double          simple_metrics_rate(   simple_metrics* sm );

#endif
