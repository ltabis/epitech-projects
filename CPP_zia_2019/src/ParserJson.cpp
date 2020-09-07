/*
** EPITECH PROJECT, 2018
** zia
** File description:
** Created by elian.nicaise,
*/

#include "ParserJson.hpp"

zia::ParserJson::ParserJson()
{

}

zia::ParserJson::~ParserJson()
{

}

void zia::ParserJson::SetJsonString(const rapidjson::Value &obj, api::JsonString)
{

}

void zia::ParserJson::SetJsonNumber(const rapidjson::Value &obj, api::JsonNumber)
{

}

void zia::ParserJson::SetJsonBool(const rapidjson::Value &obj, api::JsonBool)
{

}


int zia::ParserJson::ParseArray(const rapidjson::Value &obj)
{
    for (rapidjson::SizeType i = 0; i < obj.Size(); i++)
    {
        const rapidjson::Value &c = obj[i];
        for (auto &v : c.GetObject())
        { //iterate through array object
            if (c[v.name.GetString()].IsString()) //if array object value is string
                std::cout << v.name.GetString() << ": "
                    << c[v.name.GetString()].GetString() << std::endl;
            else //if array object value is integer
                std::cout << v.name.GetString() << ": "
                    << c[v.name.GetString()].GetInt() << std::endl;
        }
        std::cout << std::endl;
    }
    return (0);
}

int zia::ParserJson::ParseData(const rapidjson::Value &obj)
{
    if (obj.IsString())
        std::cout << obj.GetString() << std::endl;
    if (obj.IsArray())
        ParseArray(obj);
    if (obj.IsObject())
    { //check if object
        for (auto &itr: obj.GetObject())
        {
            const rapidjson::Value &objName = obj[itr.name.GetString()]; //make object value
            std::cout << itr.name.GetString() << ": "; //key name
            if (itr.value.IsNumber()) //if integer
                std::cout << itr.value.GetInt();
            else if (itr.value.IsString()) //if string
                std::cout << itr.value.GetString();
            else if (itr.value.IsBool()) //if bool
                std::cout << itr.value.GetBool();
            else if (itr.value.IsArray()) { //if array
                for (rapidjson::SizeType i = 0; i < itr.value.Size(); i++)
                {
                    if (itr.value[i].IsNumber()) //if array value integer
                        std::cout << itr.value[i].GetInt();
                    else if (itr.value[i].IsString()) //if array value string
                        std::cout << itr.value[i].GetString();
                    else if (itr.value[i].IsBool()) //if array value bool
                        std::cout << itr.value[i].GetBool();
                    else if (itr.value[i].IsObject())//if array value object
                        ParseArray(obj);
                }
            }
            std::cout << std::endl;
        }
            std::cout << std::endl;
    }
    std::cout << std::endl;
    return (0);
}

api::JsonType zia::ParserJson::getData(const std::string &path)
{
    std::ifstream ifs(path);
    rapidjson::Document document;
    rapidjson::IStreamWrapper isw(ifs);
    api::JsonType JsonFile;

    if (ifs.is_open()) {
        document.ParseStream(isw);
        for (auto &m : document.GetObject()) {
            std::cout << m.name.GetString() << std::endl;
            ParseData(m.value);
        }
    }

    return JsonFile;
}