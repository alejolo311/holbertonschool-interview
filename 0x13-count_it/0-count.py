#!/usr/bin/python3
"""
query the reddit API and
get all the hot articles
"""

import requests


def getA(sub, w, wd, wd_r, a="",):
    """ Get all the articles """
    url = f"https://www.reddit.com/r/{sub}/hot.json?limit=100&after={a}"
    response = requests.get(url, allow_redirects=False,
                            headers={'User-agent': 'Holberton'}
                            )
    if response.status_code != 200:
        return None
    articles = response.json()["data"]["children"]
    for article in articles:
        titles = article["data"]["title"].lower().split(" ")
        for title in titles:
            if title in wd:
                wd[title] += 1
    if response.json()["data"]["after"] is None:
        sw = sorted(wd.items(), key=lambda t: t[::-1])
        sw_desc = sorted(sw, key=lambda tup: tup[1], reverse=True)
        for w in sw_desc:
            if w[1] > 0:
                print("{}: {}".format(w[0], w[1] * wd_r[w[0]]))
        return
    return getA(sub, w, wd, wd_r, response.json()["data"]["after"])


def count_words(subreddit, word_list):
    """ Count words """
    w_d = {}
    w_d_r = {}
    word_list = [word.lower() for word in word_list]
    for w in word_list:
        if w not in w_d:
            w_d_r[w] = 1
            w_d[w] = 0
        else:
            w_d_r[w] += 1
    getA(subreddit, word_list, w_d, w_d_r)
