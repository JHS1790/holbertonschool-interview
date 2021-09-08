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
            keyword_dict[word.lower()] = 0
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
        lower_word_list = []
        for word in word_list:
            lower_word_list.append(word.lower())
        for keyword in keyword_dict:
            keyword_dict[keyword] = (
                keyword_dict[keyword] * lower_word_list.count(keyword)
                )
        sorted_keys = sorted(
            keyword_dict.items(), key=lambda x: x[1], reverse=True
            )
        for keyword in sorted_keys:
            if keyword[1] is not 0:
                print("{}: {}".format(keyword[0], keyword[1]))
