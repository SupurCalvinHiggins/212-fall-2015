#pragma once
#include <vector>
#include <cstdint>
#include <cassert>

struct Song {
    uint32_t duration;

    explicit Song(uint32_t duration) : duration(duration) {
        assert(duration > 0);
    }
};

struct Playlist {
    std::vector<Song> songs;

    explicit Playlist(std::vector<Song> &&songs) : songs(songs) {
    }
};

[[nodiscard]] uint32_t playlist_period(const Playlist &playlist);
