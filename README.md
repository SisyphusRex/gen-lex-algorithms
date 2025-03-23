# gen-lex-permutations

A permutation of the set {1,2,...,𝑛} is an ordered 𝑛-tuple in which each number in {1,2,...,𝑛} appears exactly once.  For
example (2,5,1,4,3) is a permutation of the set {1,2,3,4,5}.

Any two disctinct permutations over {1,2,...,𝑛-1,𝑛} can be ordered lexicographically.  Generating permutations in 
lexicographic order ensures that each permutation is generated exactly once.  The first permutation in lexicographic order is
(1,2,...,𝑛-1,𝑛), and the last permutation is (𝑛,𝑛-1,...,2,1).  The permutations of the set {1,2,3} are listed below
in lexicographic order:
  (1,2,3) < (1,3,2) < (2,1,3) < (2,3,1) < (3,1,2) < (3,2,1)

The algorithm GenLexPermutations(𝑛) takes as input a natural number 𝑛 and outputs all the permutations of
{1,2,...,𝑛} in lexicographic order.  GenLexPermutations starts with the first permutation in lexicographic order and
keeps generating the next permutation until the last permutation is reached.  The algorithm NextPerm(𝑃)
takes as input a permutation 𝑃 and returns the smallest permutation that is larger than 𝑃.

Pseudocode:  

GenLexPermutations(𝑛)  
  * Initialize 𝑃 = (1,2,...,𝑛-1,𝑛)  
  * Output 𝑃  
  * While 𝑃 ≠ (𝑛,𝑛-1,...,2,1)  
    * 𝑃 = NextPerm(𝑃)  
    * Output 𝑃  

NextPerm$`(𝑝_{1},𝑝_{2},...,𝑝_{𝑛})`$
  Let 𝑘 be the largest index such that 𝑝𝑘
