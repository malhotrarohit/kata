// Attribute Parser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Refer to problem at -
// https://www.hackerrank.com/challenges/attribute-parser/problem
// Main Assumptions - 
// 1. HRML input is well formed as per HRML grammar
// 2. All queries are well formed as per HRML query grammar

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

// a tree like structure describing the parsed hrml file
struct Tag
{
public:
    std::string name;
    std::unordered_map<std::string, std::string> attributes;
    std::unordered_map<std::string, Tag*> subTags;
};

void DeleteNode(Tag* tag)
{
    if (tag != nullptr)
    {
        if (tag->subTags.size() > 0) 
        {
            std::unordered_map<std::string, Tag*>::iterator it = tag->subTags.begin();
            while (it != tag->subTags.end())
            {
                DeleteNode(it->second);
                it++;
            }
            tag->subTags.clear();
        }
        tag->attributes.clear();
        delete tag;
    }
}

int main()
{
    unsigned int numLinesHrml = 0;
    unsigned int numLinesQueries = 0;
    std::vector<Tag*> tags;
    Tag* root = nullptr;

    std::cin >> numLinesHrml >> numLinesQueries;
    std::cin.ignore();

    for (unsigned int i = 0; i < numLinesHrml; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        Tag* tag = new Tag();
        unsigned int prev = 0, pos = 0;
        std::string prevToken;
        std::string token;
        
        // this is an opening tag
        if (line[1] != '/')
        {
            while ((pos = line.find_first_of("<> =", prev)) != std::string::npos)
            {
                if (pos > prev)
                {
                    token = line.substr(prev, pos - prev);
                    if (tag->name.empty())
                    {
                        tag->name = token;
                    }
                    else
                    {
                        if (token[0] == '\"')
                        {
                            tag->attributes[prevToken] = (token.length() > 2 ? token.substr(1, token.length() - 2) : "");
                        }
                        else 
                        {
                            tag->attributes[token] = "";
                        }
                    }
                    prevToken = token;
                }
                // since hrml tags end with > prev would become greater than length of the input string by end
                prev = pos + 1;
            }
            if (!tags.empty())
            {
                tags.back()->subTags[tag->name] = tag;
            }
            tags.push_back(tag);
        }
        // this is a closing tag
        else 
        {
            // cache the root tag
            if (tags.size() == 1)
            {
                root = tags.back();
            }
            tags.pop_back();
        }
    }

    if (root != nullptr)
    {
        for (unsigned int i = 0; i < numLinesQueries; i++)
        {
            std::string query;
            std::getline(std::cin, query);
            Tag* tag = root;
            unsigned int prev = 0, pos = 0;
            std::string token;

            while ((pos = query.find_first_of(".~", prev)) != std::string::npos)
            {
                if (pos > prev)
                {
                    if (query[pos] == '.')
                    {
                        token = query.substr(prev, pos - prev);
                        if (token != root->name)
                        {
                            tag = tag->subTags[token];
                        }
                    }
                    else if (query[pos] == '~')
                    {
                        token = query.substr(prev, pos - prev);
                        if (tag->subTags.find(token) != tag->subTags.end())
                        {
                            tag = tag->subTags[token];
                        }

                        token = query.substr(pos + 1, query.length() - pos - 1);
                        break;
                    }
                }
                prev = pos + 1;
            }
            if (tag->attributes.find(token) != tag->attributes.end())
            {
                std::cout << tag->attributes[token] << std::endl;
            }
            else
            {
                std::cout << "Not Found!" << std::endl;
            }
        }

        DeleteNode(root);
        root = nullptr;
    }

    return 0;
}