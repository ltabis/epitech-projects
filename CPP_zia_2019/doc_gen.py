#!/usr/bin/env python3

import getpass
import sys
import os

from datetime import date

# Parsing library
import CppHeaderParser

formats = {
    ## default header format
    "h_start":  "//",
    "h_middle": "//",
    "h_end":    "//",
    "h_author": "Unknown",
    "h_date":   "Unknown",
    "h_file":   "Unknown",

    ## default keywords
    "k_brief":  "/// \\brief",
    "k_return": "/// \\return",
    "k_param":  "/// \\param",

    "k_header": "///",
    "k_middle": "///",
    "k_footer": "///",

    "p_name": "project"
}

# Configuration reader class declaration
class ConfigReader:

    # Initialazing object
    def __init__(self, filepath):

        # path of the config file / file / map of values / len of file
        self.filepath = filepath
        self.dico = {}
        self.length = self.file_len()
        self.content = []

        with open(self.filepath) as file:
            for num, line in enumerate(file.readlines()):

                # getting content and removing useless characters
                self.content.append(line)
                if ':' in line:
                    newEntry = line.rstrip("\r\n").split(':', 1)
                    self.dico[newEntry[0]] = [num, newEntry[1]]

    # Get a variable from the dictionnary
    def get(self, variable):
        if variable in self.dico:
            return self.dico[variable][1]

    # Set a variable in the dictionnary and replace
    def set(self, variable, value):
        if variable in self.dico:
            self.dico[variable][1] = value

    # write the configuration in the current file
    def write(self):

        # open the file and write configuration
        with open(self.filepath, "w") as file:

            # Search lines to replace
            for num, line in enumerate(self.content):
                writen = False

                # Search in the dictionnary
                for data in self.dico:
                    if self.dico[data][0] == num:
                        file.write(data + ":" + self.dico[data][1] + "\n")
                        writen = True

                # The line isn't a config line
                if writen == False:
                    file.write(line)

    def file_len(self):
        with open(self.filepath) as file:
            for index, line in enumerate(file):
                pass
            return index + 1

    def get_all_keys(self):
        varList = []
        [varList.append(item[1]) for item in self.dico.values()]
        varList.reverse()
        return varList

    def get_all(self):
        varList = []
        [varList.append((key, item[1])) for item, key in zip(self.dico.values(), self.dico.keys())]
        varList.reverse()
        return varList

def changeDefault(key, value):

    if len(key) and len(value):
        formats[key] = value

def getConfig():

    files = ConfigReader("/usr/bin/docgen.conf")

    all_keywords = ConfigReader(files.get("keywords")).get_all()

    all_header = ConfigReader(files.get("header")).get_all()

    [changeDefault(keywords[0], keywords[1]) for keywords in all_keywords]
    [changeDefault(header[0], header[1]) for header in all_header]
    

def openFileToParse(filepath):

    ## Opening the header file
    try:
        parser = CppHeaderParser.CppHeader(filepath)
    except CppHeaderParser.CppParseError as error:
        print(error, file=sys.stderr)
        exit(1)

    ## Getting the file's content
    content = ""
    filename = ""
    with open(filepath, "r") as file:
        content = file.readlines()
        filename = file.name

    ## Parsing all methods
    methods = parseMethods(parser)

    ## getting all methods
    documentation = addMethods([], methods, content)

    ## Adding the header of the file
    documentation = addHeader(documentation, filename)

    ## rewriting the file with documentation
    openFileToWrite(filepath, documentation, content)

# Checks if the file exists
def openFileToWrite(filepath, documentation, content):

    ## We write from the last to the first methods lines to avoid computing an offset
    documentation.sort()
    documentation.reverse()

    print(documentation)

    ## Adding lines of documentation in the filegetIndentation
    [content.insert(line[0] - 1, line[1]) for line in documentation]

    content = "".join(content)
    with open(filepath, "w") as file:
        file.write(content)
        file.close()

def parseMethods(parser):

    methodList = []

    for classObject in parser.classes.values():

        data = []
        for method in classObject["methods"]["public"]:
            data.append((method["line_number"], method["rtnType"], method["name"], [param["name"] for param in method["parameters"]]))
        for method in classObject["methods"]["private"]:
            data.append((method["line_number"], method["rtnType"], method["name"], [param["name"] for param in method["parameters"]]))
        methodList.append((classObject["line_number"], classObject["name"], data))
    return methodList

def parseClasses(parser):

    classes = []

    for classObject in parser.classes.values():

        classes.append((classObject["line_number"], classObject["name"]))

    return classes


def getIndentation(line):

    indent = ""

    for c in line:
        if c.isalnum() == False and c != "~":
            indent += c
        else:
            return indent

    return ""

def addNamespaces(documentation, namespaces, content):
    pass

def addMethods(documentation, classes, content):

    for cl in classes:
        for method in cl[2]:

            ## Getting the indentation of the current method
            indent = str(getIndentation(content[method[0] - 1]))

            ## Adding the header
            documentation.append([method[0], indent + formats["k_header"] + "\n"])

            ## Adding fields
            documentation[-1][1] += indent + formats["k_brief"] + method[2] + "\n"

            if method[1] != "void":
                documentation[-1][1] += indent + formats["k_return"] + method[1] + "\n"

            if len(method[3]):
                for param in method[3]:
                    documentation[-1][1] += indent + formats["k_param"] + param + " : \n"

            ## Adding footer
            documentation[-1][1] += indent + formats["k_footer"] + "\n"

    return documentation

def addHeader(documentation, filename):
    documentation.insert(0, [1, formats["h_start"] + "\n" + 
                                formats["h_middle"] + formats["h_file"] + " " + filename + "\n" +
                                formats["h_middle"] + formats["h_author"] + " " + getpass.getuser() + " on the " + str(date.today()) + "\n" +
                                formats["h_middle"] + formats["h_date"] + " " + str(date.today()) + "\n" +
                                formats["h_middle"] + "\n" +
                                formats["h_middle"] + " project: " + formats["p_name"] + "\n" +
                                formats["h_middle"] + "\n" +
                                formats["h_end"] + "\n"
                                ])

    return documentation

def main():

    if len(sys.argv) != 2:
        exit(1)

    getConfig()
    openFileToParse(sys.argv[1])

if __name__ == "__main__":
    main()
