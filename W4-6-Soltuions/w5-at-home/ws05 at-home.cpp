// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}
		std::string strBook;
		for (auto i = 0u; i < 4; ++i)
		{
			std::getline(file, strBook);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strBook[0] != '#')
					library += Book(strBook);
				else
					--i;
			}
		}

		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the book from the file.
		for (auto i = 0u; i < 3; ++i)
		{
			std::getline(file, strBook);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strBook[0] != '#')
					library += Book(strBook);
			}
		}

		file.close();
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto fixPrice = [=](Book& book)
	{
		if (book.country() == "US")
			book.price() *= usdToCadRate;
		else if (book.country() == "UK" and 1990 <= book.year() and book.year() < 2000)
			book.price() *= gbpToCadRate;
	};
	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from in-lab): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto i = 0u; i < library.size(); ++i)
	{
		fixPrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream file(argv[2]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}
		std::string strMovie;
		for (auto i = 0u; i < sizeof(movies) / sizeof(movies[0]); /*Nothing*/)
		{
			std::getline(file, strMovie);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strMovie[0] != '#')
					movies[i++] = Movie(strMovie);
			}
		}
		file.close();
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	// Add a few movies to collection; no observer is set
	((theCollection += movies[0]) += movies[1]) += movies[2];
	theCollection += movies[1];
	// add more movies; now we get a callback from the collection
	theCollection.setObserver(movieAddedObserver);
	theCollection += movies[3];
	theCollection += movies[3];
	theCollection += movies[4];
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";
	try
	{
		// TODO: The following loop can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		for (auto i = 0u; i < 10; ++i)
			std::cout << theCollection[i];
	}
	catch (std::out_of_range error)
	{
		std::cout << "EXCEPTION: " << error.what() << "\n";
	}
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3u; i <= 4u; ++i)
	{
		try
		{
			// TODO: The following statement can generate generate an exception
			//         write code to handle the exception
			//       If an exception occurs print a message in the following format
			//EXCEPTION: ERROR_MESSAGE<endl>
			//         where ERROR_MESSAGE is extracted from the exception object.
			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
		}
		catch (const char* error)
		{
			std::cout << "EXCEPTION: " << error << "\n";
		}
	}
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
/*
Command Line:
--------------------------
  1: w05.exe
  2: books.txt
  3: movies.txt
  4: missing.txt
  5: words.txt
--------------------------

Book "Harry Potter" added!
Book "The Da Vinci Code" added!
Book "The Catcher in the Rye" added!
-----------------------------------------
The library content
-----------------------------------------
 Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.
	 Charles Dickens |   A Tale of Two Cities |    UK | 1859 |  12.32 | A historical novel, set in London and Paris at the begiming and during the French Revolution.
  George R.R. Martin | A Song of Ice and Fire |    US | 1997 |  99.90 | Nine noble famillies begim fighting for control over the mythical lands of Westeros.
	  J.R.R. Tolkien |  The Lord of the Rings |    UK | 1993 |  21.11 | Sauron has gathered to him all the Rings of Power, and he intends to use them to rule Middle-earth.
		J.K. Rowling |           Harry Potter |    UK | 1997 |  45.99 | Harry realizes his life is far from ordinary.
		   Dan Brown |      The Da Vinci Code |    US | 2003 |   7.88 | While in Paris, Harvard symbologist Robert Langdon is awakened by a phone call in the night.
	   J.D. Salinger | The Catcher in the Rye |    US | 1951 |  12.21 | The story of a teen named Holden Caulfield and his struggle to find his voice in an adult world.
-----------------------------------------

-----------------------------------------
The library content (updated prices)
-----------------------------------------
 Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.
	 Charles Dickens |   A Tale of Two Cities |    UK | 1859 |  12.32 | A historical novel, set in London and Paris at the begiming and during the French Revolution.
  George R.R. Martin | A Song of Ice and Fire |    US | 1997 | 129.87 | Nine noble famillies begim fighting for control over the mythical lands of Westeros.
	  J.R.R. Tolkien |  The Lord of the Rings |    UK | 1993 |  31.66 | Sauron has gathered to him all the Rings of Power, and he intends to use them to rule Middle-earth.
		J.K. Rowling |           Harry Potter |    UK | 1997 |  68.98 | Harry realizes his life is far from ordinary.
		   Dan Brown |      The Da Vinci Code |    US | 2003 |  10.24 | While in Paris, Harvard symbologist Robert Langdon is awakened by a phone call in the night.
	   J.D. Salinger | The Catcher in the Rye |    US | 1951 |  15.87 | The story of a teen named Holden Caulfield and his struggle to find his voice in an adult world.
-----------------------------------------

-----------------------------------------
Testing addition and callback function
-----------------------------------------
Movie "Star Wars: The Rise of Skywalker" added to collection "Action Movies" (4 items).
Movie "Terminator: Dork Fate" added to collection "Action Movies" (5 items).
-----------------------------------------

-----------------------------------------
Testing exceptions and operator[]
-----------------------------------------
						 Game of Thrones | 2011 | Nine noble famillies begim fighting for control over the mythical lands of Westeros.
					   Avengers: Endgame | 2019 | With the help of remaining allies, the Avengers assemble once more in order to reverse Thanos' actions.
							Dork Phoenix | 2019 | Jean Grey begims to develop incredible Dork powers that corrupt and turn her into a Dork Phoenix.
		Star Wars: The Rise of Skywalker | 2019 | The surviving Resistance faces the First Order once more in the final chapter of the Skywalker saga.
				   Terminator: Dork Fate | 2019 | Sarah Connor and a hibrid cyborg human must protect a young girl from a newly modiffied liquid Terminator.
EXCEPTION: Bad index [5]. Collection has [5] items.
-----------------------------------------

-----------------------------------------
Testing the functor
-----------------------------------------
EXCEPTION: Bad file name!
--------------- Movies ------------------
						 Game of Thrones | 2011 | Nine noble families begin fighting for control over the mythical lands of Westeros.
					   Avengers: Endgame | 2019 | With the help of remaining allies, the Avengers assemble once more in order to reverse Thanos' actions.
							Dark Phoenix | 2019 | Jean Grey begins to develop incredible Dark powers that corrupt and turn her into a Dark Phoenix.
		Star Wars: The Rise of Skywalker | 2019 | The surviving Resistance faces the First Order once more in the final chapter of the Skywalker saga.
				   Terminator: Dark Fate | 2019 | Sarah Connor and a hybrid cyborg human must protect a young girl from a newly modified liquid Terminator.
--------------- Books -------------------
 Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.
	 Charles Dickens |   A Tale of Two Cities |    UK | 1859 |  12.32 | A historical novel, set in London and Paris at the begining and during the French Revolution.
  George R.R. Martin | A Song of Ice and Fire |    US | 1997 | 129.87 | Nine noble families begin fighting for control over the mythical lands of Westeros.
	  J.R.R. Tolkien |  The Lord of the Rings |    UK | 1993 |  31.66 | Sauron has gathered to him all the Rings of Power, and he intends to use them to rule Middle-earth.
		J.K. Rowling |           Harry Potter |    UK | 1997 |  68.98 | Harry realizes his life is far from ordinary.
		   Dan Brown |      The Da Vinci Code |    US | 2003 |  10.24 | While in Paris, Harvard symbologist Robert Langdon is awakened by a phone call in the night.
	   J.D. Salinger | The Catcher in the Rye |    US | 1951 |  15.87 | The story of a teen named Holden Caulfield and his struggle to find his voice in an adult world.
-----------------------------------------

-----------------------------------------
Testing operator[] (the other overload)
-----------------------------------------
Movie Terminator 2 not in collection.
In collection:
							Dark Phoenix | 2019 | Jean Grey begins to develop incredible Dark powers that corrupt and turn her into a Dark Phoenix.
-----------------------------------------
*/

// a lambda that fixes prices for Books (convert to CAD)
//  - books published in US have the price in USD (American Dollars)
//  - books published in UK in the '90s have the price in GBP (British Pounds)

// a functor that fixes spelling in the description
//  - constructor loads misspelled words from a file "spelling error -> correction"
//  - throws an exception if the file doesn't exist
//  - throws an exception if the file has wrong format

// a dynamic Collection class, of template types
//  - add items to the collection using +=
//  - access elements using []
//  - doesn't support copy & move operations
//  - a callback function to be called on successful adition (if an item with the same title is already in the list, don't add it)
