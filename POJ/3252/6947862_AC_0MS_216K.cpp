#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;
int start , finish ;
int s[50] , f[50] ;
int c[33][33] ;
void init_c()
{
    c[0][0] = 1 ;
    int i , j ; 
    for ( i = 1 ; i <= 32 ; i ++ )
    {
        c[i][0] = 1 ;
        c[i][i] = 1 ;    
    }
    
    for ( i = 2 ; i <= 32 ; i ++ )
        for ( j = 1 ; j < i ; j ++ )
            c[i][j] = c[i-1][j-1] + c[i-1][j] ;
        
}
int do1( int num1 , int num0 , int l )
{
     int t0 ;
     if( num1 > num0 )
     {
         if ( l < ( num1 - num0 ) )
            return 0 ;
         t0 = ( l - ( num1 - num0 ) + 1 ) / 2 + ( num1 - num0 ) ;     
     } 
     else 
     {
          if ( l < num0 - num1 )
             t0 = 0 ;
          else 
             t0 = ( l - ( num0 - num1 ) + 1 ) / 2 ;     
     } 
     int i ;
     int s = 0 ;
     for ( i = t0 ; i <= l ; i ++ )
         s += c[l][i] ;
     return s ;
}
int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out1.txt", "w", stdout);
    int i ;
    init_c( ) ;
    cin >> start >> finish ;
    int cnt1 , cnt2 ;
    int t1 = start ;
    cnt1 = 0 ;
    while ( t1 )
    {
        s[++cnt1] = t1 % 2 ;
        t1 /= 2 ;       
    }
    t1 = finish ;
    cnt2 = 0 ;
    while ( t1 )
    {
          f[++cnt2 ] = t1 % 2 ;
          t1 /= 2 ;      
    }
    
    int ss = 0 ;
    int n1 , n0 ;
    if( cnt1 == cnt2 )
    {
        int ss1 , ss2 ;
        ss1 = ss2 = 0 ;
        n1 = 1 ; 
        n0 = 0 ;
        for ( i = cnt2 - 1 ; i > 0 ; i -- )
        {
            if ( f[i] == 0 ) 
               n0 ++ ;
            
            if ( f[i] == 1 )
            {
               ss1 += do1( n1 , n0 + 1 , i - 1 ); 
               n1 ++ ;    
            } 
            if ( i == 1 && n1 <= n0 )
               ss1 ++ ; 
        }     
        n1 = 1 ; 
        n0 = 0 ;
        for ( i = cnt1 - 1 ; i > 0 ; i -- )
        {
            if ( s[i] == 0 ) 
               n0 ++ ;
            
            if ( s[i] == 1 )
            {
               ss2 += do1( n1 , n0 + 1 , i - 1 ); 
               n1 ++ ;    
            } 
            if ( i == 1 && n1 <= n0 )
               ss2 ++ ; 
        }
        if ( n1 <= n0 )
           ss2 --; 
        cout << ( ss1 - ss2 ) << endl ;   
    }
    else{
    for ( i = cnt1 + 1 ; i < cnt2 ; i ++ )
        ss += do1( 1 , 0 , i - 1 ) ;
    
    n0 = 0 ;
    n1 = 1 ;
    for ( i = cnt1 - 1 ; i > 0 ; i -- )
    {
        if ( s[i] == 1 )
           n1 ++ ; 
        
        if ( s[i] == 0 )
        {
           ss += do1( n1 + 1 , n0 , i - 1 );
           n0 ++ ;     
        }   
        if ( i == 1 && n1 <= n0 )
           ss ++ ;
    }
    
    n1 = 1 ;
    n0 = 0 ;
    for ( i = cnt2 - 1 ; i > 0 ; i -- )
    {
        if ( f[i] == 0 ) 
           n0 ++ ;
       
        if ( f[i] == 1 )
        {
           ss += do1( n1 , n0 + 1 , i - 1 ); 
           n1 ++ ;    
        }
         if ( i == 1 && n1 <= n0 )
           ss ++ ;    
    }
    cout << ss << endl ;}
   // system( "pause" );
    return 0 ;    
    
}
