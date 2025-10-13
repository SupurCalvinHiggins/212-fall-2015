#pragma once
#include <vector>

struct Song {
    size_t duration;

    explicit Song(size_t duration) : duration(duration) { }
};

struct Playlist {
    std::vector<Song> songs;

    explicit Playlist(std::vector<Song>&& songs) : songs(songs) { }
};

[[nodiscard]] size_t playlist_period(const Playlist& playlist);