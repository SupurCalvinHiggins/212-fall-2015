#pragma once
#include <string>
#include <vector>
#include <cstdint>

using u32 = uint32_t;

struct Component {
    std::string name;

    explicit Component(std::string&& name) : name(name) { }
};

struct Device {
    std::vector<Component> components;
    std::vector<std::pair<Component, Component>> connections;

    Device(std::vector<Component>&& components, std::vector<std::pair<Component, Component>>&& connections) : components(components), connections(connections) { }
};

[[nodiscard]] u32 strategic_silicon(const Device& device, size_t height, size_t width);

