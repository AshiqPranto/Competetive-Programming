# **Hello...!!** :relaxed:
In this repository i store all of my important implementation about programming...<br/>
I collect some important **algorithms**,**data structure**,**my cp templates** and **cp resources**...

# **Data Stracture**

**1. Sparse Table**
   Sparse Table is a data structure, that allows answering range queries. It can answer most range queries in O(logn), but its true power is answering range minimum       queries (or equivalent range maximum queries). For those queries it can compute the answer in O(1) time.

The only drawback of this data structure is, that it can only be used on immutable arrays. This means, that the array cannot be changed between two queries. If any element in the array changes, the complete data structure has to be recomputed.
Space Complexity: O(NlogN)
Time Complexity: O(NlogN) for building the sparse table and O(1) to make a query

