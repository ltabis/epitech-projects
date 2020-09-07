#ifndef CPP_ZIA_2019_API_TYPES_HPP
#define CPP_ZIA_2019_API_TYPES_HPP

#include <string>
#include <vector>
#include <variant>
#include <map>
#include <unordered_map>

namespace api {

    using String = std::string;
    using StrArray = std::vector<String>;
    using Buffer = std::vector<char>;
    using Headers = std::unordered_map<String, String>;

    using Port = unsigned short;
    using IpV4 = unsigned int;


    struct JsonType;

    struct JsonNull {
        bool operator==(JsonNull const &) const { return true; }
    };

    using JsonString = std::wstring;
    using JsonNumber = double;
    using JsonBool = bool;
    using JsonArray = std::vector<JsonType>;
    using JsonObject = std::map<JsonString, JsonType>;

    using JsonValue = std::variant<JsonString, JsonNumber, JsonBool, JsonNull, JsonArray, JsonObject>;

    struct JsonType {
        bool operator==(JsonType const &other) const noexcept {return other._ == _;}
        template<typename T> T &as() {return std::get<T>(_);}
        template<typename T> const T &as() const {return std::get<T>(_);}

        JsonValue _;
    };

}

#endif /* CPP_ZIA_2019_API_TYPES_HPP */
