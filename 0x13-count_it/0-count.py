#!/usr/bin/python3
""" recursive function that queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords"""
import requests
import sys

keyword_dict = {}
headers = {'User-Agent': 'holberton_1790'}


def count_words(subreddit, word_list, next_post=None):
    if not keyword_dict:
        for word in word_list:
            keyword_dict[word] = 0
    hot = requests.get(
        "https://www.reddit.com/r/{}/hot.json?after={}"
        .format(subreddit, next_post),
        headers=headers)
    if hot.status_code == 404:
        return
    hot_json = hot.json()
    hot_data = hot_json['data']
    next_post = hot_data['after']
    hot_posts = hot_data['children']
    for post in hot_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_keywords = post_title.split()
        for keyword in title_keywords:
            for key in keyword_dict:
                if keyword.lower() == key.lower():
                    keyword_dict[key] += 1
    if next_post:
        count_words(subreddit, word_list, next_post)
    else:
        combine_duplicate_keywords()
        for keyword in sorted(keyword_dict):
            if keyword_dict[keyword] is not 0:
                print("{}: {}".format(keyword, keyword_dict[keyword]))


def combine_duplicate_keywords():
    dupe_keys = {}
    for keyword_1 in keyword_dict:
        for keyword_2 in keyword_dict:
            if keyword_1.lower() == keyword_2 and keyword_1 != keyword_2:
                dupe_keys[keyword_1] = keyword_dict[keyword_1]
    for dupe_keyword in dupe_keys:
        del keyword_dict[dupe_keyword]
        keyword_dict[dupe_keyword.lower()] += dupe_keys[dupe_keyword]
