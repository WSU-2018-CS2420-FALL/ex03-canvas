#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "library.h"
#include "print.h"
#include "audio.h"
#include "patron.h"

TEST_CASE("Library Test") {
  Library lib;

  Book *b = new Print("Animal Farm", "987-987-998", "George Orwell", 350);
  Audio *a = new Audio("harry potter and the sorcerer's stone", "348-342-546", "J. K. Rowling", 16.5);

  Patron p("Jim Carrey");
  REQUIRE(lib.books().size() == 0);
  lib.books().items().push_back(b);
  REQUIRE(lib.books().size() == 1);
  lib.books().items().push_back(a);
  REQUIRE(lib.books().size() == 2);

  REQUIRE(lib.patrons().size() == 0);
  lib.patrons().items().push_back(&p);
  REQUIRE(lib.patrons().size() == 1);

  REQUIRE(lib.transactions().size() == 0);
  lib.checkout(b, &p);
  REQUIRE(lib.transactions().size() == 1);
  lib.checkout(a, &p);
  REQUIRE(lib.transactions().size() == 2);
  lib.checkin(b);
  REQUIRE(lib.transactions().size() == 1);
  lib.checkin(b);
  REQUIRE(lib.transactions().size() == 1);

  delete b;
  delete a;
}