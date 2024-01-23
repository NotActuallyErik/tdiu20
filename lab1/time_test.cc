#include "catch.hpp"
#include "Time.h"

using namespace std;

TEST_CASE ("Constructors and getters")
{
   SECTION("Default")
   {
      Time empty{};
      CHECK( empty.get_hour()   == 0 );
      CHECK( empty.get_minute() == 0 );
      CHECK( empty.get_second() == 0 );
   }
/* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----

   SECTION("Integer")
   {
      Time t0{0,0,0};
      Time t1{12,30,30};
      Time t2{23,59,59};

      CHECK_THROWS( Time{13,35,60} );
      CHECK_THROWS( Time{13,60,35} );
      CHECK_THROWS( Time{24,35,35} );
             
      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );
   }
*/
/* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----

   SECTION("String")
   {
      Time t0{"00:00:00"};
      Time t1{"12:30:30"};
      Time t2{"23:59:59"};

      CHECK_THROWS( Time{"13:35:60"} );
      CHECK_THROWS( Time{"13:60:35"} );
      CHECK_THROWS( Time{"24:35:35"} );

      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );  
   }
*/
}
/* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----
TEST_CASE ("is_am") 
{
   Time t0{"05:00:00"};
   Time t1{"14:00:00"};
   Time t2{"12:00:00"};
   Timo t4{"00:00:00"};
   CHECK       ( t0.is_am() );
   CHECK_FALSE ( t1.is_am() );
   // Fill with extra corner cases!
}
*/
/* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----

TEST_CASE ("to_string")
{
   Time t0{};
   Time t1{11, 59, 59};
   Time t2{12, 0, 0};
   Time t3{13, 0, 0};
   Time t4{23, 59, 59};
   SECTION("24 hour format no argument")
   {
      CHECK( t0.to_string() == "00:00:00" );
      CHECK( t1.to_string() == "11:59:59" );
      CHECK( t2.to_string() == "12:00:00" );
      CHECK( t3.to_string() == "13:00:00" );
      CHECK( t4.to_string() == "23:59:59" );
      // Fill with more tests!
   }
   
   SECTION("24 hour format with argument")
   {
      CHECK( t0.to_string(false) == "00:00:00" );
      CHECK( t1.to_string(false) == "11:59:59" );
      CHECK( t2.to_string(false) == "12:00:00" );
      CHECK( t3.to_string(false) == "13:00:00" );
      CHECK( t4.to_string(false) == "23:59:59" );
   } 

   SECTION("12 hour format")
   {
      CHECK( t0.to_string(true) == "00am:00:00" );
      CHECK( t1.to_string(true) == "11am:59:59" );
      CHECK( t2.to_string(true) == "12pm:00:00" );
      CHECK( t3.to_string(true) == "13pm:00:00" );
      CHECK( t4.to_string(true) == "23pm:59:59" );
   }
}

TEST_CASE ("operators")
{
   Time t0{}
   Time t1{11, 59, 59};
   Time t2{23, 59, 59};
   Time t4{0,  0,  0}

   SECTION("Arithmetic operators")
   {
      SECTION("increment & decrement")
      {
         CHECK( t0++.to_string() == "00:00:01" );
         CHECK( t0--.to_string() == "00:00:00" );
         CHECK( ++t0.to_string() == "00:00:01" );
         CHECK( --t0.to_string() == "00:00:00" );
         CHECK( t1++.to_string() == "12:00:00" );
         CHECK( t2++.to_string() == "00:00:00" );
         CHECK( t0--.to_string() == "23:59:59" );
      }

      SECTION("addition & subtraction by integers")
      {
         // Do we even want to do this?
      }
   }

   SECTION("Relational operators")
   {
      CHECK( t0 == t4 );
      CHECK( t0 != t1 );
      CHECK( t1 < t2  );
      CHECK( t2 > t1  );
      CHECK( t0 >= t4 );
      CHECK( t0 <= t4 );
      // Are there any potential edge-cases?
   }  

   SECTION("Assignment operators")
   {
      // This might not be in the scope of the lab tbh
   }





}

// Fill with more tests of other functions and operators!

*/
