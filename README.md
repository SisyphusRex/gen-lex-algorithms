# gen-lex-algorithms

General Lexicographic Algorithms

### GenLexPermutations
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
  * Let 𝑘 be the largest index such that $`𝑝_{𝑘} \lt 𝑝_{𝑘+1}`$
      * If no such 𝑘 exists, then $`(𝑝_{1},𝑝_{2},...,𝑝_{𝑛})`$ is the last permutation
  * Let $`𝑝_{𝑗}`$ be the smallest element such that 𝑗>𝑘 and $`𝑝_{𝑗}\gt 𝑝_{𝑘}`$
  * Swap $`𝑝_{𝑗}`$ and $`𝑝_{𝑘}`$
  * Reverse the order of $`𝑝_{𝑘+1},...,𝑝_{𝑛}`$
  * Return $`(𝑝_{1},𝑝_{2},...,𝑝_{𝑛})`$

### GenLexSubsets  
The next algorithm takes as input two natural numbers, 𝑟 and 𝑛, such that $`𝑟\le 𝑛`$, and outputs all the 𝑟-subsets of the set
{1,2,...,𝑛-1,𝑛}.  The elements in a subset are always listed in increasing order.  The subsets are generated according to
lexicographic order to ensure that each subset is generated exactly once.  The first 𝑟-subset of {1,2,...,𝑛-1,𝑛} in 
lexicographic order is {1,2,...,𝑟-1,𝑟}, and the last 𝑟-subset is {𝑛-𝑟+1,...,𝑛-1,𝑛}.  The 3-subsets of the set
{1,2,3,4,5} are listed below in lexicographic order:  
  {1,2,3} < {1,2,4} < {1,2,5} < {1,3,4} < {1,3,5} < {1,4,5} < {2,3,4} < {2,3,5} < {2,4,5} < {3,4,5}

The algorithm GenLexSubsets(𝑟,𝑛) starts with the first 𝑟-subset in lexicographic order and keeps generating the next 𝑟-subset until the last 𝑟-subset is reached.  The algorithm NextSubset(𝑛,𝑆) takes as input an 𝑟-subset 𝑆 and natural
number 𝑛 and returns the small 𝑟-subset of {1,2,...,𝑛} that is larger than 𝑆.

Pseudocode:

GenLexSubsets(𝑟,𝑛)
  * Initialize 𝑆 = {1,2,...,𝑟-1,𝑟}
  * Output 𝑆
  * While 𝑆 ≠ {𝑛-𝑟+1,...,𝑛-1,𝑛}
      * 𝑆 = NextSubset(𝑛,𝑆)
      * Output 𝑆

NextSubset$`(𝑛,\{𝑠_{1},𝑠_{2},...,𝑠_{𝑟}\})`$
  * Let 𝑘 be the largest index such that $`𝑠_{𝑘}\lt 𝑛-𝑟+𝑘`$
      * If no 𝑘 exists then $`\{𝑠_{1},𝑠_{2},...,s_{𝑟}\}`$ is the last 𝑟-subset of {1,2,...,𝑛}.
  * $`𝑠_{𝑘}:=𝑠_{𝑘}+1`$
  * For 𝑗=𝑘+1 to 𝑟
      * $`𝑠_{𝑗}:=𝑠_{𝑗-1}+1`$
  * Return($`\{𝑠_{1},𝑠_{2},...,𝑠_{𝑟}\}`$)

