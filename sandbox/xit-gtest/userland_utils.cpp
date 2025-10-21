#include "userland_utils.hpp"

nlohmann::json nil::xit::buffer_type<nlohmann::json>::deserialize(
    const void* data,
    std::uint64_t size
)
{
    return nlohmann::json::from_msgpack(std::string_view(static_cast<const char*>(data), size));
}

std::vector<std::uint8_t> nil::xit::buffer_type<nlohmann::json>::serialize(
    const nlohmann::json& value
)
{
    return nlohmann::json::to_msgpack(value);
}

void nlohmann::adl_serializer<Circle>::to_json(nlohmann::json& j, const Circle& v)
{
    j = nlohmann::json::object({{"position", v.position}, {"radius", v.radius}});
}

void nlohmann::adl_serializer<Circle>::from_json(const nlohmann::json& j, Circle& v)
{
    using nlohmann::json;
    v.position = j.value(json::json_pointer("/position"), std::array<double, 2>());
    v.radius = j.value(json::json_pointer("/radius"), 0.0);
}

void nlohmann::adl_serializer<Circles>::to_json(nlohmann::json& j, const Circles& v)
{
    j = nlohmann::json::object({{"x", v.x}, {"y", v.y}});
}

void nlohmann::adl_serializer<Circles>::from_json(const nlohmann::json& j, Circles& v)
{
    v.x = j.value(nlohmann::json::json_pointer("/x"), Circle{});
    v.y = j.value(nlohmann::json::json_pointer("/y"), Circle{});
}

void nlohmann::adl_serializer<Ranges>::to_json(nlohmann::json& j, const Ranges& v)
{
    j = nlohmann::json::array({v.v1, v.v2, v.v3});
}

void nlohmann::adl_serializer<Ranges>::from_json(const nlohmann::json& j, Ranges& v)
{
    // NOLINTNEXTLINE
    v.v1 = (j.size() < 1) ? 0 : j[0].get<std::int64_t>();
    v.v2 = (j.size() < 2) ? 0 : j[1].get<std::int64_t>();
    v.v3 = (j.size() < 3) ? 0 : j[2].get<std::int64_t>();
}
