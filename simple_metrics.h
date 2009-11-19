/**
 * http://www.opensource.org/licenses/isc-license.txt
 *
 * Copyright (c) 2009, Jeremy Hinegardner
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __SIMPLE_METRICS_H__
#define __SIMPLE_METRICS_H__
#include <stdlib.h>
#include <math.h>

typedef struct _simple_metrics{
    double      min;
    double      max;
    double      sum;
    double      sumsq;
    long        count;
} simple_metrics ;

simple_metrics* simple_metrics_new();
void            simple_metrics_free(   simple_metrics* sm );
void            simple_metrics_update( simple_metrics* sm, double value );

long            simple_metrics_count(  simple_metrics* sm );
double          simple_metrics_max(    simple_metrics* sm );
double          simple_metrics_mean(   simple_metrics* sm );
double          simple_metrics_min(    simple_metrics* sm );
double          simple_metrics_rate(   simple_metrics* sm );
double          simple_metrics_sum(    simple_metrics* sm );
double          simple_metrics_sumsq(  simple_metrics* sm );
double          simple_metrics_stddev( simple_metrics* sm );

#endif
