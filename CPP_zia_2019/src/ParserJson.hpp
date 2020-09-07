/*
** EPITECH PROJECT, 2018
** zia
** File description:
** Created by elian.nicaise,
*/

#pragma once

#include "Types.hpp"
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

namespace zia {
    class ParserJson
    {
    public:
        ParserJson();
        ~ParserJson();
        api::JsonType getData(const std::string &);

    private:
        int ParseArray(const rapidjson::Value &obj);
        int ParseData(const rapidjson::Value &obj);
        void SetJsonString(const rapidjson::Value &obj, api::JsonString);
        void SetJsonNumber(const rapidjson::Value &obj, api::JsonNumber);
        void SetJsonBool(const rapidjson::Value &obj, api::JsonBool);
    };
}