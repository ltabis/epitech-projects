#!/usr/bin/env python3

class Country:

    # init object
    def __init__(self, data):

        self.data = []
        self.country_name = ""
        self.country_code = ""

        data = self.parse_data(data)

    # parse data to fill object
    def parse_data(self, data):
        self.country_name = data[0]
        self.country_code = data[1]

        data = data[2:]
        for i in data:
            self.data.append(int(i.replace('\n', '')))
