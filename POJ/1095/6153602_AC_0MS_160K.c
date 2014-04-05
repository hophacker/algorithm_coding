#include <stdio.h>
#include <string.h>

long num[ 30 ];

/* to compute the number of t node-rooted binary trees */
/* f[ t ] is the number of t node-rooted biary trees */
/* init routine compute the first 30 nodes */
void init() {
int t = 0, i;
long s = 0;
memset( num, 0, sizeof( num ) );

num[ 0 ] = 1;
/*
   * the number of n-node-rooted tree is Catlan number
   * num[ i ] = C(2i, i) / (i-1), where C(n, m) is combination
   * number. But direct computation is complex, it concerns about
   * big number arithmetic operation.
   * we use the following loop to compute it.
   */
while ( 1 ) {
    ++t;
    for ( i = 0; i < t; i++ ) {
      num[ t ] += num[ i ] * num[ t-i-1 ];
    }
    s += num[ i ];
    if ( s > 500000000 ) {
      break;
    }
}
}
/* this routine build and print the tree with node and order */
void build( int node, long order ) {
int i = node - 1;
long k;
/* 
   * i is the number of nodes in right subtree, 
   * while t-i-1 is the number of nodes in left subtree.
   */
k = num[ i ] * num[ node-i-1 ];
while ( order > k ) {
    order -= k;
    --i;
    k = num[ i ] * num[ node-i-1 ];
}

/* left subtree existing */
if ( node-i-1 > 0 ) {
    putchar( '(' );
    /* compute the order of left subtree */
    k = order / num[ i ];
    if ( order % num[ i ] != 0 ) {
      k++;
    }
    /* build left subtree */
    build( node-i-1, k );
    putchar( ')' );
}
putchar( 'X' );

/* right subtree existing */
if ( i > 0 ) {
    putchar( '(' );
    k = ( order-1 ) % num[ i ] + 1;
    /* build right subtree */
    build( i, k );
    putchar( ')' );
}
}

int main( void ) {
int i;
long n;
init();
while ( scanf( "%ld", &n ) != EOF && n != 0 ) {
    i = 1;
    /* find the number of nodes whose order is n */
    while ( n > num[ i ] ) {
      n -= num[ i ];
      i++;
    }
    /* node is i and order is n, build it */
    build( i, n );
    putchar( '\n' );
}
return 0;
}
