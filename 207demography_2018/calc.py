#!/usr/bin/env python3

from math import *
from statistics import *

def sum_sq(data):

    res = 0

    for i in data:
        res += i ** 2
    return res

def sum_mul(data, date):

    res = 0
    i = 0

    while i < len(data):
        res += data[i] * date[i]
        i += 1
    return res

def a_coeff(data, dates):

    N = len(data)
    dates = dates[len(dates) - len(data):]

    calc = (sum(data) * sum_sq(dates) - sum(dates) * sum_mul(data, dates)) / (N * sum_sq(dates) - (sum(dates) ** 2))
    return calc

def a_coeff_2(data, dates):

    N = len(data)
    dates = dates[len(dates) - len(data):]

    calc = (sum(dates) * sum_sq(data) - sum(data) * sum_mul(data, dates)) / (N * sum_sq(data) - (sum(data) ** 2))
    return calc

def b_coeff(data, dates):

    N = len(data)
    dates = dates[len(dates) - len(data):]

    calc = (N * sum_mul(data, dates) - sum(dates) * sum(data)) / (N * sum_sq(dates) - (sum(dates) ** 2))
    return calc

def b_coeff_2(data, dates):

    N = len(data)
    dates = dates[len(dates) - len(data):]

    calc = (N * sum_mul(data, dates) - sum(dates) * sum(data)) / (N * sum_sq(data) - (sum(data) ** 2))
    return calc

def sum_funx(data, dates):

    res = 0
    idx = 0
    a = a_coeff(data, dates)
    b = b_coeff(data, dates)
    dates = dates[len(dates) - len(data):]

    for i in data:
        res += (i - (b * dates[idx] + a)) ** 2
        idx += 1
    return res

def deviationx(data, dates):

    N = len(data)

    return sqrt((1 / N) * (sum_funx(data, dates)))

def sum_funy(data, dates):

    res = 0
    idx = 0
    a = a_coeff_2(data, dates)
    b = b_coeff_2(data, dates)
    dates = dates[len(dates) - len(data):]

    for i in data:
        res += (i - ((dates[idx] - a) / b)) ** 2
        idx += 1
    return res

def deviationy(data, dates):

    N = len(data)

    return sqrt((1 / N) * (sum_funy(data, dates)))


def sum_correl(data, m_data):

    return sum((i - m_data) ** 2 for i in data)

def sum_final(data, dates, m_data, m_dates):

    return sum(((i - m_data) * (j - m_dates) for i, j in zip(data, dates)))

def correlation(data, dates):
    N = len(data)
    m_dates = mean(dates)
    m_data = mean(data)

    sum_data = sqrt((1 / N) * (sum_correl(data, m_data)))
    sum_dates = sqrt((1 / N) * (sum_correl(dates, m_dates)))
    sum_both = (1 / N) * sum_final(data, dates, m_data, m_dates)

    return sum_both / (sum_dates * sum_data)
