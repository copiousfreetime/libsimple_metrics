/**
 * Copyright (c) 2009 Jeremy Hinegadner
 * All rights reserved.  See LICENSE and/or COPYING for details
 *
 * vim: shiftwidth=4
 */

#include "simple_metrics.h"
#include <stdio.h>

simple_metrics* simple_metrics_new( )
{
    simple_metrics *sm = calloc( 1, sizeof( simple_metrics ) );

    if ( NULL != sm ) {
        sm->sum     = 0.0;
        sm->sumsq   = 0.0;
        sm->count   = 0;
    }
}

void simple_metrics_free( simple_metrics* sm )
{
	free( sm );
}

void simple_metrics_update( simple_metrics* sm, double value )
{
    if ( 0 == sm->count ) {
        sm->min = value;
        sm->max = value;
    } else {
        sm->min = ( value < sm->min ) ? ( value ) : ( sm->min );
        sm->max = ( value > sm->max ) ? ( value ) : ( sm->max );
    }

    sm->count += 1;
    sm->sum   += value;
    sm->sumsq += ( value * value );
    return;
}

double simple_metrics_min( simple_metrics* sm )
{
    return (sm->min);
}

double simple_metrics_max( simple_metrics* sm )
{
    return (sm->max);
}

double simple_metrics_sum( simple_metrics* sm )
{
    return (sm->sum);
}

long simple_metrics_count( simple_metrics* sm )
{
    return (sm->count);
}

double simple_metrics_mean( simple_metrics* sm )
{
    double mean = 0.0;

    if ( sm->count > 0 ) {
        mean = sm->sum / sm->count;
    } 

    return mean;
}

double simple_metrics_rate( simple_metrics* sm )
{
    double rate = 0.0;

    if ( sm->sum != 0.0 ) {
        rate = sm->count / sm->sum;
    }
    return rate;
}

double simple_metrics_stddev( simple_metrics* sm )
{
    double stddev = 0.0;

    if ( sm->count > 1 ) {
        stddev = sqrt( ( sm->sumsq - (sm->sum * sm->sum / sm->count) ) / (sm->count - 1));
    }
    return stddev;
}
