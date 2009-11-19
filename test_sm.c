#include <simple_metrics.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char ** argv )
{
    int iterations     = 10000;
    int i              = 0;

    simple_metrics* sm = simple_metrics_new();

    if ( argc > 1 ) {
        iterations = atol( argv[1] );
    }

    printf("Running for %d iterations\n", iterations );

	srandomdev();

    for( i = 0 ; i < iterations ; i++ ) {
		double d = (double)random();
        simple_metrics_update( sm, d );
    }
;
    printf( "Count  : %ld\n"   ,  simple_metrics_count( sm ) );
    printf( "Min    : %0.5lf\n", simple_metrics_min( sm ) );
    printf( "Max    : %0.5lf\n", simple_metrics_max( sm ) );
    printf( "Sum    : %0.5lf\n", simple_metrics_sum( sm ) );
    printf( "Mean   : %0.5lf\n", simple_metrics_mean( sm ) );
    printf( "Rate   : %0.5lf\n", simple_metrics_rate( sm ) );
    printf( "Stddev : %0.5lf\n", simple_metrics_stddev( sm ) );

	simple_metrics_free( sm );

    return 0;
}

