#!/usr/bin/python3
'Log Parsing'

import sys

def print_info():

    print('File size: {:d}'.format(total_size))
    for i in status_list:
        if i in final_list:
            status_count = final_list.count(i)
            print("{}: {:d}".format(i, status_count))


status_list = [200, 301, 400, 401, 403, 404, 405, 500]

try:
    total_size = 0
    final_list = []
    for index, line in enumerate(sys.stdin, 1):
        if line:
            line_split = line.split()
            if len(line_split) > 2:
                if line_split[-1].isnumeric() and line_split[-2].isnumeric():
                    size = line_split[-1]
                    status = line_split[-2]
                    total_size += int(size)
            if len(status) > 0 and int(status) in status_list:
                final_list.append(int(status))
        if index % 10 == 0:
            print('File size: {:d}'.format(total_size))
            for i in status_list:
                if i in final_list:
                    status_count = final_list.count(i)
                    print("{}: {:d}".format(i, status_count))
except Exception:
    pass

finally:
    print_info()
