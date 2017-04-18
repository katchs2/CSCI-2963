"""
Words/Ladder Graph
------------------
Generate  an undirected graph over the 5757 5-letter words in the
datafile words_dat.txt.gz.  Two words are connected by an edge
if they differ in one letter, resulting in 14,135 edges. This example
is described in Section 1.1 in Knuth's book [1]_,[2]_.
References
----------
.. [1] Donald E. Knuth,
   "The Stanford GraphBase: A Platform for Combinatorial Computing",
   ACM Press, New York, 1993.
.. [2] http://www-cs-faculty.stanford.edu/~knuth/sgb.html
"""
# Authors: Aric Hagberg (hagberg@lanl.gov),
#          Brendt Wohlberg,
#          hughdbrown@yahoo.com

#    Copyright (C) 2004-2016 by
#    Aric Hagberg <hagberg@lanl.gov>
#    Dan Schult <dschult@colgate.edu>
#    Pieter Swart <swart@lanl.gov>
#    All rights reserved.
#    BSD license.

#    Modifications from the original implementation done by Samuel Deslandes
import matplotlib
import networkx as nx

#-------------------------------------------------------------------
#   The Words/Ladder graph of Section 1.1
#-------------------------------------------------------------------
def generate_graph(words,alt):
    from string import ascii_lowercase as lowercase
    from itertools import permutations
    
    G = nx.Graph(name="words")
    lookup = dict((c,lowercase.index(c)) for c in lowercase)
    if alt:
        def scramble(word):
            perms = [''.join(p) for p in permutations(word)]
            return set(perms)
        def edit_distance_one(word):
            for i in range(len(word)):
                left, c, right = word[0:i], word[i], word[i+1:]
                j = lookup[c] # lowercase.index(c)
                for cc in lowercase[j+1:]:
                    for i in scramble(left + cc + right):
                        yield i
    else:
        def edit_distance_one(word):
            for i in range(len(word)):
                left, c, right = word[0:i], word[i], word[i+1:]
                j = lookup[c] # lowercase.index(c)
                for cc in lowercase[j+1:]:
                    yield left + cc + right
    candgen = ((word, cand) for word in sorted(words)
               for cand in edit_distance_one(word) if cand in words)
    G.add_nodes_from(words)
    for word, cand in candgen:
        G.add_edge(word, cand)
    return G

def words_graph(word_len,alt):
    import gzip
    fh=gzip.open('words_dat.txt.gz','r') 
    words=set()
    for line in fh.readlines():
        line = line.decode()
        if line.startswith('*'):
            continue
        w=str(line[0:word_len])
        words.add(w)
    fh.close()    
    return generate_graph(words,alt)


## my code
def solve(words, alt=False):
    G=words_graph(len(words[0][0]),alt)
    for (source,target) in words:
        print("Shortest path between %s and %s is"%(source,target))
        try:
            sp=nx.shortest_path(G, source, target)
            for n in sp:
                print(n)
        except nx.NetworkXNoPath:
            print("None")
            
## words with 5 letters
words5 = [('shape','sharp'),
          #('nodes','graph'),
          #('moron','smart'),
          #('pound','marks')
          ]



print("5 letter words")
solve(words5)

print("\nVariation")
solve(words5[:1],True)