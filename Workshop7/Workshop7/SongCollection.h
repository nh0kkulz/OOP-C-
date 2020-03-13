// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: November 12,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SONG_COLLECTION_H
#define SONG_COLLECTION_H
#include <iostream>
#include <vector>
#include <list>
namespace sdds
{
	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		int m_year{};
		size_t m_length{};
	};
	class SongCollection {
		std::vector <Song> collection;
	public:
		SongCollection(const char* file);
		void display(std::ostream& out) const;
		void trim(std::string& str);
		void sort(const std::string&);
		void cleanAlbum();
		bool inCollection(const std::string&) const;
		std::list<Song> getSongsForArtist(const std::string& a) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif