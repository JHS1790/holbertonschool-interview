#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""
import sys

status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}
sum_file_size = 0


def print_stats():
    """Print'em boys"""
    global sum_file_size

    print('File size: {}'.format(sum_file_size))
    status_codes_sorted = sorted(status_codes.keys())
    for code in status_codes_sorted:
        if status_codes[code] > 0:
            print('{}: {}'.format(code, status_codes[code]))


if __name__ == "__main__":
    count = 0
    try:
        for line in sys.stdin:
            try:
                point = line.split(' ')
                if point[-2] in status_codes:
                    status_codes[point[-2]] += 1
                sum_file_size += int(point[-1])
            except:
                pass
            count += 1
            if count == 10:
                print_stats()
                count = 0
    except KeyboardInterrupt:
        print_stats()
        raise
    else:
        print_stats()
