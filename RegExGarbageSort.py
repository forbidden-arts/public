# Python Challenge

# Thought process: I'm going to directly request that gawd-awful source code
# so I don't have to load it into another file of some sort and accidentally
# change something.

# After looking at the source, most of the garbage are symbols, and doing a
# by-hand search reveals the letter 'a' exists once in the garbage pile.
# going to RegEx filter for letters.

import urllib.request
import re

garbage = urllib.request.urlopen("http://www.pythonchallenge.com/pc/def/ocr.html").read().decode('utf8')
# that ".decode" took me forever to figure out. should have just dumped all
# this into a file.

# strip out all the special / escape characters
g_sort = re.findall("<!--(.*?)-->", garbage, re.DOTALL)[-1]
#print(g_sort)

# find actual letters
print("".join(re.findall("[A-Za-z]", g_sort)))