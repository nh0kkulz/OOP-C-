// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: November 12,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include "SongCollection.h"
using namespace std;
namespace sdds {
	SongCollection::SongCollection(const char* file) {
		std::ifstream f(file);
		if (!f)
			throw "Invalid File";
		while (!f.eof()) {
			Song song;
			std::string buffer;
			getline(f, buffer);
			trim(song.m_title = buffer.substr(0, 25));
			trim(song.m_artist = buffer.substr(25, 25));
			trim(song.m_album = buffer.substr(50, 25));
			try {
				song.m_year = stoi(buffer.substr(75, 5));
			}
			catch (...) {
				song.m_year = 0;
			}
			song.m_length = stoi(buffer.substr(80, 5));
			song.m_price = stod(buffer.substr(85, 5));
			collection.push_back(song);
		}
	}
	void SongCollection::trim(string& str) {
		size_t i;
		for (i = 0u; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);
		for (i = str.length(); i > 0 && str[i-1] == ' '; i--);
		str = str.substr(0, i);
	}
	void SongCollection::display(std::ostream& out) const {
		for_each(collection.begin(), collection.end(), [&out](const Song& s) {out << s; });
		size_t total;
		total = accumulate(collection.begin(), collection.end(), 0, [](int i, const Song&a) {return i + a.m_length; });
		int hour = total / 3600;
		int minute = (total - hour * 3600) / 60;
		int second = (total - hour * 3600) % 60;
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::setw(78) << "Total Listening Time: " << hour << ":" << minute << ":" << second << std::right << "|\n";
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	}
	void SongCollection::cleanAlbum() {
		for_each(collection.begin(), collection.end(), [](Song& s) {if (s.m_album == "[None]") s.m_album = ""; });
	}
	bool SongCollection::inCollection(const std::string& art) const {
		return any_of(collection.begin(), collection.end(), [&art](const Song&s) {return s.m_artist == art; });
	}
	std::list<Song> SongCollection::getSongsForArtist(const string& a) const {
		int count;
		count = count_if(collection.begin(), collection.end(), [&a](const Song& s) {return s.m_artist == a; });
		list<Song> temp(count);
		copy_if(collection.begin(), collection.end(), temp.begin(), [&a](const Song& s) {return s.m_artist == a; });
		return temp;
	}
	void SongCollection::sort(const std::string& p) {
		if(p=="album")
			std::sort(collection.begin(), collection.end(), [](const Song& a, const Song& b) {return a.m_album < b.m_album; });
		else if(p=="title")
			std::sort(collection.begin(), collection.end(), [](const Song& a, const Song& b) {return a.m_title < b.m_title; });
		else
			std::sort(collection.begin(), collection.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << left << setw(20) << theSong.m_title << " | " << setw(15) << theSong.m_artist << " | " << setw(20) << theSong.m_album << " | "
			<< setw(6) << right;
		if (theSong.m_year == 0) {
			out << "" << " | " << theSong.m_length/60 << ":" << setw(2) << setfill('0') << theSong.m_length%60 << " | " << theSong.m_price << " |" << setfill (' ') << endl;
		}
		else {
			out << theSong.m_year << " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60 << " | " << theSong.m_price << " |" << setfill(' ') << endl;
		}
		return out;
	}
}